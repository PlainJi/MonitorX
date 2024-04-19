#pragma once

#include <stdbool.h>
#include "app.h"
#include "ui.h"

#define URL_GIT             "https://skyline.github.com"
#define URL_GIT_PREFIX      "https://github.com/users/"
#define URL_GIT_SUFFIX1     "/contributions?from="
#define URL_GIT_SUFFIX2     "-01-01&to="
#define URL_GIT_SUFFIX3     "-12-31"

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
