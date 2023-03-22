#pragma once

#include "curldef.h"

#define URL_GIT             "https://skyline.github.com/plainji/"
#define START_YEAR          2008

typedef struct _ui_git_t {
    char username[32];
    int year;
    unsigned char min;
    unsigned char max;
    unsigned char median;
    unsigned char p80;
    unsigned char p90;
    unsigned char p99;
    unsigned char contribution[53][7];
}ui_git_t;

int git_curl_req(int year, ui_git_t *git_info);
int git_init(void);
void git_uninit(void);
void git_thread(void);
