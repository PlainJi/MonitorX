#include "git.h"
#include <time.h>
#include <pthread.h>
#include "curldef.h"
#include "curl/curl.h"
#include "curl/easy.h"
#include "json_parser.h"
#include "ui_controller.h"
#include "config.h"

git_t **git_info;
int end_year = 0, year_cnt = 0;
time_t git_last_update_time = 0;
bool git_updating = true;
char git_updating_percent = 0;
char url_buf[128];
CURLcode res;
CURL *curl = NULL;
struct MemoryStruct chunk;
extern pthread_mutex_t lvgl_mutex;

int git_curl_req(const char *username, int year, git_t *info) {
    if (username) {
        snprintf(url_buf, sizeof(url_buf), "%s/%s/%d.json", URL_GIT, username, year);
    } else {
        snprintf(url_buf, sizeof(url_buf), "%s/%s/%d.json", URL_GIT, conf.git_username, year);
    }
    printf("curl %s\n", url_buf);
    chunk.size = 0;
    curl_easy_setopt(curl, CURLOPT_URL, url_buf);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "gzip");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        printf("perform curl error:%d.\n", res);
        return 1;
    }

    //printf("%lu %s\n", (long unsigned int)chunk.size, chunk.memory);
    int parse_res = parse_git_info(chunk.memory, info);
    if (parse_res) {
        printf("parse_git_info res=%d\n", parse_res);
        return 2;
    }

    return 0;
}

int git_check_username(const char *username) {
    git_t tmp;
    memset(&tmp, 0, sizeof(tmp));
    printf("[GIT CHECK]\n");
    return git_curl_req(username, 2008, &tmp);
}

// lvgl is not thread-safe by default.
// But in event and timer it's valid.
// Beshre this func is only called in kb_event_cb.
void git_reset(void) {
    git_last_update_time = 0;
    ui_update_contribution_panel(NULL);
}

int git_init(void) {
    // get end year until timesynced
    while (end_year < START_YEAR) {
        time_t t = time(NULL);
	    struct tm *s_tm = localtime(&t);
	    end_year = s_tm->tm_year+1900;
        sleep(1);
    }
    year_cnt = end_year - START_YEAR + 1;
    printf("git years from %d to %d, total %d years!\n", START_YEAR, end_year, year_cnt);

    // malloc buffer for pointers to git_t
    git_info = malloc(sizeof(git_t*)*year_cnt);
    if (!git_info) {
        printf("git_init1 Out of memory!\n");
        return 1;
    }
    memset(git_info, 0, sizeof(git_info)*year_cnt);

    // malloc buffer for git_t of each year
    for (int i=0; i<year_cnt; i++) {
        git_info[i] = malloc(sizeof(git_t));
        if (!git_info) {
            printf("git_init2, out of memory!\n");
            return 2;
        }
        memset(git_info[i], 0, sizeof(git_t));
    }

    memset(&chunk, 0, sizeof(chunk));
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
    return 0;
}

void git_uninit(void) {
    for (int i=0; i<year_cnt; i++) {
        if (git_info[i]) free(git_info[i]);
    }
    if (git_info) free(git_info);
    if(chunk.memory) free(chunk.memory);
	if(curl) curl_easy_cleanup(curl);
    curl_global_cleanup();
}

void git_stop_update(void) {
    printf("git stop update!\n");
    git_last_update_time = time(NULL);
    git_updating = false;
}

void git_start_update(void) {
    printf("git start update!\n");
    git_last_update_time = 0;
}

void update_contribution_wall(void) {
    int current_year = START_YEAR;
    git_updating = true;

    while (git_updating) {
        ui_update_git_status(git_updating_percent);
        int temp = current_year-START_YEAR;
        if (!git_curl_req(NULL, current_year, git_info[temp]) ) {
            current_year++;
            git_updating_percent = (current_year-START_YEAR)*100/(end_year-START_YEAR);
            if (current_year > end_year) {
                git_updating_percent = 100;
                current_year = START_YEAR;
                git_updating = false;
                pthread_mutex_lock(&lvgl_mutex);
                ui_update_git(git_info);
                pthread_mutex_unlock(&lvgl_mutex);
                ui_update_git_status(git_updating_percent);
                git_last_update_time = time(NULL);
                printf("git update contribution: %s\n", asctime(localtime(&git_last_update_time)));
            }
        }
        usleep(500*1000);
    }
}

void git_thread(void) {
    printf("%s\n", curl_version());

    while(git_init()) {
        git_uninit();        
        sleep(1);
    }

    pthread_mutex_lock(&lvgl_mutex);
    ui_git_init(end_year);
    pthread_mutex_unlock(&lvgl_mutex);
    
    while(1) {
        if (time(NULL) - git_last_update_time > conf.git_update_cont_itv_h*3600) {
            update_contribution_wall();
        }
        sleep(1);
    }

    git_uninit();
}
