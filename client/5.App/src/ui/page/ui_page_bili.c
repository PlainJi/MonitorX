#include "ui_page_bili.h"

#include <string.h>
#include "../ui.h"

DEFINE_IMG(bili_released_loading);
DEFINE_IMG(bili_released);
DEFINE_IMG(bili_pressed);
DEFINE_IMG(face_unknown);
DEFINE_IMG(face);
DEFINE_IMG(like);
//DEFINE_IMG(coin);
DEFINE_IMG(video);
//DEFINE_IMG(favorite);
DEFINE_IMG(follower);

// screen bili
//void ui_event_Bili(lv_event_t * e);
lv_obj_t * ui_bili;
lv_obj_t * ui_bili_username;
lv_obj_t * ui_bili_userid;
lv_obj_t * ui_bili_title;
lv_obj_t * ui_bili_face_panel;
lv_obj_t * ui_bili_face;
lv_obj_t * ui_bili_like_image;
lv_obj_t * ui_bili_video_image;
lv_obj_t * ui_bili_follower_image;
//lv_obj_t * ui_bili_coin_image;
//lv_obj_t * ui_bili_favorite_image;
lv_obj_t * ui_bili_like_label;
lv_obj_t * ui_bili_video_label;
lv_obj_t * ui_bili_follower_label;
//lv_obj_t * ui_bili_coin_label;
//lv_obj_t * ui_bili_favorite_label;
lv_obj_t * ui_bili_sign;
lv_obj_t * ui_bili_logo_button;
lv_obj_t * ui_bili_loading_bar;

static bili_t ui_bili_info;
bili_callback_t bili_cb;

/**********************
 *   LOCAL FUNCTIONS
 **********************/

void kb_event_cb(lv_event_t * e)
{
    int ret = 0;
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = lv_event_get_user_data(e);

    if(code == LV_EVENT_LONG_PRESSED) {
        lv_keyboard_set_textarea(kb, ta);
        lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
        if (ta == ui_bili_username) {
            bili_cb.bili_stop_update_cb();
        }
    }
    if (code == LV_EVENT_READY) {
        const char *input = lv_textarea_get_text(ta);
        if (ta == ui_bili_username) {
            if (ui_bili_check_userid(input)) {
                ret = 1;
            } else {
                bili_cb.bili_set_userid_cb(input);
            }
        }
        if (!ret) {
            lv_keyboard_set_textarea(kb, NULL);
            lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_state(ta, LV_STATE_ANY);
            lv_indev_reset(NULL, ta);
        }
    } else if (code == LV_EVENT_CANCEL) {
        if (ta == ui_bili_username) {
            bili_cb.bili_start_update_cb();
        }
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_state(ta, LV_STATE_ANY);
        lv_indev_reset(NULL, ta);
    }
}

// void ui_event_Bili(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
//         _ui_screen_change(ui_Tomato, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
//     }
//     if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
//         _ui_screen_change(ui_Git, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
//     }
// }

