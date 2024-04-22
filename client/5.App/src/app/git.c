#include "git.h"

#include <time.h>
#include <pthread.h>

static git_t *git_info;
static int end_year = 0, year_cnt = 0;
static time_t git_last_update_time = 0;
static bool git_updating = true;
static char git_updating_percent = 0;
static char url_buf[128];
static CURLcode res;
static CURL *git_curl = NULL;
static struct MemoryStruct chunk;

const char* str_skip_lines(const char *str, int lines) {
    int cur_lines = 0;

    while((cur_lines<lines) && (*str)) {
        if (*str == 0x0A) cur_lines++;
        str++;
    }
    if (cur_lines == lines) return str;
    else return NULL;
}

const char* str_get_line(const char *str, char *buf, int length) {
    int cnt = 0;
    //length -= 1;
    while((*str) && (*str != 0x0A) && (cnt < length)) {
        *buf++ = *str++;
        cnt++;
    }

    if (cnt < length) {
        if ((*str) && (*str == 0x0A)) {
            *buf++ = 0x0A;
            str++;
        }
        *buf = 0;
        return str;
    } else {
        buf[length-1] = 0;
        return NULL;
    }
}

int get_level_from_line(const char *buf, char *level, int *count) {
    *level = -1;
    //              <td></td>
    if (buf[3] == '>') {
        *level = -1;
        *count = 0;
        return 0;
    } else if (buf[3] == ' ') {
        // find data-level
        char *temp1 = strstr(buf, "data-level=\"");
        if (temp1) {
            *level = (char)atoi(temp1+12);
            return 0;
        } else {
            LOG_ERR("keyword not found!\n");
            return 1;
        }
    } else {
        return 2;
    }
}

int git_parse_html(const char *str, git_t *ui_git) {
    char *cur_pos = NULL;
    char line_buf[512];
    char *buf_temp = NULL;
    char level = 0;
    int count = 0;
    // go step unused lines
    cur_pos = (char*)strstr((const char*)str, "<tr");
    if (!cur_pos) {
        return 1;
    }

    // from Sunday to Saturday
    for (int i=0; i<7; i++) {
        cur_pos = (char*)strstr((const char*)cur_pos+3, "<tr");
        if (!cur_pos) {
            return 2;
        }

        // skip unused lines
        // <tr style="height: 10px">
        // <td class="ContributionCalendar-label" style="position: relative">
        cur_pos = (char*)str_skip_lines((const char*)cur_pos, 2);
        if (!cur_pos) {
            return 3;
        }
        // <span class="sr-only">Sunday</span>
        cur_pos = (char*)str_get_line((const char*)cur_pos, line_buf, sizeof(line_buf));
        if (!cur_pos) {
            return 4;
        }
        // print weekday
        buf_temp = line_buf;
        while(*buf_temp && (*buf_temp++ != '>'));
        //printf("%s\n", buf_temp);

        for(int j=0; j<53; j++) {
            cur_pos = (char*)strstr((const char*)cur_pos, "<td");
            if (!cur_pos) {
                return 5;
            }
            cur_pos = (char*)str_get_line((const char*)cur_pos, line_buf, sizeof(line_buf));
            if (!cur_pos) {
                return 6;
            }
            if(get_level_from_line(line_buf, &level, &count)) {
                LOG_ERR("get level failed!\n");
                return 7;
            }
            ui_git->contribution[j][i] = level;
            //printf("%d ", level);
        }
        //printf("\n");
    }
    
    return 0;
}

