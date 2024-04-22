#pragma once

#include "lvgl/lvgl.h"

#define CONTRIBUTION_PANEL_W		(750)
#define CONTRIBUTION_PANEL_H		(105)
#define START_YEAR                  (2008)

extern lv_obj_t *ui_git;

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

typedef int (*git_check_username_cb_)(const char*);
typedef void (*git_set_username_cb_)(const char*);
typedef void (*git_stop_update_cb_)(void);
typedef void (*git_start_update_cb_)(void);

typedef struct _git_callback_t {
    git_check_username_cb_ git_check_username_cb;
    git_set_username_cb_ git_set_username_cb;
    git_stop_update_cb_ git_stop_update_cb;
    git_start_update_cb_ git_start_update_cb;
}git_callback_t;

extern git_callback_t git_cb;

/**********************
 * LOCAL FUNCTIONS
 **********************/
void ui_git_canvas_draw_rect(lv_obj_t *obj, int x, int y, int w, int h, lv_color_t color, lv_opa_t opa);
int ui_git_get_select_year(void);
void ui_git_update_contribution_panel_by_year(int year);
int ui_git_check_username(const char *username);

/**********************
 * GLOBAL FUNCTIONS
 **********************/
void ui_git_init_page(void);
int ui_git_set_year_list(int start_year, int end_year);

void ui_git_set_basic(char *username, int end_year);
int ui_git_update_basic(void);

void ui_git_set_contribution(git_t *info);
void ui_git_update_contribution(void);
void ui_git_update_contribution_panel(git_t *info);
void ui_git_update_status(char percent);