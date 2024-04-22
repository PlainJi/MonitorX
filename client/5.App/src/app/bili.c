#include "bili.h"

#include <pthread.h>
#include "curldef.h"
#include "json_parser.h"
#include "config.h"
#include "util.h"

char bili_url_buf[128];
CURLcode bili_res;
CURL *bili_curl = NULL;
struct MemoryStruct bili_chunk;
struct curl_slist *bili_header_chunk = NULL;

bool bili_updating = false;
static bili_t bili_info;
time_t bili_last_update_stat = 0;

int bili_curl_req(const char *url) {
    //LOG_INFO("curl %s\n", url);
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
        LOG_ERR("[BILI] perform curl error:%d.\n", bili_res);
        return 1;
    }

    //LOG_INFO("%lu %s\n", (long unsigned int)bili_chunk.size, bili_chunk.memory);
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

int bili_req_card(const char *userid, bili_t *info) {
    int res = 0;
    snprintf(bili_url_buf, sizeof(bili_url_buf), "%s%s", URL_BILI_CARD, userid);
    do {
        if (bili_curl_req(bili_url_buf)) { res = 1; break; }
        if (parse_bili_card(bili_chunk.memory, info)) {res = 2; break; }
    }while(0);

    if(res) {
        LOG_ERR("bili_req_card faile, res = %d\n", res);
    }

    return res;
}

int bili_save_face(const void *buf, size_t size, const char *path) {
    lv_fs_file_t f;
    lv_fs_res_t res;
    int ret = 0;

    do {
        // open
        res = lv_fs_open(&f, path, LV_FS_MODE_WR);
        if(res != LV_FS_RES_OK) {
            ret = 1; break;
        }
        // write
        uint32_t bytes_writen = 0;
        res = lv_fs_write(&f, buf, (uint32_t)size, &bytes_writen);
        if(res != LV_FS_RES_OK || bytes_writen != size) {
            ret = 2; break;
        }
        // close
        lv_fs_close(&f);
    } while(0);

    return ret;
}

int bili_req_face(const char *face_url) {
    int res = 0;
    do {
        if (bili_curl_req(face_url)) {
            res = 1; break;
        }
        LOG_INFO("face size: %d\n", bili_chunk.size);
        if (bili_save_face(bili_chunk.memory, bili_chunk.size, REAL_FACE_PATH)) {
            res = 2; break;
        }
    }while(0);

    if(res) {
        LOG_ERR("bili_req_face faile, res = %d\n", res);
    }

    return res;
}

int bili_check_userid(const char *userid) {
    bili_relation_t tmp;
    LOG_INFO("bili checking userid: %s\n", userid);
    return bili_req_relation(userid, &tmp);
}

void bili_set_userid(const char *userid) {
    LOG_INFO("bili set userid: %s\n", userid);
    config_set_bili_userid(userid);
    LOG_INFO("config_set_bili_userid, userid=%s\n", userid);

    memset(&bili_info, 0, sizeof(bili_info));
    strncpy(bili_info.userid, userid, sizeof(bili_info.userid)-1);
    LOG_INFO("strncpy, userid=%s\n", userid);

    // lvgl is not thread-safe by default.
    // But it's valid in lv_event and lv_timer.
    // Beshure these funcs can only be called in kb_event_cb.
    ui_bili_reset_info();
    LOG_INFO("bili_set_userid, userid=%s\n", userid);
    ui_bili_set_basic(userid);
    ui_bili_update_basic();
    bili_last_update_stat = 0;
}

int bili_init(void) {
    bili_last_update_stat = 0;
    memset(&bili_chunk, 0, sizeof(bili_chunk));
    memset(&bili_info, 0, sizeof(bili_info));
    bili_header_chunk = curl_slist_append(bili_header_chunk, \
        "user-agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/106.0.0.0 Safari/537.36");
    curl_global_init(CURL_GLOBAL_ALL);
    bili_curl = curl_easy_init();
    //curl_easy_setopt(bili_curl, CURLOPT_VERBOSE, 1);

    bili_cb.bili_check_userid_cb = bili_check_userid;
    bili_cb.bili_set_userid_cb = bili_set_userid;
    bili_cb.bili_start_update_cb = bili_start_update;
    bili_cb.bili_stop_update_cb = bili_stop_update;

    // init ui, show userid.
    strncpy(bili_info.userid, conf.bili_userid, sizeof(bili_info.userid)-1);
    pthread_mutex_lock(&lvgl_mutex);
    ui_bili_reset_info();
    ui_bili_set_basic(bili_info.userid);
    ui_bili_update_basic();
    pthread_mutex_unlock(&lvgl_mutex);

    return 0;
}

int bili_uninit(void) {
    if (bili_header_chunk) curl_slist_free_all(bili_header_chunk);
    if (bili_chunk.memory) free(bili_chunk.memory);
	if(bili_curl) curl_easy_cleanup(bili_curl);
    curl_global_cleanup();

    return 0;
}

void bili_stop_update(void) {
    LOG_INFO("bili stop update!\n");
    bili_last_update_stat = time(NULL);
    bili_updating = false;
}

void bili_start_update(void) {
    LOG_INFO("bili start update!\n");
    bili_last_update_stat = 0;
}

