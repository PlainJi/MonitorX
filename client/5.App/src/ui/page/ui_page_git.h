#pragma once

#include "lvgl/lvgl.h"

#define CONTRIBUTION_PANEL_W		(750)
#define CONTRIBUTION_PANEL_H		(105)

extern lv_obj_t *ui_git;


void ui_git_init_page(void);
void ui_git_set_year_list(int start_year, int end_year);