int git_curl_req(const char *username, int year, git_t *info) {
    if (username) {
        snprintf(url_buf, sizeof(url_buf), "%s/%s/%d.json", URL_GIT, username, year);
        //snprintf(url_buf, sizeof(url_buf), "%s%s%s%d%s%d%s", \
        //    URL_GIT_PREFIX, username, URL_GIT_SUFFIX1, year, URL_GIT_SUFFIX2, year, URL_GIT_SUFFIX3);
    } else {
        snprintf(url_buf, sizeof(url_buf), "%s/%s/%d.json", URL_GIT, conf.git_username, year);
        //snprintf(url_buf, sizeof(url_buf), "%s%s%s%d%s%d%s", \
        //    URL_GIT_PREFIX, conf.git_username, URL_GIT_SUFFIX1, year, URL_GIT_SUFFIX2, year, URL_GIT_SUFFIX3);
    }
    //LOG_INFO("git_curl %s\n", url_buf);
    chunk.size = 0;
    curl_easy_setopt(git_curl, CURLOPT_URL, url_buf);
    curl_easy_setopt(git_curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(git_curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(git_curl, CURLOPT_ACCEPT_ENCODING, "gzip");
    curl_easy_setopt(git_curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(git_curl, CURLOPT_WRITEDATA, (void*)&chunk);
    res = curl_easy_perform(git_curl);
    if (res != CURLE_OK) {
        LOG_ERR("perform git_curl error:%d.\n", res);
        return 1;
    }

    // LOG_INFO("%lu %s\n", (long unsigned int)chunk.size, chunk.memory);
    int parse_res = parse_git_info(chunk.memory, info);
    // int parse_res = git_parse_html(chunk.memory, info);
    if (parse_res) {
        LOG_INFO("git_parse error! res=%d\n", parse_res);
        return 2;
    }

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////

void git_stop_update(void) {
    LOG_INFO("git stop update!\n");
    git_last_update_time = time(NULL);
    git_updating = false;
}

void git_start_update(void) {
    LOG_INFO("git start update!\n");
    git_last_update_time = 0;
}

void git_set_username(const char *username) {
    LOG_INFO("git set username: %s\n", username);
    config_set_git_username(username);
    
    git_last_update_time = 0;
    // lvgl is not thread-safe by default.
    // But it's valid in lv_event and lv_timer.
    // Beshure this func can only be called in kb_event_cb.
    ui_git_update_contribution_panel(NULL);
}

int git_check_username(const char *username) {
    git_t tmp;
    memset(&tmp, 0, sizeof(tmp));
    LOG_INFO("git checking username: %s\n", username);
    return git_curl_req(username, START_YEAR, &tmp);
}

////////////////////////////////////////////////////////////

int git_get_basic(void) {
    time_t t = time(NULL);
    struct tm *s_tm = localtime(&t);
    end_year = s_tm->tm_year+1900;
    year_cnt = end_year - START_YEAR + 1;
    LOG_INFO("Years from %d to %d, total %d years!\n", START_YEAR, end_year, year_cnt);

    if (!strlen(conf.git_username)) {
        LOG_ERR("Invalid config for git username! Use unknown instead!\n");
        strncpy(conf.git_username, "unknown", sizeof(conf.git_username));
        return 1;
    }
}

int git_init(void) {
    git_get_basic();       // make sure git_get_basic is the first to be called!

    git_info = (git_t*)calloc(year_cnt, sizeof(git_t));
    if (!git_info) {
        LOG_INFO("git_init1 Out of memory!\n");
        return 1;
    }
    memset(&chunk, 0, sizeof(chunk));
    curl_global_init(CURL_GLOBAL_ALL);
    git_curl = curl_easy_init();
    //curl_easy_setopt(git_curl, CURLOPT_VERBOSE, 1);

    git_cb.git_check_username_cb = git_check_username;
    git_cb.git_set_username_cb = git_set_username;
    git_cb.git_start_update_cb = git_start_update;
    git_cb.git_stop_update_cb = git_stop_update;
    pthread_mutex_lock(&lvgl_mutex);
    ui_git_set_basic(conf.git_username, end_year);
    ui_git_update_basic();
    pthread_mutex_unlock(&lvgl_mutex);

    return 0;
}

void git_uninit(void) {
    if (git_info) free(git_info);
    if(chunk.memory) free(chunk.memory);
	if(git_curl) curl_easy_cleanup(git_curl);
    curl_global_cleanup();
}

void git_update(void) {
    int current_year = START_YEAR;
    int git_updating_percent = 0;
    git_updating = true;

    while (git_updating) {
        pthread_mutex_lock(&lvgl_mutex);
        ui_git_update_status(git_updating_percent);
        pthread_mutex_unlock(&lvgl_mutex);

        int temp = current_year-START_YEAR;
        time_t t = time(NULL);
        LOG_INFO("getting contribution of year %d\n", current_year);

        if (git_curl_req(NULL, current_year, &git_info[temp])) {
            // failed
            pthread_mutex_lock(&lvgl_mutex);
            ui_git_update_status(100);
            pthread_mutex_unlock(&lvgl_mutex);
        } else {
            // succeed
            current_year++;
            git_updating_percent = (current_year-START_YEAR)*100/(end_year-START_YEAR);
            if (current_year > end_year) {
                git_updating = false;
                git_updating_percent = 100;
                git_last_update_time = time(NULL);

                pthread_mutex_lock(&lvgl_mutex);
                ui_git_set_contribution(git_info);
                ui_git_update_contribution();
                ui_git_update_status(git_updating_percent);
                pthread_mutex_unlock(&lvgl_mutex);
                LOG_INFO("update contribution wall complete\n");
            }
        }
        usleep((rand()%1000+500) * 1000);
    }
}

void git_thread(void) {
    LOG_INFO("curl version: %s\n", curl_version());

    while(git_init()) {
        git_uninit();
        sleep(1);
    }
    
    while(1) {
        if (time(NULL) - git_last_update_time > conf.git_update_cont_itv_h*3600) {
            git_update();
        }
        sleep(1);
    }

    git_uninit();
}
