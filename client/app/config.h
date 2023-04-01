#pragma once

#define CONFIG_FILE_NAME    "config.ini"

typedef struct _sys_config_t {
    // system

    // git params
    char git_username[32];
    int git_update_cont_itv_h;

    // bili params
    char bili_userid[16];
    int bili_update_folw_itv_m;
    int bili_update_stat_itv_h;
}sys_config_t;

extern sys_config_t conf;

int read_config(void);
void set_git_username(const char *username);
void config_set_git_username(const char *username);
void config_set_bili_userid(const char *id);
int save_config(void);
void free_config_resource(void);