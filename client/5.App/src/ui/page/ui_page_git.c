#include "ui_page_git.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ui.h"

DEFINE_IMG(git_released_loading);
DEFINE_IMG(git_released);
DEFINE_IMG(git_pressed);

// screen git
//void ui_event_git(lv_event_t * e);
lv_obj_t * ui_git;
lv_obj_t * ui_git_username;
lv_obj_t * ui_git_year;
lv_obj_t * ui_git_contri_panel;
lv_obj_t * ui_git_Jan;
lv_obj_t * ui_git_Feb;
lv_obj_t * ui_git_Mar;
lv_obj_t * ui_git_Apr;
lv_obj_t * ui_git_May;
lv_obj_t * ui_git_Jun;
lv_obj_t * ui_git_Jul;
lv_obj_t * ui_git_Aug;
lv_obj_t * ui_git_Sep;
lv_obj_t * ui_git_Oct;
lv_obj_t * ui_git_Nov;
lv_obj_t * ui_git_Dec;
lv_obj_t * ui_git_logo_button;
lv_obj_t * ui_git_loading_bar;

git_t *ui_git_info;
git_callback git_cb;
static int ui_git_end_year = 0;
static char ui_git_username_buf[32];
static lv_color_t color_bg0;
static lv_color_t color_bg1;
static lv_color_t color_bg2;
static lv_color_t color_bg3;
static lv_color_t color_bg4;
static lv_obj_t *ui_git_canvas;
LV_DRAW_BUF_DEFINE(canvas_draw_buf, CONTRIBUTION_PANEL_W, CONTRIBUTION_PANEL_H, LV_COLOR_FORMAT_ARGB8888);

/**********************
 *   LOCAL FUNCTIONS
 **********************/

void ui_event_git(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    // if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
    //     _ui_screen_change(ui_Bili, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    // }
    // if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
    //     _ui_screen_change(ui_Monitor, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    // }
    if (target == ui_git_year && event_code == LV_EVENT_VALUE_CHANGED) {
        ui_git_update_contribution_panel_by_year(ui_git_get_select_year());
    }
}

static void ui_git_kb_event_cb(lv_event_t * e)
{
    int ret = 0;
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = lv_event_get_user_data(e);
    if(code == LV_EVENT_LONG_PRESSED) {
        lv_keyboard_set_textarea(kb, ta);
        lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
        if (ta == ui_git_username) {
			git_cb.git_stop_update_cb();
        }
    }

    if (code == LV_EVENT_READY) {
        const char *input = lv_textarea_get_text(ta);
        if (ta == ui_git_username) {
            if (ui_git_check_username(input)) {
				// invalid username

            } else {
				// valid username
				lv_keyboard_set_textarea(kb, NULL);
				lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
				lv_obj_clear_state(ta, LV_STATE_ANY);
				lv_indev_reset(NULL, ta);

                git_cb.git_set_username_cb(input);
            }
        }
    } else if (code == LV_EVENT_CANCEL) {
        if (ta == ui_git_username) {
            lv_textarea_set_text(ui_git_username, ui_git_username_buf);
            //git_cb.git_start_update_cb();
        }
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_state(ta, LV_STATE_ANY);
        lv_indev_reset(NULL, ta);
    }
}

