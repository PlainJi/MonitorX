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

/**********************
 * LOCAL FUNCTIONS
 **********************/
void ui_git_draw_rect(int x, int y, int w, int h, lv_color_t background, lv_color_t border);

/**********************
 * GLOBAL FUNCTIONS
 **********************/
void ui_git_init_page(void);
int ui_git_set_year_list(int start_year, int end_year);

void ui_git_set_basic(char *username, int end_year);
int ui_git_update_basic(void);

void ui_git_set_contribution(git_t **info);
void ui_git_update_contribution(void);
void ui_update_git_status(char percent);