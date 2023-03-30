#include "bili.h"
#include <pthread.h>
#include "curldef.h"
#include "curl/curl.h"
#include "curl/easy.h"
#include "json_parser.h"
#include "ui_controller.h"

char bili_mid[16] = {0};
char bili_url_buf[128];
CURLcode bili_res;
CURL *bili_curl = NULL;
struct MemoryStruct bili_chunk;
struct curl_slist *bili_header_chunk = NULL;

bool bili_updating = true;
char bili_updating_percent = 0;

bool bili_relation_refreshed = false;
bili_relation_t bili_relation;

bool bili_video_list_refreshed = false;
bili_video_list_t bili_video_list;

bool bili_video_detail_refreshed = false;
char *bili_video_infos = NULL;
bili_t bili_info_all;

int bili_curl_req(char *url) {
    printf("curl %s\n", url);
    bili_chunk.size = 0;
    
    curl_easy_setopt(bili_curl, CURLOPT_URL, url);
    curl_easy_setopt(bili_curl, CURLOPT_HTTPHEADER, bili_header_chunk);
    curl_easy_setopt(bili_curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(bili_curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(bili_curl, CURLOPT_ACCEPT_ENCODING, "gzip");
    curl_easy_setopt(bili_curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(bili_curl, CURLOPT_WRITEDATA, (void*)&bili_chunk);
    bili_res = curl_easy_perform(bili_curl);
    if (bili_res != CURLE_OK) {
        printf("perform curl error:%d.\n", bili_res);
        return 1;
    }

    //printf("%lu %s\n", (long unsigned int)bili_chunk.size, bili_chunk.memory);
    return 0;
}

int bili_req_relation(void) {
    int res = 0;
    snprintf(bili_url_buf, sizeof(bili_url_buf), "%s%s", URL_BILI_RELATION, BILI_MID_STR);
    do {
        if (bili_curl_req(bili_url_buf)) { res = 1; break; }
        if (parse_bili_relation(bili_chunk.memory, &bili_relation)) {res = 2; break; }
    }while(0);

    if(res) {
        printf("bili_req_relation faile, res = %d\n", res);
    }

    return res;
}

int bili_req_video_list(void) {
    int res = 0, tmp = 0;
    int pn = 1, ps = 20;

    do {
        snprintf(bili_url_buf, sizeof(bili_url_buf), "%s%s&pn=%d&ps=%d", \
            URL_BILI_VIDEO_LIST, BILI_MID_STR, pn, ps);
        if (bili_curl_req(bili_url_buf)) { res = 1; break; }
        if ((tmp=parse_bili_video_list(bili_chunk.memory, &bili_video_list))) { 
            printf("parse_bili_video_list error, ret = %d\n", tmp);
            if (tmp == 3) {sleep(5);}
            res = 2;
            break;
        }
        int left = bili_video_list.count - bili_video_list.pn * bili_video_list.ps;
        if (left > 0) pn++; else break;
        sleep(1);
    }while(1);

    return res;
}

int bili_req_video_detail(int cnt) {
    int res = 0, tmp = 0;
    int aid = *((int*)(bili_video_list.video_list_buf + cnt*sizeof(int)));
    snprintf(bili_url_buf, sizeof(bili_url_buf), "%s%d", \
            URL_BILI_VIDEO_INFO, aid);

    if (bili_curl_req(bili_url_buf)) { res = 1; }
    if ((tmp=parse_bili_video_detail(bili_chunk.memory, \
        (bili_video_info_t*)(bili_video_infos + cnt*sizeof(bili_video_info_t))))) {
        printf("parse_bili_video_detail error, ret = %d\n", tmp);
        res = 2;
    }

    return res;
}

int bili_get_summary(void) {
    strcat(bili_info_all.userid, BILI_MID_STR);
    strcat(bili_info_all.username, bili_video_list.author);
    bili_info_all.following = bili_relation.following;
    bili_info_all.follower = bili_relation.follower;
    bili_info_all.videos = bili_video_list.count;
    for (int i=0; i<bili_video_list.count; i++) {
        bili_video_info_t *tmp = (bili_video_info_t*)(bili_video_infos + sizeof(bili_video_info_t)*i);
        bili_info_all.view += tmp->view;
        bili_info_all.danmu += tmp->danmu;
        bili_info_all.reply += tmp->reply;
        bili_info_all.like += tmp->like;
        bili_info_all.coin += tmp->coin;
        bili_info_all.favorite += tmp->favorite;
        bili_info_all.share += tmp->share;
    }
    printf("username: %s follower: %d likes: %d coins: %d favorite: %d\n", bili_info_all.username, \
        bili_info_all.follower, bili_info_all.like, bili_info_all.coin, bili_info_all.favorite);

    return 0;
}

int bili_init(void) {
    snprintf(bili_mid, sizeof(bili_mid), "%s", BILI_MID_STR);
    
    memset(&bili_chunk, 0, sizeof(bili_chunk));
    bili_header_chunk = curl_slist_append(bili_header_chunk, "User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/106.0.0.0 Safari/537.36");
    memset(&bili_video_list, 0, sizeof(bili_video_list));
    memset(&bili_relation, 0, sizeof(bili_relation));
    memset(&bili_info_all, 0, sizeof(bili_info_all));
    curl_global_init(CURL_GLOBAL_ALL);
    bili_curl = curl_easy_init();
    //curl_easy_setopt(bili_curl, CURLOPT_VERBOSE, 1);

    return 0;
}

int bili_uninit(void) {
    if (bili_header_chunk) free(bili_header_chunk);
    if (bili_chunk.memory) free(bili_chunk.memory);
    if (bili_video_list.video_list_buf) free(bili_video_list.video_list_buf);
    if (bili_video_infos) free(bili_video_infos);
	if(bili_curl) curl_easy_cleanup(bili_curl);
    curl_global_cleanup();

    return 0;
}

extern pthread_mutex_t lvgl_mutex;

void bili_thread(void) {
    while(bili_init()) {
        bili_uninit();        
        sleep(1);
    }

    pthread_mutex_lock(&lvgl_mutex);
    ui_bili_init();
    pthread_mutex_unlock(&lvgl_mutex);

    int cur_video_cnt = 0;
    do {
        ui_update_bili_status(bili_updating_percent);
        if (bili_updating) {
            // update relation, like followers
            if (!bili_relation_refreshed) {
                if(!bili_req_relation()) {
                    // pthread_mutex_lock(&lvgl_mutex);
                    // ui_update_bili_relation(&bili_relation);
                    // pthread_mutex_unlock(&lvgl_mutex);
                    // bili_relation_refreshed = true;
                }
            }

            if (!bili_video_list_refreshed) {
                // update video list
                if (bili_req_video_list()) {
                    if (bili_chunk.memory) free(bili_chunk.memory);
                    if (bili_video_list.video_list_buf) free(bili_video_list.video_list_buf);
                    memset(&bili_video_list, 0, sizeof(bili_video_list));
                } else {
                    bili_video_infos = malloc(bili_video_list.count * sizeof(bili_video_info_t));
                    if (!bili_video_infos) {
                        printf("malloc bili_video_infos failed!\n");
                        break;
                    }
                    bili_video_list_refreshed = true;
                }
            } else {
                // get detail of each video
                if (!bili_video_detail_refreshed && cur_video_cnt<bili_video_list.count) {
                    if (!bili_req_video_detail(cur_video_cnt)) {
                        cur_video_cnt++;
                        bili_updating_percent = cur_video_cnt*100 / bili_video_list.count;
                    } else {

                    }
                } else {
                    bili_video_detail_refreshed = true;
                    bili_updating_percent = 100;
                    // get summary and update
                    bili_get_summary();
                    pthread_mutex_lock(&lvgl_mutex);
                    ui_update_bili(&bili_info_all);
                    ui_update_bili_relation(&bili_relation);
                    ui_update_bili_status(bili_updating_percent);
                    bili_relation_refreshed = true;
                    bili_updating = false;
                    pthread_mutex_unlock(&lvgl_mutex);
                }
            }
        }
        sleep(1);
    }while(1);

    bili_uninit();
    printf("bili_thread exit!\n");
}