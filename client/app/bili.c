#include "bili.h"
#include <pthread.h>
#include "curldef.h"
#include "curl/curl.h"
#include "curl/easy.h"
#include "json_parser.h"
#include "ui_controller.h"
#include "config.h"

char bili_url_buf[128];
CURLcode bili_res;
CURL *bili_curl = NULL;
struct MemoryStruct bili_chunk;
struct curl_slist *bili_header_chunk = NULL;

bool bili_updating = false;
bili_relation_t bili_relation;
bili_video_list_t bili_video_list;
char *bili_video_infos = NULL;
bili_t bili_info_all;

time_t bili_last_update_relation = 0;
time_t bili_last_update_stat = 0;
extern pthread_mutex_t lvgl_mutex;

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

int bili_req_relation(const char *userid, bili_relation_t *info) {
    int res = 0;
    snprintf(bili_url_buf, sizeof(bili_url_buf), "%s%s", URL_BILI_RELATION, userid);
    do {
        if (bili_curl_req(bili_url_buf)) { res = 1; break; }
        if (parse_bili_relation(bili_chunk.memory, info)) {res = 2; break; }
    }while(0);

    if(res) {
        printf("bili_req_relation faile, res = %d\n", res);
    }

    return res;
}

int bili_check_userid(const char *userid) {
    bili_relation_t tmp;
    printf("[BILI CHECK]\n");
    return bili_req_relation(userid, &tmp);
}

int bili_req_video_list(void) {
    int res = 0, tmp = 0;
    int pn = 1, ps = 20;

    do {
        snprintf(bili_url_buf, sizeof(bili_url_buf), "%s%s&pn=%d&ps=%d", \
            URL_BILI_VIDEO_LIST, conf.bili_userid, pn, ps);
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
    memset(&bili_info_all, 0, sizeof(bili_info_all));
    strncpy(bili_info_all.userid, conf.bili_userid, sizeof(bili_info_all.userid));
    strncpy(bili_info_all.username, bili_video_list.author, sizeof(bili_info_all.username));
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
    printf("bili username: %s follower: %d likes: %d coins: %d favorite: %d\n", bili_info_all.username, \
        bili_info_all.follower, bili_info_all.like, bili_info_all.coin, bili_info_all.favorite);

    return 0;
}

void bili_reset(void) {
    bili_last_update_relation = 0;
    bili_last_update_stat = 0;
    memset(bili_video_list.author, 0, sizeof(bili_video_list.author));
}

int bili_init(void) {
    bili_reset();
    memset(&bili_chunk, 0, sizeof(bili_chunk));
    memset(&bili_video_list, 0, sizeof(bili_video_list));
    memset(&bili_relation, 0, sizeof(bili_relation));
    memset(&bili_info_all, 0, sizeof(bili_info_all));
    bili_header_chunk = curl_slist_append(bili_header_chunk, "User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/106.0.0.0 Safari/537.36");
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

void bili_stop_update(void) {
    printf("bili stop update!\n");
    bili_last_update_relation = time(NULL);
    bili_last_update_stat = time(NULL);
    bili_updating = false;
}

void update_relation(void) {
    // update relation, like followers
    if(!bili_req_relation(conf.bili_userid, &bili_relation)) {
        pthread_mutex_lock(&lvgl_mutex);
        ui_update_bili_relation(&bili_relation);
        pthread_mutex_unlock(&lvgl_mutex);
        bili_last_update_relation = time(NULL);
        printf("update_bili_relation: %s\n", asctime(localtime(&bili_last_update_relation)));
    }
}

void update_detail(void) {
    int ret = 0;
    int cur_video_cnt = 0;
    int bili_updating_percent = 0;

    if (bili_req_video_list()) {
        if (bili_chunk.memory) free(bili_chunk.memory);
        if (bili_video_list.video_list_buf) free(bili_video_list.video_list_buf);
        memset(&bili_video_list, 0, sizeof(bili_video_list));
    } else {
        if (bili_video_list.count) {
            bili_video_infos = realloc(bili_video_infos, bili_video_list.count * sizeof(bili_video_info_t));
            if (!bili_video_infos) {
                printf("malloc bili_video_infos failed!\n");
                return;
            }
        }
    }

    time_t tmp = 0;
    bili_updating = true;

    while (bili_updating) {
        ui_update_bili_status(bili_updating_percent);
        // get detail of each video
        if (cur_video_cnt<bili_video_list.count) {
            if (!bili_req_video_detail(cur_video_cnt)) {
                cur_video_cnt++;
                bili_updating_percent = cur_video_cnt*100 / bili_video_list.count;
            } else {
                bili_updating = false;
            }
        } else {
            bili_updating_percent = 100;
            // get summary and update
            bili_get_summary();
            pthread_mutex_lock(&lvgl_mutex);
            ui_update_bili(&bili_info_all);
            pthread_mutex_unlock(&lvgl_mutex);
            ui_update_bili_status(bili_updating_percent);
            bili_last_update_stat = time(NULL);
            bili_updating = false;
            printf("update_bili_status: %s\n", asctime(localtime(&bili_last_update_stat)));
        }
        usleep(500*1000);
    }
}

void bili_thread(void) {
    while(bili_init()) {
        bili_uninit();        
        sleep(1);
    }

    pthread_mutex_lock(&lvgl_mutex);
    ui_bili_init();
    pthread_mutex_unlock(&lvgl_mutex);

    do {
        if (time(NULL) - bili_last_update_relation > conf.bili_update_folw_itv_m*60) {
            update_relation();
        }
        if (time(NULL) - bili_last_update_stat > conf.bili_update_stat_itv_h*3600) {
            update_detail();
        }
        sleep(1);
    }while(1);

    bili_uninit();
    printf("bili_thread exit!\n");
}