void ui_git_init_page(void)
{
	// init local resource
	memset(ui_git_username_buf, 0, sizeof(ui_git_username_buf));
	ui_git_end_year = 2024;
	ui_git_info = NULL;

	// init page resource
    ui_create_panel(NULL, &ui_git, 0, 0, 800, 480, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_git, LV_PART_MAIN, lv_color_black(), LV_OPA_COVER, NULL, LV_OPA_COVER);
	// username
    ui_create_textarea(ui_git, &ui_git_username, -240, -30, 250, LV_SIZE_CONTENT, \
                        &ui_font_ascii_32, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, \
                        2, 0, "", "Username");
	lv_obj_clear_state(ui_git_username, LV_STATE_ANY);

	// year dropdown
    ui_git_year = lv_dropdown_create(ui_git);
    lv_dropdown_set_options(ui_git_year, "2024\n");
    ui_obj_set_style_basic(ui_git_year, 240, -30, 150, 40, LV_ALIGN_CENTER);
	ui_obj_set_style_bg(ui_git_year, LV_PART_MAIN, lv_color_black(), LV_OPA_0, NULL, LV_OPA_0);
	ui_obj_set_style_border(ui_git_year, LV_PART_MAIN, 0, lv_color_black(), LV_OPA_0);
    ui_obj_set_style_text(ui_git_year, LV_PART_MAIN, &ui_font_ascii_32, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0);
    lv_obj_add_flag(ui_git_year, LV_OBJ_FLAG_EVENT_BUBBLE);     /// Flags

	// month label
    int i = 0;
    double pos = -360;
    char *month_str[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nor", "Dec"};
    lv_obj_t *month_obj[] = {ui_git_Jan, ui_git_Feb, ui_git_Mar, ui_git_Apr, ui_git_May, ui_git_Jun, \
                            ui_git_Jul, ui_git_Aug, ui_git_Sep, ui_git_Oct, ui_git_Nov, ui_git_Dec};
    for (int i=0; i<12; i++) {
        ui_create_label(ui_git, &month_obj[i], (int)pos, 40, 50, LV_SIZE_CONTENT, &ui_font_ascii_14, \
                    LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, month_str[i]);
        pos += ((357+360)/12.0 + 2);
    }
	// contribution panel
    ui_create_panel(ui_git, &ui_git_contri_panel, 0, 100, 750, 105, LV_ALIGN_CENTER);

    ui_git_logo_button = lv_imagebutton_create(ui_git);
    ui_obj_set_style_basic(ui_git_logo_button, 0, -90, 177, 177, LV_ALIGN_CENTER);
    lv_imagebutton_set_src(ui_git_logo_button, LV_IMAGEBUTTON_STATE_RELEASED, NULL, IMG(git_released), NULL);
    lv_imagebutton_set_src(ui_git_logo_button, LV_IMAGEBUTTON_STATE_PRESSED, NULL, IMG(git_pressed), NULL);

    ui_git_loading_bar = lv_bar_create(ui_git);
    ui_obj_set_style_basic(ui_git_loading_bar, 0, -90, 177, 178, LV_ALIGN_CENTER);
    ui_obj_set_style_radius(ui_git_loading_bar, LV_PART_INDICATOR, 0);
    ui_obj_set_style_bg(ui_git_loading_bar, LV_PART_MAIN, lv_color_hex(0), LV_OPA_0, IMG(git_released_loading), LV_OPA_COVER);
    ui_obj_set_style_bg(ui_git_loading_bar, LV_PART_INDICATOR, lv_color_hex(0), LV_OPA_0, IMG(git_released), LV_OPA_COVER);
	lv_obj_set_style_anim_duration(ui_git_loading_bar, 1000, LV_PART_MAIN);
#ifdef DEBUG
    ui_animation(ui_git_loading_bar, 0, 100, 1000, 1000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_bar_set_value);
#endif

	// init canvas
	ui_git_canvas = lv_canvas_create(ui_git);
	ui_obj_set_style_basic(ui_git_canvas, 0, 100, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER);
	lv_canvas_set_draw_buf(ui_git_canvas, &canvas_draw_buf);
	lv_canvas_fill_bg(ui_git_canvas, lv_color_white(), LV_OPA_COVER);

	// init color
	color_bg4 = lv_color_hex(0x096E3C);		// dark green
	color_bg3 = lv_color_hex(0x059A50);
	color_bg2 = lv_color_hex(0x16BA65);
	color_bg1 = lv_color_hex(0x8BDDA3);		// light green
	color_bg0 = lv_color_hex(0xDFE1E4);		// grey

	// init keyboard
	lv_obj_t *kb_git = lv_keyboard_create(ui_git);
	ui_obj_set_style_basic(kb_git, 0, 0, 800, 240, LV_ALIGN_BOTTOM_MID);
	ui_obj_set_style_bg(kb_git, LV_PART_MAIN, lv_color_hex3(0x111111), LV_OPA_COVER, NULL, LV_OPA_COVER);
	ui_obj_set_style_bg(kb_git, LV_PART_ITEMS, lv_color_hex3(0xbbbbbb), LV_OPA_COVER, NULL, LV_OPA_COVER);
    lv_keyboard_set_mode(kb_git, LV_KEYBOARD_MODE_TEXT_LOWER);
    lv_keyboard_set_popovers(kb_git, true);
	lv_obj_add_flag(kb_git, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(ui_git_username, ui_git_kb_event_cb, LV_EVENT_ALL, kb_git);

    lv_obj_add_event_cb(ui_git, ui_event_git, LV_EVENT_ALL, NULL);

	ui_git_update_contribution_panel(NULL);
}

void ui_git_canvas_draw_rect(lv_obj_t *obj, int x, int y, int w, int h, lv_color_t color, lv_opa_t opa) {
	uint32_t x_, y_;

	for(x_ = (x+1); x_ < (x+w-1); x_++) {
		lv_canvas_set_px(obj, x_, y, color, opa);
	}
    for(x_ = x; x_ < (x+w); x_++) {
        for(y_ = (y+1); y_ < (y+h-1); y_++) {
            lv_canvas_set_px(obj, x_, y_, color, opa);
        }
    }
	for(x_ = (x+1); x_ < (x+w-1); x_++) {
		lv_canvas_set_px(obj, x_, y+h-1, color, opa);
	}
}

int ui_git_get_select_year(void) {
	char dd_buf[8];
	lv_dropdown_get_selected_str(ui_git_year, dd_buf, sizeof(dd_buf));
	return atoi(dd_buf);
}

// API for skyline.github.com
void ui_git_update_contribution_panel(git_t *info) {
	const int x_start = 5;
	const int y_start = 5;
	const int w_h = 11;
	const int step = 3;

	if (info == NULL || info->max == 0) {
		for (int j=0; j<=52; j++) {
			for (int k=0; k<7; k++) {
				ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg0, LV_OPA_COVER);
			}
		}
	} else {
		float temp = info->max / 5.0;
		for (int j=0; j<=52; j++) {
			for (int k=0; k<7; k++) {
				if (info->contribution[j][k] == 0) {
					ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg0, LV_OPA_COVER);
				} else {
					float cnt = (float)info->contribution[j][k] / temp;
					if (cnt <= 2.0f) {
						ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg1, LV_OPA_COVER);
					} else if (cnt <= 3.0f) {
						ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg2, LV_OPA_COVER);
					} else if (cnt <= 4.0f) {
						ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg3, LV_OPA_COVER);
					} else if (cnt <= 5.0f) {
						ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg4, LV_OPA_COVER);
					}
				}
			}
		}
	}
}

