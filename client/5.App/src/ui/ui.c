
#include "ui.h"
#include "ui_helper.h"
#include "page/ui_page_monitor.h"
#include "page/ui_page_git.h"
#include "page/ui_page_bili.h"
#include "page/ui_page_tomato.h"
#include "page/ui_page_quicksetting.h"
#include "page/ui_page_setting.h"

//#include "ui_controller.h"
//#include "config.h"
#include <stdio.h>
#include <time.h>


///////////////////// VARIABLES ////////////////////
lv_font_t *lv_font_fzht_14;
lv_font_t *lv_font_fzht_24;
lv_font_t *lv_font_fzht_32;

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


    // // init font
    // static lv_ft_info_t info;
    // info.name = "./res/font/FangZhengHeiTi-GBK.ttf";
    // info.weight = 32;
    // info.style = FT_FONT_STYLE_NORMAL;
    // info.mem = NULL;

    // if(!lv_ft_font_init(&info)) {
    //     LV_LOG_ERROR("init font failed.");
    //     return;
    // }
    // lv_style_init(&style_font_fzht_32);
    // lv_style_set_text_font(&style_font_fzht_32, info.font);

    // info.weight = 14;
    // if(!lv_ft_font_init(&info)) {
    //     LV_LOG_ERROR("init font failed.");
    //     return;
    // }
    // lv_style_init(&style_font_fzht_14);
    // lv_style_set_text_font(&style_font_fzht_14, info.font);

    // info.weight = 24;
    // if(!lv_ft_font_init(&info)) {
    //     LV_LOG_ERROR("init font failed.");
    //     return;
    // }
    // lv_style_init(&style_font_fzht_24);
    // lv_style_set_text_font(&style_font_fzht_24, info.font);

    // lv_disp_t * dispp = lv_disp_get_default();
    // lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), \
    //                             lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    // lv_disp_set_theme(dispp, theme);

    // ui_Monitor_screen_init();
    // ui_Git_screen_init();
    // ui_Bili_screen_init();
    // ui_Tomato_screen_init();
    // lv_disp_load_scr(ui_Monitor);
}

void ui_init(void) {
    ui_font_init();

    ui_monitor_init();
    ui_git_init();
    ui_bili_init();
    ui_tomato_init();
    //lv_screen_load(ui_monitor_connect_panel);
    //lv_screen_load(ui_monitor_disconnect_panel);
    lv_screen_load(ui_tomato);
    //lv_screen_load_anim(ui_monitor_connect_panel, LV_SCR_LOAD_ANIM_OUT_TOP, 1000, 0, true);
}