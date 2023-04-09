#include "config.h"
#include "iniparser.h"

sys_config_t conf;
dictionary *ini = NULL;
FILE *config_file = NULL;

int config_init(void) {
    int ret = 0;
    int tmp_int;
    const char *tmp_str;

    // default config
    strncpy(conf.git_username, "PlainJi", sizeof(conf.git_username));
    conf.git_update_cont_itv_h = 5;
    strncpy(conf.bili_userid, "389426697", sizeof(conf.bili_userid));
    conf.bili_update_folw_itv_m = 5;
    conf.bili_update_stat_itv_h = 5;

    do {
        ini = iniparser_load(CONFIG_FILE_NAME);
        if (ini==NULL) {
            fprintf(stderr, "cannot parse file: %s\n", CONFIG_FILE_NAME);
            ret = 1;
            break;
        }

        // git username
        if ((tmp_str=iniparser_getstring(ini, "git:git_username", NULL)) == NULL) ret = 2;
        else strncpy(conf.git_username, tmp_str, sizeof(conf.git_username));

        // git contribute
        if ((tmp_int=iniparser_getint(ini, "git:git_update_cont_itv_h", -1)) == -1) ret = 3;
        else conf.git_update_cont_itv_h = tmp_int;

        // bili userid
        if ((tmp_str=iniparser_getstring(ini, "bili:bili_userid", NULL)) == NULL) ret = 4;
        else strncpy(conf.bili_userid, tmp_str, sizeof(conf.bili_userid));
        // bili follower
        if ((tmp_int=iniparser_getint(ini, "bili:bili_update_folw_itv_m", -1)) == -1) ret = 5;
        else conf.bili_update_folw_itv_m = tmp_int;
        // bili stat
        if ((tmp_int=iniparser_getint(ini, "bili:bili_update_stat_itv_h", -1)) == -1) ret = 6;
        else conf.bili_update_stat_itv_h = tmp_int;

        printf("git_username: %s\n", conf.git_username);
        printf("git_update_cont_itv_h: %d\n", conf.git_update_cont_itv_h);
        printf("bili userid: %s\n", conf.bili_userid);
        printf("bili_update_folw_itv_m: %d\n", conf.bili_update_folw_itv_m);
        printf("bili_update_stat_itv_h: %d\n", conf.bili_update_stat_itv_h);

    }while(0);

    return ret;
}

void config_set_git_username(const char *username) {
    strncpy(conf.git_username, username, sizeof(conf.git_username));
    save_config();
}

void config_set_bili_userid(const char *id) {
    strncpy(conf.bili_userid, id, sizeof(conf.bili_userid));
    save_config();
}

int save_config(void) {
    if (ini) {
        iniparser_set(ini, "git:git_username", conf.git_username);
        iniparser_set(ini, "bili:bili_userid", conf.bili_userid);
        
        config_file = fopen(CONFIG_FILE_NAME, "w");
        if (config_file == NULL) {
            fprintf(stderr, "cannot fopen file: %s\n", CONFIG_FILE_NAME);
            return 1;
        }
        iniparser_dump_ini(ini, config_file);
        fclose(config_file);
        config_file = NULL;
    }

    return 0;
}

void config_uninit(void) {
    if (ini) {
        dictionary_del(ini);
        ini = NULL;
    }
    if (config_file) {
        fclose(config_file);
        config_file = NULL;
    }
}