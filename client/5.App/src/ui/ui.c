
#include "ui.h"
#include "ui_helper.h"
#include "page/ui_page_monitor.h"
#include "page/ui_page_git.h"
#include "page/ui_page_bili.h"
#include "page/ui_page_tomato.h"
#include "page/ui_page_quicksetting.h"
#include "page/ui_page_setting.h"
#include "page/ui_page_clock.h"

//#include "ui_controller.h"
//#include "config.h"
#include <stdio.h>
#include <time.h>


///////////////////// VARIABLES ////////////////////
lv_font_t *lv_font_fzht_14;
lv_font_t *lv_font_fzht_24;
lv_font_t *lv_font_fzht_32;
lv_font_t *lv_font_fzht_48;
lv_font_t *lv_font_fzht_64;
lv_font_t *lv_font_fzht_72;
lv_font_t *lv_font_fzht_96;
pthread_mutex_t lvgl_mutex = PTHREAD_MUTEX_INITIALIZER;

/*
///////////////////// Event ////////////////////

void kb_event_cb(lv_event_t * e)
{
    int ret = 0;
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = lv_event_get_user_data(e);
    if(code == LV_EVENT_LONG_PRESSED) {
        lv_keyboard_set_textarea(kb, ta);
        lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
        if (ta == ui_TextGitUserName) {
            git_stop_update();
        } else if (ta == ui_TextBiliUserName) {
            bili_stop_update();
        }
    }

    if (code == LV_EVENT_READY) {
        const char *input = lv_textarea_get_text(ta);
        if (ta == ui_TextGitUserName) {
            if (ui_git_check_username(input)) {
                ret = 1;
            } else {
                config_set_git_username(input);
                git_reset();
            }
        } else if (ta == ui_TextBiliUserName) {
            if (ui_bili_check_userid(input)) {
                ret = 1;
            } else {
                config_set_bili_userid(input);
                bili_reset();
            }
        }
        if (!ret) {
            lv_keyboard_set_textarea(kb, NULL);
            lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_state(ta, LV_STATE_ANY);
            lv_indev_reset(NULL, ta);
        }
    } else if (code == LV_EVENT_CANCEL) {
        if (ta == ui_TextGitUserName) {
            lv_textarea_set_text(ui_TextGitUserName, conf.git_username);
            git_start_update();
        } else if (ta == ui_TextBiliUserName) {
            bili_start_update();
        }
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_state(ta, LV_STATE_ANY);
        lv_indev_reset(NULL, ta);
    }
}

*/

void ui_font_init(void)
{
    lv_font_fzht_14 = lv_freetype_font_create("./res/font/FangZhengHeiTi-GBK.ttf", \
                        LV_FREETYPE_FONT_RENDER_MODE_BITMAP, 14, FT_FONT_STYLE_NORMAL);
    if (!lv_font_fzht_14) {
        LV_LOG_ERROR("init font fzht_14 failed.");
        return;
    }

    lv_font_fzht_24 = lv_freetype_font_create("./res/font/FangZhengHeiTi-GBK.ttf", \
                        LV_FREETYPE_FONT_RENDER_MODE_BITMAP, 24, FT_FONT_STYLE_NORMAL);
    if (!lv_font_fzht_24) {
        LV_LOG_ERROR("init font fzht_24 failed.");
        return;
    }

    lv_font_fzht_32 = lv_freetype_font_create("./res/font/FangZhengHeiTi-GBK.ttf", \
                        LV_FREETYPE_FONT_RENDER_MODE_BITMAP, 32, FT_FONT_STYLE_NORMAL);
    if (!lv_font_fzht_32) {
        LV_LOG_ERROR("init font fzht_32 failed.");
        return;
    }

    lv_font_fzht_48 = lv_freetype_font_create("./res/font/FangZhengHeiTi-GBK.ttf", \
                        LV_FREETYPE_FONT_RENDER_MODE_BITMAP, 48, FT_FONT_STYLE_NORMAL);
    if (!lv_font_fzht_48) {
        LV_LOG_ERROR("init font fzht_48 failed.");
        return;
    }

    lv_font_fzht_64 = lv_freetype_font_create("./res/font/FangZhengHeiTi-GBK.ttf", \
                        LV_FREETYPE_FONT_RENDER_MODE_BITMAP, 64, FT_FONT_STYLE_NORMAL);
    if (!lv_font_fzht_64) {
        LV_LOG_ERROR("init font fzht_64 failed.");
        return;
    }

    lv_font_fzht_72 = lv_freetype_font_create("./res/font/FangZhengHeiTi-GBK.ttf", \
                        LV_FREETYPE_FONT_RENDER_MODE_BITMAP, 72, FT_FONT_STYLE_NORMAL);
    if (!lv_font_fzht_72) {
        LV_LOG_ERROR("init font fzht_72 failed.");
        return;
    }

    lv_font_fzht_96 = lv_freetype_font_create("./res/font/FangZhengHeiTi-GBK.ttf", \
                        LV_FREETYPE_FONT_RENDER_MODE_BITMAP, 96, FT_FONT_STYLE_NORMAL);
    if (!lv_font_fzht_96) {
        LV_LOG_ERROR("init font fzht_96 failed.");
        return;
    }
}

void ui_init(void) {
    // ui_font_init();
    ui_git_init_page();
    // ui_bili_init_page();
    // ui_tomato_init_page();
    // ui_clock_init_page();

    // ui_monitor_load_page(true);
    // ui_monitor_load_anim();

    //lv_screen_load(ui_monitor_connect_panel);
    lv_screen_load(ui_git);
}