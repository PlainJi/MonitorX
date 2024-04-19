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
static int ui_git_end_year = 0;
static char ui_git_username_buf[32];
static lv_color_t color_bg_1, color_bd_1;
static lv_color_t color_bg0, color_bd0;
static lv_color_t color_bg1, color_bd1;
static lv_color_t color_bg2, color_bd2;
static lv_color_t color_bg3, color_bd3;
static lv_color_t color_bg4, color_bd4;
static lv_obj_t *ui_git_canvas;
static lv_layer_t canvas_layer;
static lv_draw_rect_dsc_t canvas_dsc;
LV_DRAW_BUF_DEFINE(canvas_draw_buf, CONTRIBUTION_PANEL_W, CONTRIBUTION_PANEL_H, LV_COLOR_FORMAT_ARGB8888);

/*
void ui_event_git(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        _ui_screen_change(ui_Bili, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Monitor, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
    if (target == ui_year && event_code == LV_EVENT_VALUE_CHANGED) {
        char buf[5];
        lv_dropdown_get_selected_str(ui_year, buf, sizeof(buf));
        ui_update_contribution_panel_by_year(atoi(buf));
    }
}
*/

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
            //git_stop_update();
        }
    }

    if (code == LV_EVENT_READY) {
        const char *input = lv_textarea_get_text(ta);
        if (ta == ui_git_username) {
            // if (ui_git_check_username(input)) {
            //     ret = 1;
            // } else {
            //     config_set_git_username(input);
            //     git_reset();
            // }
        }
        if (!ret) {
            lv_keyboard_set_textarea(kb, NULL);
            lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_state(ta, LV_STATE_ANY);
            lv_indev_reset(NULL, ta);
        }
    } else if (code == LV_EVENT_CANCEL) {
        if (ta == ui_git_username) {
            //lv_textarea_set_text(ui_git_username, conf.git_username);
            //git_start_update();
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

    ui_create_textarea(ui_git, &ui_git_username, -240, -30, 250, LV_SIZE_CONTENT, \
                        &ui_font_ascii_32, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, \
                        1, 0, "", "Username");

    ui_git_year = lv_dropdown_create(ui_git);
    lv_dropdown_set_options(ui_git_year, "2024\n");
    ui_obj_set_style_basic(ui_git_year, 240, -30, 150, 40, LV_ALIGN_CENTER);
	ui_obj_set_style_bg(ui_git_year, LV_PART_MAIN, lv_color_black(), LV_OPA_0, NULL, LV_OPA_0);
	ui_obj_set_style_border(ui_git_year, LV_PART_MAIN, 0, lv_color_black(), LV_OPA_0);
    ui_obj_set_style_text(ui_git_year, LV_PART_MAIN, &ui_font_ascii_32, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0);
    lv_obj_add_flag(ui_git_year, LV_OBJ_FLAG_EVENT_BUBBLE);     /// Flags

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

    ui_create_panel(ui_git, &ui_git_contri_panel, 0, 100, 750, 105, LV_ALIGN_CENTER);

    ui_git_logo_button = lv_imagebutton_create(ui_git);
    ui_obj_set_style_basic(ui_git_logo_button, 0, -90, 177, 177, LV_ALIGN_CENTER);
    lv_imagebutton_set_src(ui_git_logo_button, LV_IMAGEBUTTON_STATE_RELEASED, NULL, IMG(git_released), NULL);
    lv_imagebutton_set_src(ui_git_logo_button, LV_IMAGEBUTTON_STATE_PRESSED, NULL, IMG(git_pressed), NULL);

    ui_git_loading_bar = lv_bar_create(ui_git);
    ui_obj_remove_state_flag(ui_git_loading_bar);
    ui_obj_set_style_basic(ui_git_loading_bar, 0, -90, 177, 178, LV_ALIGN_CENTER);
    ui_obj_set_style_radius(ui_git_loading_bar, LV_PART_INDICATOR, 0);
    ui_obj_set_style_bg(ui_git_loading_bar, LV_PART_MAIN, lv_color_hex(0), LV_OPA_0, IMG(git_released_loading), LV_OPA_COVER);
    ui_obj_set_style_bg(ui_git_loading_bar, LV_PART_INDICATOR, lv_color_hex(0), LV_OPA_0, IMG(git_released), LV_OPA_COVER);
#ifdef DEBUG
    ui_animation(ui_git_loading_bar, 0, 100, 1000, 1000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_bar_set_value);
#endif

	// init canvas
	ui_git_canvas = lv_canvas_create(ui_git);
	ui_obj_set_style_basic(ui_git_canvas, 0, 100, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER);
	lv_canvas_set_draw_buf(ui_git_canvas, &canvas_draw_buf);
	lv_canvas_fill_bg(ui_git_canvas, lv_color_white(), LV_OPA_COVER);
    lv_canvas_init_layer(ui_git_canvas, &canvas_layer);

	// init color
	color_bg4 = lv_color_hex(0x096E3C);		// dark green
	color_bd4 = lv_color_hex(0x0A6A3A);
	color_bg3 = lv_color_hex(0x059A50);
	color_bd3 = lv_color_hex(0x03A153);
	color_bg2 = lv_color_hex(0x16BA65);
	color_bd2 = lv_color_hex(0x15C469);
	color_bg1 = lv_color_hex(0x8BDDA3);		// light green
	color_bd1 = lv_color_hex(0x92E9AB);
	color_bg0 = lv_color_hex(0xDFE1E4);		// grey
	color_bd0 = lv_color_hex(0xEBEDF0);
	color_bg_1 = lv_color_hex(0xFFFFFF);	// white
	color_bd_1 = lv_color_hex(0xFFFFFF);
	lv_draw_rect_dsc_init(&canvas_dsc);
    canvas_dsc.border_width = 1;
    canvas_dsc.radius = 3;
	ui_git_draw_rect(0, 0, 1, 1, color_bg_1, color_bd_1);


	// init keyboard
	lv_obj_t *kb_git = lv_keyboard_create(ui_git);
	ui_obj_set_style_basic(kb_git, 0, 0, 800, 240, LV_ALIGN_BOTTOM_MID);
	ui_obj_set_style_bg(kb_git, LV_PART_MAIN, lv_color_hex3(0x111111), LV_OPA_COVER, NULL, LV_OPA_COVER);
	ui_obj_set_style_bg(kb_git, LV_PART_ITEMS, lv_color_hex3(0xbbbbbb), LV_OPA_COVER, NULL, LV_OPA_COVER);
    lv_keyboard_set_mode(kb_git, LV_KEYBOARD_MODE_TEXT_LOWER);
    lv_keyboard_set_popovers(kb_git, true);
	lv_obj_add_flag(kb_git, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(ui_git_username, ui_git_kb_event_cb, LV_EVENT_ALL, kb_git);

    // lv_obj_add_event_cb(ui_Git, ui_event_Git, LV_EVENT_ALL, NULL);
}

void ui_git_draw_rect(int x, int y, int w, int h, lv_color_t background, lv_color_t border) {
	lv_area_t coords = {x, y, w, h};
	canvas_dsc.bg_color = background;
	canvas_dsc.border_color = border;
    lv_draw_rect(&canvas_layer, &canvas_dsc, &coords);
    lv_canvas_finish_layer(ui_git_canvas, &canvas_layer);
}

// ------------------------------------------------------------------------------


void ui_git_set_username(char *username) {
	lv_textarea_set_text(ui_git_username, username);
}

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

int ui_git_get_select_year(void) {
	char dd_buf[8];
	lv_dropdown_get_selected_str(ui_git_year, dd_buf, sizeof(dd_buf));
	return atoi(dd_buf);
}

void ui_update_git_status(char percent) {
	static char cur_percent = 0;

	if (cur_percent != percent) {
		if (percent != 100) {
			lv_obj_clear_flag(ui_git_loading_bar, LV_OBJ_FLAG_HIDDEN);
		}
        // TODO plain
		//ui_animation(ui_git_loading_bar, cur_percent, percent, 1000, 0, 0, 0, 0, _lv_bar_set_value);
        lv_bar_set_value(ui_git_loading_bar, percent, LV_ANIM_ON);
		if (percent == 100) {
			lv_obj_add_flag(ui_git_loading_bar, LV_OBJ_FLAG_HIDDEN);
		}
		cur_percent = percent;
	}
}

// API for skyline.github.com
void ui_git_update_contribution_panel(git_t info) {
	const int x_start = 5;
	const int y_start = 5;
	const int w_h = 11;
	const int step = 3;

	if (info.max == 0) {
		for (int j=0; j<=52; j++) {
			for (int k=0; k<7; k++) {
				ui_git_draw_rect(x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg0, color_bd0);
			}
		}
	} else {
		float temp = info.max / 5.0;
		for (int j=0; j<=52; j++) {
			for (int k=0; k<7; k++) {
				if (info.contribution[j][k] == 0) {
					ui_git_draw_rect(x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg0, color_bd0);
				} else {
					float cnt = (float)info.contribution[j][k] / temp;
					if (cnt <= 2.0f) {
						ui_git_draw_rect(x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg1, color_bd1);
					} else if (cnt <= 3.0f) {
						ui_git_draw_rect(x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg2, color_bd2);
					} else if (cnt <= 4.0f) {
						ui_git_draw_rect(x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg3, color_bd3);
					} else if (cnt <= 5.0f) {
						ui_git_draw_rect(x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg4, color_bd4);
					}
				}
			}
		}
	}
}

// API for https://github.com/users/X/contributions?from=2010-01-01&to=2020-12-31"
void ui_git_update_contribution_panel1(git_t info) {
	const int x_start = 5;
	const int y_start = 5;
	const int w_h = 11;
	const int step = 3;

	for (int j=0; j<=52; j++) {
		for (int k=0; k<7; k++) {
			char contrib = info.contribution[j][k];
			if (-1 == contrib) {
				ui_git_draw_rect(x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg1, color_bd1);
			} else if (0 == contrib) {
				ui_git_draw_rect(x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg0, color_bd0);
			} else if (1 == contrib) {
				ui_git_draw_rect(x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg1, color_bd1);
			} else if (2 == contrib) {
				ui_git_draw_rect(x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg2, color_bd2);
			} else if (3 == contrib) {
				ui_git_draw_rect(x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg3, color_bd3);
			} else if (4 == contrib) {
				ui_git_draw_rect(x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg4, color_bd4);
			} else {
				ui_git_draw_rect(x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, color_bg1, color_bd1);
			}
		}
	}
}

void ui_update_contribution_panel_by_year(int year) {
	if (year >= START_YEAR && year <= ui_git_end_year) {
		ui_git_update_contribution_panel(ui_git_info[year-START_YEAR]);
	}
}

int ui_git_check_username(const char *username) {
	char error_msg[128];

	// int ret = git_check_username(username);	//callback
	// if (ret) {
	// 	snprintf(error_msg, sizeof(error_msg), "  Invalid username, error code: %d.", ret);
	// 	lv_obj_t *msg_box = lv_msgbox_create(ui_Git, "Error", error_msg, NULL, true);
	// 	lv_obj_center(msg_box);
	// 	return 1;
	// }
	// return 0;
}


/**********************************************************************/

void ui_git_set_basic(char *username, int end_year) {
	strncpy(ui_git_username_buf, username, sizeof(ui_git_username_buf)-1);
	ui_git_end_year = end_year;
}

int ui_git_init(void) {
	pthread_mutex_lock(&lvgl_mutex);
	ui_git_set_username(ui_git_username_buf);
    ui_git_set_year_list(START_YEAR, ui_git_end_year);
	pthread_mutex_unlock(&lvgl_mutex);
}