// API for https://github.com/users/X/contributions?from=2010-01-01&to=2020-12-31"
void ui_git_update_contribution_panel1(git_t *info) {
	const int x_start = 5;
	const int y_start = 5;
	const int w_h = 11;
	const int step = 3;

	if (info == NULL) {
		for (int j=0; j<=52; j++) {
			for (int k=0; k<7; k++) {
				ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg0, LV_OPA_COVER);
			}
		}
		return;
	}

	for (int j=0; j<=52; j++) {
		for (int k=0; k<7; k++) {
			char contrib = info->contribution[j][k];
			if (-1 == contrib) {
				ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg1, LV_OPA_COVER);
			} else if (0 == contrib) {
				ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg0, LV_OPA_COVER);
			} else if (1 == contrib) {
				ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg1, LV_OPA_COVER);
			} else if (2 == contrib) {
				ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg2, LV_OPA_COVER);
			} else if (3 == contrib) {
				ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg3, LV_OPA_COVER);
			} else if (4 == contrib) {
				ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg4, LV_OPA_COVER);
			} else {
				ui_git_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg1, LV_OPA_COVER);
			}
		}
	}
}

void ui_git_update_contribution_panel_by_year(int year) {
	if (ui_git_info && (year >= START_YEAR) && (year <= ui_git_end_year)) {
		ui_git_update_contribution_panel(&ui_git_info[year-START_YEAR]);
		LOG_INFO("update contribution of year %d\n", year);
	} else {
		LOG_ERR("ui_git_update_contribution_panel_by_year failed! year=%d, ui_git_info addr=0x%p\n", year, (void*)ui_git_info);
	}
}