void ui_bili_init_page(void) {
    // init local resource
    memset(&ui_bili_info, 0, sizeof(ui_bili_info));
    memset(&bili_cb, 0, sizeof(bili_cb));

    ui_create_panel(NULL, &ui_bili, 0, 0, 800, 480, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_bili, LV_PART_MAIN, lv_color_black(), LV_OPA_COVER, NULL, LV_OPA_COVER);

    ui_create_label(ui_bili, &ui_bili_userid, 20, 20, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_TOP_LEFT, \
                    lv_font_fzht_14, LV_TEXT_ALIGN_LEFT, lv_color_hex(0x5B5B5B), LV_OPA_COVER, 0, 0, "ID:");
    ui_create_label(ui_bili, &ui_bili_title, -20, 20, 200, LV_SIZE_CONTENT, LV_ALIGN_TOP_RIGHT, lv_font_fzht_14, \
                    LV_TEXT_ALIGN_RIGHT, lv_color_hex(0x5B5B5B), LV_OPA_COVER, 0, 0, "");
    lv_obj_set_align(ui_bili_title, LV_ALIGN_TOP_RIGHT);
    lv_label_set_long_mode(ui_bili_title, LV_LABEL_LONG_SCROLL_CIRCULAR);
    ui_create_textarea(ui_bili, &ui_bili_username, -240, -72, 250, LV_SIZE_CONTENT, lv_font_fzht_32, LV_TEXT_ALIGN_CENTER, \
                        lv_color_white(), LV_OPA_COVER, 1, 0, "", "Input UserID");
    lv_obj_clear_state(ui_bili_username, LV_STATE_ANY);

    ui_create_panel(ui_bili, &ui_bili_face_panel, 240, -72, 60, 60, LV_ALIGN_CENTER);
    ui_obj_set_style_radius(ui_bili_face_panel, LV_PART_MAIN, -10);
    ui_create_image(ui_bili_face_panel, &ui_bili_face, 0, 0, 60, 60, 20, true, LV_IMAGE_ALIGN_STRETCH, IMG(face_unknown));
    ui_create_image(ui_bili, &ui_bili_like_image,    -240, 40, 48, 48, 20, false, LV_IMAGE_ALIGN_DEFAULT, IMG(like));
    ui_create_image(ui_bili, &ui_bili_video_image,      0, 40, 48, 48, 20, false, LV_IMAGE_ALIGN_DEFAULT, IMG(video));
    ui_create_image(ui_bili, &ui_bili_follower_image, 240, 40, 48, 48, 20, false, LV_IMAGE_ALIGN_DEFAULT, IMG(follower));

    ui_create_label(ui_bili, &ui_bili_like_label,    -240, 110, 220, LV_SIZE_CONTENT, LV_ALIGN_CENTER, &ui_font_ascii_32, \
                    LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "0");
    ui_create_label(ui_bili, &ui_bili_video_label,      0, 110, 220, LV_SIZE_CONTENT, LV_ALIGN_CENTER, &ui_font_ascii_32, \
                    LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "0");
    ui_create_label(ui_bili, &ui_bili_follower_label, 240, 110, 220, LV_SIZE_CONTENT, LV_ALIGN_CENTER, &ui_font_ascii_32, \
                    LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "0");

    ui_create_label(ui_bili, &ui_bili_sign, 0, 170, 500, LV_SIZE_CONTENT, LV_ALIGN_CENTER, lv_font_fzht_24, \
                    LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "");
    lv_label_set_long_mode(ui_bili_sign, LV_LABEL_LONG_SCROLL_CIRCULAR);

    ui_bili_logo_button = lv_imagebutton_create(ui_bili);
    ui_obj_set_style_basic(ui_bili_logo_button, 0, -90, 160, 161, LV_ALIGN_CENTER);
    lv_imagebutton_set_src(ui_bili_logo_button, LV_IMAGEBUTTON_STATE_RELEASED, NULL, IMG(bili_released), NULL);
    lv_imagebutton_set_src(ui_bili_logo_button, LV_IMAGEBUTTON_STATE_PRESSED, NULL, IMG(bili_pressed), NULL);

    ui_bili_loading_bar = lv_bar_create(ui_bili);
    ui_obj_remove_state_flag(ui_bili_loading_bar);
    ui_obj_set_style_basic(ui_bili_loading_bar, 0, -90, 160, 161, LV_ALIGN_CENTER);
    ui_obj_set_style_radius(ui_bili_loading_bar, LV_PART_INDICATOR, 0);
    ui_obj_set_style_bg(ui_bili_loading_bar, LV_PART_MAIN, lv_color_hex(0), LV_OPA_0, IMG(bili_released_loading), LV_OPA_COVER);
    ui_obj_set_style_bg(ui_bili_loading_bar, LV_PART_INDICATOR, lv_color_hex(0), LV_OPA_0, IMG(bili_released), LV_OPA_COVER);

    // init keyboard
	lv_obj_t *kb_bili = lv_keyboard_create(ui_bili);
    lv_obj_set_x(kb_bili, 0);
    lv_obj_set_y(kb_bili, 0);
    lv_keyboard_set_mode(kb_bili, LV_KEYBOARD_MODE_NUMBER);
    lv_keyboard_set_popovers(kb_bili, true);
	lv_obj_add_flag(kb_bili, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(ui_bili_username, kb_event_cb, LV_EVENT_ALL, kb_bili);

    // lv_obj_add_event_cb(ui_Bili, ui_event_Bili, LV_EVENT_ALL, NULL);
}

int ui_bili_check_userid(const char *userid) {
	char error_msg[128];

	int ret = bili_cb.bili_check_userid_cb(userid);
	if (ret) {
		snprintf(error_msg, sizeof(error_msg), "  Invalid UserID %s, Error Code: %d.", userid, ret);
		lv_obj_t *mbox = lv_msgbox_create(NULL);
		lv_obj_center(mbox);
    	lv_msgbox_add_title(mbox, "Bili Error");
		lv_msgbox_add_text(mbox, error_msg);
		lv_msgbox_add_close_button(mbox);
		return 1;
	}
	return 0;
}

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void ui_bili_set_basic(const char *userid) {
    memset(ui_bili_info.userid, 0, sizeof(ui_bili_info.userid));
    strncpy(ui_bili_info.userid, userid, sizeof(ui_bili_info.userid)-1);
}

void ui_bili_update_basic(void) {
    lv_label_set_text_fmt(ui_bili_userid, "ID: %s", ui_bili_info.userid);
    lv_textarea_set_text(ui_bili_username, ui_bili_info.userid);
}

void ui_bili_set_info(bili_t *info) {
    memcpy(&ui_bili_info, info, sizeof(bili_t));
}

void ui_bili_update_info(void) {
    lv_label_set_text_fmt(ui_bili_userid, "ID: %s", ui_bili_info.userid);
    lv_textarea_set_text(ui_bili_username, ui_bili_info.username);
    lv_label_set_text(ui_bili_title, ui_bili_info.title);
    lv_label_set_text(ui_bili_sign, ui_bili_info.sign);
	lv_label_set_text_fmt(ui_bili_like_label, "%d", ui_bili_info.like);
	lv_label_set_text_fmt(ui_bili_video_label, "%d", ui_bili_info.video);
	lv_label_set_text_fmt(ui_bili_follower_label, "%d", ui_bili_info.follower);
    if (!strlen(ui_bili_info.face_path)) {
        lv_image_set_src(ui_bili_face, IMG(face_unknown));
    } else {
        lv_image_set_src(ui_bili_face, ui_bili_info.face_path);
    }
}

void ui_bili_reset_info(void) {
    memset(&ui_bili_info, 0, sizeof(ui_bili_info));
    ui_bili_update_info();
}

void ui_bili_update_status(char percent) {
	static char cur_percent = 0;

	if (cur_percent != percent) {
		if (percent != 100) {
			lv_obj_clear_flag(ui_bili_loading_bar, LV_OBJ_FLAG_HIDDEN);
		}
        lv_bar_set_value(ui_bili_loading_bar, percent, LV_ANIM_ON);
		if (percent == 100) {
			lv_obj_add_flag(ui_bili_loading_bar, LV_OBJ_FLAG_HIDDEN);
		}
		cur_percent = percent;
	}
}
