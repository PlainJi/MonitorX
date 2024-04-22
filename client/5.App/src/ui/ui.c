
#include "ui.h"

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
    ui_font_init();
    
    // ui_git_init_page();
    ui_bili_init_page();
    // ui_tomato_init_page();
    // ui_clock_init_page();

    //ui_monitor_load_page(true);
    //ui_monitor_load_anim();

    lv_screen_load(ui_bili);
}