/**********************
 *   GLOBAL FUNCTIONS
 **********************/

int ui_git_set_year_list(int start_year, int end_year) {
	ui_git_end_year = end_year;

	if (end_year >= start_year) {
		int length = (end_year-start_year+1)*5+1;
		char *year_buf = malloc(length);
        if (!year_buf) 
            return 1;

		int cnt = 0;
		while (cnt <= (end_year-start_year)) {
			snprintf(year_buf+cnt*5, length-cnt*5, "%d\n", end_year-cnt);
			cnt++;
		}
		lv_dropdown_set_options(ui_git_year, year_buf);
		lv_obj_t * dd_list = lv_dropdown_get_list(ui_git_year);
		lv_dropdown_set_selected(ui_git_year, 0);
		lv_obj_set_style_text_font(dd_list, &ui_font_ascii_24, LV_PART_MAIN | LV_STATE_DEFAULT);
		free(year_buf);
	}
}

void ui_git_set_username(char *username) {
	lv_textarea_set_text(ui_git_username, username);
}

int ui_git_check_username(const char *username) {
	char error_msg[128];

	int ret = git_cb.git_check_username_cb(username);
	if (ret) {
		snprintf(error_msg, sizeof(error_msg), "  Invalid username %s, error code: %d.", username, ret);
		lv_obj_t *mbox = lv_msgbox_create(NULL);
		lv_obj_center(mbox);
    	lv_msgbox_add_title(mbox, "Error");
		lv_msgbox_add_text(mbox, error_msg);
		lv_msgbox_add_close_button(mbox);
		return 1;
	}
	return 0;
}

void ui_git_set_basic(char *username, int end_year) {
	if (!ui_git_info) {
		ui_git_info = (git_t*)malloc(sizeof(git_t)*(end_year-START_YEAR));
	} else if (end_year != ui_git_end_year) {
		ui_git_info = (git_t*)realloc(ui_git_info, sizeof(git_t)*(end_year-START_YEAR));
	}
	ui_git_end_year = end_year;
	strncpy(ui_git_username_buf, username, sizeof(ui_git_username_buf)-1);
	LOG_INFO("ui_git_username_buf: %s, ui_git_end_year=%d\n", ui_git_username_buf, ui_git_end_year);
}

int ui_git_update_basic(void) {
	ui_git_set_username(ui_git_username_buf);
    ui_git_set_year_list(START_YEAR, ui_git_end_year);
}

void ui_git_set_contribution(git_t *info) {
	if (ui_git_info) {
		memcpy(ui_git_info, info, sizeof(git_t)*(ui_git_end_year-START_YEAR+1));
	} else {
		LOG_ERR("ui_git_set_contribution, ui_git_info is invalid!\n");
	}
}

void ui_git_update_contribution(void) {
	int year = ui_git_get_select_year();
	ui_git_update_contribution_panel_by_year(year);
}

void ui_update_git_status(char percent) {
	static char cur_percent = 0;

	if (cur_percent != percent) {
		if (percent != 100) {
			lv_obj_clear_flag(ui_git_loading_bar, LV_OBJ_FLAG_HIDDEN);
		}
        lv_bar_set_value(ui_git_loading_bar, percent, LV_ANIM_ON);
		if (percent == 100) {
			lv_obj_add_flag(ui_git_loading_bar, LV_OBJ_FLAG_HIDDEN);
		}
		cur_percent = percent;
	}
}
