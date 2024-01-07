#pragma once

#include "stdbool.h"
#include "curldef.h"

#define URL_GIT             "https://skyline.github.com"
#define URL_GIT_PREFIX      "https://github.com/users/"
#define URL_GIT_SUFFIX1     "/contributions?from="
#define URL_GIT_SUFFIX2     "-01-01&to="
#define URL_GIT_SUFFIX3     "-12-31"
#define START_YEAR          2008

typedef struct _git_t {
    char username[32];
    int year;
    unsigned char min;
    unsigned char max;
    unsigned char median;
    unsigned char p80;
    unsigned char p90;
    unsigned char p99;
    char contribution[53][7];
}git_t;

const char* str_skip_lines(const char *str, int lines);
const char* str_get_line(const char *str, char *buf, int length);
int get_level_from_line(const char* buf, char *level, int *count);
int git_parse_html(const char *str, git_t *ui_git);
int git_curl_req(const char *username, int year, git_t *git_info);
int git_check_username(const char *username);
void git_reset(void);
int git_init(void);
void git_uninit(void);
void git_stop_update(void);
void git_start_update(void);
void update_contribution_wall(void);
void git_thread(void);
