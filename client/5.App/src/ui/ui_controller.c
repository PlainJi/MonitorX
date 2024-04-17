#if 0
#include "ui_controller.h"
#include "json_parser.h"
#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include "monitor.h"
#include "git.h"
#include "bili.h"
#include "tomato.h"
#include "config.h"

#define portMAX_DELAY				(0xffff)
#define pdTRUE						(1)



/////////////////////////////////////////////////////////////////////////////



void ui_bili_reset(void) {
	lv_textarea_set_text(ui_TextBiliUserID, "ID");
	lv_label_set_text(ui_TextBiliTitle, "Title");
	lv_textarea_set_text(ui_TextLike, "0");
	lv_textarea_set_text(ui_TextVideo, "0");
	lv_textarea_set_text(ui_TextFollower, "0");
}

void ui_bili_init(void) {
	char bili_buf[32] = {0};
	ui_bili_reset();

	snprintf(bili_buf, sizeof(bili_buf), "ID: %s", conf.bili_userid);
	lv_textarea_set_text(ui_TextBiliUserID, bili_buf);

	// init keyboard
	lv_obj_t *kb_bili = lv_keyboard_create(ui_Bili);
    lv_obj_set_x(kb_bili, 0);
    lv_obj_set_y(kb_bili, 0);
    lv_keyboard_set_mode(kb_bili, LV_KEYBOARD_MODE_NUMBER);
    lv_keyboard_set_popovers(kb_bili, true);
	lv_obj_add_flag(kb_bili, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(ui_TextBiliUserName, kb_event_cb, LV_EVENT_ALL, kb_bili);
}

void ui_update_bili_status_mutex(char percent) {
	static char cur_percent = 0;
	if (cur_percent != percent) {
		pthread_mutex_lock(&lvgl_mutex);
		if (percent != 100) {
			lv_obj_clear_flag(ui_Bili_Slider_Loading, LV_OBJ_FLAG_HIDDEN);
		}
		ui_Loading_Animation(ui_Bili_Slider_Loading, cur_percent, percent, 800);
		if (percent == 100) {
			lv_obj_add_flag(ui_Bili_Slider_Loading, LV_OBJ_FLAG_HIDDEN);
		}
		pthread_mutex_unlock(&lvgl_mutex);
		cur_percent = percent;
	}
}

void ui_update_bili_relation(bili_relation_t *relation) {
	char bili_buf[16] = {0};

	snprintf(bili_buf, sizeof(bili_buf), "%d", relation->follower);
	lv_textarea_set_text(ui_TextFollower, bili_buf);
}

void ui_update_bili_username(char *username) {
	lv_textarea_set_text(ui_TextBiliUserName, username);
}

void ui_update_bili(bili_t *info_all) {
	char bili_buf[32] = {0};

	snprintf(bili_buf, sizeof(bili_buf), "ID: %s", info_all->userid);
	lv_textarea_set_text(ui_TextBiliUserID, bili_buf);
	lv_textarea_set_text(ui_TextBiliUserName, info_all->username);

	snprintf(bili_buf, sizeof(bili_buf), "%d", info_all->like);
	lv_textarea_set_text(ui_TextLike, bili_buf);

	snprintf(bili_buf, sizeof(bili_buf), "%d", info_all->video);
	lv_textarea_set_text(ui_TextVideo, bili_buf);

	snprintf(bili_buf, sizeof(bili_buf), "%d", info_all->follower);
	lv_textarea_set_text(ui_TextFollower, bili_buf);
}

void ui_update_bili_card(bili_t *info_all) {
	char bili_buf[32] = {0};

	snprintf(bili_buf, sizeof(bili_buf), "ID: %s", info_all->userid);
	lv_textarea_set_text(ui_TextBiliUserID, bili_buf);
	lv_label_set_text(ui_TextBiliTitle, info_all->title);

	lv_textarea_set_text(ui_TextBiliUserName, info_all->username);
	printf("%s\n", info_all->face_url);

	snprintf(bili_buf, sizeof(bili_buf), "%d", info_all->like);
	lv_textarea_set_text(ui_TextLike, bili_buf);

	snprintf(bili_buf, sizeof(bili_buf), "%d", info_all->video);
	lv_textarea_set_text(ui_TextVideo, bili_buf);

	snprintf(bili_buf, sizeof(bili_buf), "%d", info_all->follower);
	lv_textarea_set_text(ui_TextFollower, bili_buf);

	lv_label_set_text(ui_TextSign, info_all->sign);
}

int ui_bili_check_userid(const char *userid) {
	char error_msg[128];

	int ret = bili_check_userid(userid);
	if (ret) {
		snprintf(error_msg, sizeof(error_msg), "  Invalid userID, please check your input. ErrNo. %d.", ret);
		lv_obj_t *msg_box = lv_msgbox_create(ui_Bili, "Error", error_msg, NULL, true);
		lv_obj_center(msg_box);
		return 1;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////

void ui_tomato_set_time(int minutes) {
    lv_meter_set_indicator_value(ui_meter, ui_indic_pointer, minutes);
    lv_meter_set_indicator_end_value(ui_meter, ui_indic_pie, minutes);
}

void ui_tomato_init(void) {
	ui_tomato_set_time(0);
	lv_arc_set_value(ui_ArcTomato, 1);
}

void ui_update_tomato_time(int time_min) {
	tomato_time_min = time_min;
	left_time_min = time_min;
	start_sec = time(NULL);
	printf("ui_update_tomato_time: %d\n", time_min);
}


#endif