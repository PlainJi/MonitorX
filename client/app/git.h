#pragma once

#include "curldef.h"

#define URL_GIT             "https://skyline.github.com"
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
    unsigned char contribution[53][7];
}git_t;

int git_curl_req(const char *username, int year, git_t *git_info);
int git_check_username(const char *username);
void git_reset(void);
int git_init(void);
void git_uninit(void);
void git_stop_update(void);
void update_contribution_wall(void);
void git_thread(void);
