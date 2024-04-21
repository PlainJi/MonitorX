#pragma once

#include <pthread.h>

#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"

#include "util.h"
#include "ui_helper.h"
#include "page/ui_page_bili.h"
#include "page/ui_page_clock.h"
#include "page/ui_page_git.h"
#include "page/ui_page_monitor.h"
#include "page/ui_page_quicksetting.h"
#include "page/ui_page_setting.h"
#include "page/ui_page_tomato.h"

extern lv_font_t *lv_font_fzht_14;
extern lv_font_t *lv_font_fzht_24;
extern lv_font_t *lv_font_fzht_32;
extern lv_font_t *lv_font_fzht_48;
extern lv_font_t *lv_font_fzht_64;
extern lv_font_t *lv_font_fzht_72;
extern lv_font_t *lv_font_fzht_96;
extern pthread_mutex_t lvgl_mutex;

void ui_init(void);
// void ui_Monitor_screen_init(void);
// void ui_Git_screen_init(void);
// void ui_Bili_screen_init(void);
// void ui_Tomato_screen_init(void);