void bili_update(void) {
    int ret = 0;

    pthread_mutex_lock(&lvgl_mutex);
    ui_bili_update_status(0);
    pthread_mutex_unlock(&lvgl_mutex);

    memset(&bili_info, 0, sizeof(bili_info));
    do {
        // step 1, get card info
        if (bili_req_card(conf.bili_userid, &bili_info)) {
            // failed
            pthread_mutex_lock(&lvgl_mutex);
            ui_bili_update_status(100);
            pthread_mutex_unlock(&lvgl_mutex);
            return;
        }
        pthread_mutex_lock(&lvgl_mutex);
        ui_bili_update_status(50);
        pthread_mutex_unlock(&lvgl_mutex);

        // step 2, get face image
        if (bili_req_face(bili_info.face_url)) {
            // failed
            strncpy(bili_info.face_path, UNKNOWN_FACE_PATH, sizeof(bili_info.face_path)-1);
            pthread_mutex_lock(&lvgl_mutex);
            ui_bili_update_status(100);
            pthread_mutex_unlock(&lvgl_mutex);
            return;
        }
        strncpy(bili_info.face_path, REAL_FACE_PATH, sizeof(bili_info.face_path)-1);
        
        // step 3, update
        LOG_INFO("UserID: %s UserName: %s\n", bili_info.userid, bili_info.username);
        LOG_INFO("Following: %d Follower: %d\n", bili_info.following, bili_info.follower);
        LOG_INFO("Video: %d Like: %d\n", bili_info.video, bili_info.like);
        LOG_INFO("Title: %s\n", bili_info.title);
        LOG_INFO("Sign: %s\n", bili_info.sign);
        LOG_INFO("Face path: %s\n", bili_info.face_path);

        pthread_mutex_lock(&lvgl_mutex);
        ui_bili_set_info(&bili_info);
        ui_bili_update_info();
        ui_bili_update_status(100);
        pthread_mutex_unlock(&lvgl_mutex);
    } while(0);
}

void bili_thread(void) {
    while(bili_init()) {
        bili_uninit();
        sleep(1);
    }

    do {
        if (time(NULL) - bili_last_update_stat > conf.bili_update_folw_itv_m*60) {
            bili_last_update_stat = time(NULL);
            bili_update();
        }
        sleep(1);        
    }while(1);

    bili_uninit();
    LOG_INFO("bili_thread exit!\n");
}


/* deprecated
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

int bili_req_video_list(void) {
    int res = 0, tmp = 0;
    int pn = 1, ps = 50;

    do {
        time_t t = time(NULL);
        printf("[%s] [BILI] getting video list of page %d.\n", getasctime(&t), pn);
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
        usleep((rand()%3000+500) * 1000);
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
    memset(&bili_info, 0, sizeof(bili_info));
    strncpy(bili_info.userid, conf.bili_userid, sizeof(bili_info.userid));
    strncpy(bili_info.username, bili_video_list.author, sizeof(bili_info.username));
    bili_info.following = bili_relation.following;
    bili_info.follower = bili_relation.follower;
    bili_info.video = bili_video_list.count;
    for (int i=0; i<bili_video_list.count; i++) {
        bili_video_info_t *tmp = (bili_video_info_t*)(bili_video_infos + sizeof(bili_video_info_t)*i);
        bili_info.view += tmp->view;
        bili_info.danmu += tmp->danmu;
        bili_info.reply += tmp->reply;
        bili_info.like += tmp->like;
        bili_info.coin += tmp->coin;
        bili_info.favorite += tmp->favorite;
        bili_info.share += tmp->share;
    }
    time_t t = time(NULL);
    printf("[%s] [BILI] get summary username: %s follower: %d likes: %d coins: %d favorite: %d\n", \
        getasctime(&t), bili_info.username, bili_info.follower, \
        bili_info.like, bili_info.coin, bili_info.favorite);

    return 0;
}

void update_relation(void) {
    // update relation, like followers
    if(!bili_req_relation(conf.bili_userid, &bili_relation)) {
        // ui_update_bili_relation(&bili_relation);  // TODO PLAIN
        printf("[%s] [BILI] update_relation: %d\n", getasctime(&bili_last_update_relation), bili_relation.follower);
    }
}

void update_detail(void) {
    int ret = 0;
    int cur_video_cnt = 0;
    int bili_updating_percent = 0;

    if (bili_req_video_list()) {
        // req video list failed
        if (bili_video_list.video_list_buf) free(bili_video_list.video_list_buf);
        memset(&bili_video_list, 0, sizeof(bili_video_list));
    } else {
        // req video list succeed
        if (bili_video_list.count) {
            // update username
            // ui_update_bili_username(bili_video_list.author); // TODO PLAIN
            printf("[%s] [BILI] update username %s.\n", getasctime(&bili_last_update_stat), bili_video_list.author);
            // alloc buffer for each video info    
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
        // get detail of each video
        if (cur_video_cnt<bili_video_list.count) {
            if (!bili_req_video_detail(cur_video_cnt)) {
                cur_video_cnt++;
                bili_updating_percent = cur_video_cnt*100 / bili_video_list.count;
            } else {
                bili_updating = false;
                printf("[%s] [BILI] update_detail failed!!!!\n", getasctime(&bili_last_update_stat));
            }
        } else {
            // get summary and update
            bili_get_summary();
            // ui_update_bili(&bili_info);  // TODO PLAIN

            // ensure ui percent is 100
            bili_updating_percent = 100;
            // ui_update_bili_status_mutex(bili_updating_percent);  // TODO PLAIN
            bili_updating = false;
            printf("[%s] [BILI] update_detail complete.\n", getasctime(&bili_last_update_stat));
        }
        usleep((rand()%1000+500) * 1000);
    }
}
*/
