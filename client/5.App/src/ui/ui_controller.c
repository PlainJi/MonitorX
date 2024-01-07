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

#define CPU_USAGE_POINTER_START		(-180)
#define CPU_USAGE_POINTER_END		(1620)
#define GPU_USAGE_POINTER_START		(-180)
#define GPU_USAGE_POINTER_END		(1620)
#define CPU_TEMP_POINTER_START		(300)
#define CPU_TEMP_POINTER_END		(1500)
#define GPU_TEMP_POINTER_START		(300)
#define GPU_TEMP_POINTER_END		(1500)

#define CONTRIBUTION_PANEL_W		(750)
#define CONTRIBUTION_PANEL_H		(105)

#define GET_ANGLE_BY_PERCENT(start, end, percent) (percent/100.0f*(end-start)+start)

extern pthread_mutex_t lvgl_mutex;

char buf[32] = {0};		// monitor temp string buffer
git_t **ui_git_info;	// same as git_info**
int ui_git_end_year = 0;

void ImageRotation(lv_obj_t *obj, int start, int end, float usage) {
	int angle = (int)(usage / 100.0f * (end - start) + start);
	lv_img_set_angle(obj, angle);
}
/////////////////////////////////////
void CpuSetModel(char *model) {
	static bool init_flag = false;
	
	if (!init_flag) {
		lv_textarea_set_text(ui_CpuModel, model);
		init_flag = true;
	}
}

void CpuSetUsagePointer(float usage) {
	static int last_angle = CPU_USAGE_POINTER_START;
	int angle = GET_ANGLE_BY_PERCENT(CPU_USAGE_POINTER_START, CPU_USAGE_POINTER_END, usage);

	if (angle != last_angle) {
		ui_AnimationForPointer(ui_CpuUsagePointer, angle, 950);
		last_angle = angle;
	}
}

void CpuSetUsagePercent(float usage) {
	static int last_usage = 0;
	int cur_usage = (int)usage;

	if (cur_usage != last_usage) {
		sprintf(buf, "%d%%", cur_usage);
		lv_textarea_set_text(ui_CpuUsagePercent, buf);
		last_usage = cur_usage;
	}
}

void CpuSetFrequency(float mhz) {
	float temp = 0;
	static int last_mhz = 0;
	int cur_mhz = (int)mhz;

	if (cur_mhz != last_mhz) {
		if (mhz > 999.0f) {
			temp = mhz / 1000.0f;
			sprintf(buf, "%3.1fGHz", (double)temp);
			lv_textarea_set_text(ui_CpuFrequency, buf);
		} else {
			sprintf(buf, "%dMHz", (int)mhz);
			lv_textarea_set_text(ui_CpuFrequency, buf);
		}
		last_mhz = cur_mhz;
	}
}

void CpuSetTempPointer(float usage) {
	static int last_angle = CPU_TEMP_POINTER_START;
	int angle = GET_ANGLE_BY_PERCENT(CPU_TEMP_POINTER_START, CPU_TEMP_POINTER_END, usage);

	if (angle != last_angle) {
		ui_AnimationForPointer(ui_CpuTemp, angle, 950);
		last_angle = angle;
	}
}
/////////////////////////////////////
void GpuSetModel(char *model) {
	static bool init_flag = false;

	if (!init_flag) {
		lv_textarea_set_text(ui_GpuModel, model);
		init_flag = true;
	}
}

void GpuSetUsagePointer(float usage) {
	static int last_angle = GPU_USAGE_POINTER_START;
	int angle = GET_ANGLE_BY_PERCENT(GPU_USAGE_POINTER_START, GPU_USAGE_POINTER_END, usage);

	if (angle != last_angle) {
		ui_AnimationForPointer(ui_GpuUsagePointer, angle, 950);
		last_angle = angle;
	}
}

void GpuSetUsagePercent(float usage) {
	static int last_usage = 0;
	int cur_usage = (int)usage;

	if (cur_usage != last_usage) {
		sprintf(buf, "%d%%", cur_usage);
		lv_textarea_set_text(ui_GpuUsagePercent, buf);
		last_usage = cur_usage;
	}
}

void GpuSetFrequency(float mhz) {
	static int last_mhz = 0;
	int cur_mhz = (int)mhz;
	float temp = 0;

	if (cur_mhz != last_mhz) {
		if (mhz > 999.0f) {
			temp = mhz / 1000.0f;
			sprintf(buf, "%3.1fGHz", (double)temp);
			lv_textarea_set_text(ui_GpuFrequency, buf);
		} else {
			sprintf(buf, "%dMHz", (int)mhz);
			lv_textarea_set_text(ui_GpuFrequency, buf);
		}
		last_mhz = cur_mhz;
	}
}

void GpuSetTempPointer(float usage) {
	static int last_angle = GPU_TEMP_POINTER_START;
	int angle = GET_ANGLE_BY_PERCENT(GPU_TEMP_POINTER_START, GPU_TEMP_POINTER_END, usage);

	if (angle != last_angle) {
		ui_AnimationForPointer(ui_GpuTemp, angle, 950);
		last_angle = angle;
	}
}
/////////////////////////////////////
void MemSetUsage(float usage) {
	static int last_usage = 0;
	int cur_usage = (int)usage;

	if (cur_usage != last_usage) {
		ui_AnimationForArc(ui_MemUsageArc, cur_usage, 950);
		last_usage = cur_usage;
	}
}

void MemSetUsagePercent(float usage) {
	static int last_usage = 0;
	int cur_usage = (int)usage;

	if (cur_usage != last_usage) {
		sprintf(buf, "%d%%", cur_usage);
		lv_textarea_set_text(ui_MemUsagePercent, buf);
		last_usage = cur_usage;
	}
}

void MemSetCapacity(const char *str) {
	static bool init_flag = false;

	if (!init_flag) {
		lv_textarea_set_text(ui_MemCapacity, str);
		init_flag = true;
	}
}

void GMemSetUsage(float usage) {
	static int last_usage = 0;
	int cur_usage = (int)usage;

	if (cur_usage != last_usage) {
		ui_AnimationForArc(ui_GMemUsageArc, cur_usage, 950);
		last_usage = cur_usage;
	}
}

void GMemSetUsagePercent(float usage) {
	static int last_usage = 0;
	int cur_usage = (int)usage;

	if (cur_usage != last_usage) {
		sprintf(buf, "%d%%", cur_usage);
		lv_textarea_set_text(ui_GMemUsagePercent, buf);
		last_usage = cur_usage;
	}
}

void GMemSetCapacity(const char *str) {
	static bool init_flag = false;

	if (!init_flag) {
		lv_textarea_set_text(ui_GMemCapacity, str);
		init_flag = true;
	}
}
/////////////////////////////////////
void AutoUnit(int bytes, char *dest_buf) {
	float temp = 0.0f;
	if (bytes > 999 * 1024) {
		temp = (float)bytes / 1024.0f / 1024.0f;
		sprintf(dest_buf, "%3dMB", (int)temp);
	} else {
		temp = (float)bytes / 1024.0f;
		sprintf(dest_buf, "%3dKB", (int)temp);
	}
}

void NetSetUpload(int bytes) {
	static int last_bytes = 0;

	if (bytes != last_bytes) {
		AutoUnit(bytes, buf);
		lv_textarea_set_text(ui_Up, buf);
		last_bytes = bytes;
	}
}

void NetSetDownload(int bytes) {
	static int last_bytes = 0;

	if (bytes != last_bytes) {
		AutoUnit(bytes, buf);
		lv_textarea_set_text(ui_Down, buf);
		last_bytes = bytes;
	}
}

void IoSetRead(int bytes) {
	static int last_bytes = 0;

	if (bytes != last_bytes) {
		AutoUnit(bytes, buf);
		lv_textarea_set_text(ui_Read, buf);
		last_bytes = bytes;
	}
}

void IoSetWrite(int bytes) {
	static int last_bytes = 0;

	if (bytes != last_bytes) {
		AutoUnit(bytes, buf);
		lv_textarea_set_text(ui_Write, buf);
		last_bytes = bytes;
	}
}

/////////////////////////////////////
void SetTime(char *str) {
	static char time[16] = {0};

	if (strncmp(time, str, sizeof(time))) {
		lv_textarea_set_text(ui_Time, str);
		strncpy(time, str, sizeof(time));
	}
}

void SetWeek(char *str) {
	static char week[8] = {0};

	if (strncmp(week, str, sizeof(week))) {
		lv_textarea_set_text(ui_Week, str);
		strncpy(week, str, sizeof(week));
	}
}

void SetDate(char *str) {
	static char date[16] = {0};

	if (strncmp(date, str, sizeof(date))) {
		lv_textarea_set_text(ui_Date, str);
		strncpy(date, str, sizeof(date));
	}
}

/////////////////////////////////////
void update_time_from_local(void) {
	char temp[32] = {0};
	static char *week[] = {"Sun.", "Mon.", "Tus.", "Wed.", "Thu.", "Fri.", "Sat."};
	time_t t = time(NULL);
	struct tm *s_tm = localtime(&t);
	sprintf(temp, "%d-%02d-%02d\n", s_tm->tm_year+1900, s_tm->tm_mon, s_tm->tm_mday);
	SetDate(temp);
	sprintf(temp, "%02d:%02d\n", s_tm->tm_hour, s_tm->tm_min);
	SetTime(temp);
	sprintf(temp, "%s\n", week[s_tm->tm_wday]);
	SetWeek(temp);
}

void ui_monitor_init(void) {
	ui_InitAnimationForPointer(ui_CpuUsagePointer, CPU_USAGE_POINTER_START, CPU_USAGE_POINTER_END);
	ui_InitAnimationForPointer(ui_GpuUsagePointer, GPU_USAGE_POINTER_START, GPU_USAGE_POINTER_END);
	ui_InitAnimationForPointer(ui_CpuTemp, CPU_TEMP_POINTER_START, CPU_TEMP_POINTER_END);
	ui_InitAnimationForPointer(ui_GpuTemp, GPU_TEMP_POINTER_START, GPU_TEMP_POINTER_END);
	ui_InitAnimationForArc(ui_MemUsageArc, 0, 100);
	ui_InitAnimationForArc(ui_GMemUsageArc, 0, 100);
}

void ui_update_monitor(monitor_t *pMonitor) {
	CpuSetModel(pMonitor->cpu_model);
	CpuSetUsagePointer(pMonitor->cpu_load);
	CpuSetUsagePercent(pMonitor->cpu_load);
	MemSetUsage(pMonitor->ram_load);
	MemSetUsagePercent(pMonitor->ram_load);
	MemSetCapacity(pMonitor->ram_capacity);
	CpuSetFrequency(pMonitor->cpu_clock);
	CpuSetTempPointer(pMonitor->cpu_temp);

	GpuSetModel(pMonitor->gpu_model);
	GpuSetUsagePointer(pMonitor->gpu_load);
	GpuSetUsagePercent(pMonitor->gpu_load);
	GMemSetUsage(pMonitor->gram_load);
	GMemSetUsagePercent(pMonitor->gram_load);
	GMemSetCapacity(pMonitor->gram_capacity);
	GpuSetFrequency(pMonitor->gpu_clock);
	GpuSetTempPointer(pMonitor->gpu_temp);

	NetSetUpload(pMonitor->link_up_bytes);
	NetSetDownload(pMonitor->link_dw_bytes);
 	IoSetRead(pMonitor->io_read_bytes);
	IoSetWrite(pMonitor->io_write_bytes);
	
	//update_time_from_local();				// need time synced
	SetDate(pMonitor->date);
	SetTime(pMonitor->time);
	SetWeek(pMonitor->week);
}

void ui_monitor_disconnected(void) {
	printf("ui_monitor_disconnected\n");
	lv_obj_set_style_opa(ui_PanelMonitor, LV_OPA_10, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui_AnimationForDisconnectStart();
	lv_obj_set_style_opa(ui_PanelDisconnect, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ui_monitor_reconnected(void) {
	lv_obj_set_style_opa(ui_PanelDisconnect, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui_AnimationForDisconnectStop();
	lv_obj_set_style_opa(ui_PanelMonitor, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
}

/////////////////////////////////////////////////////////////////////////////

static uint8_t ui_git_cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CONTRIBUTION_PANEL_W, CONTRIBUTION_PANEL_H)];
lv_obj_t *ui_git_canvas;
lv_color_t color_bg_1, color_bd_1;
lv_color_t color_bg0, color_bd0;
lv_color_t color_bg1, color_bd1;
lv_color_t color_bg2, color_bd2;
lv_color_t color_bg3, color_bd3;
lv_color_t color_bg4, color_bd4;
lv_draw_rect_dsc_t ui_git_dsc;

void ui_git_init(int end_year) {
	// init username
	lv_textarea_set_text(ui_TextGitUserName, conf.git_username);

	// init year
	ui_git_end_year = end_year;
	if (end_year >= START_YEAR) {
		int length = (end_year-START_YEAR+1)*5+1;
		char *year_buf = malloc(length);
		int cnt = 0;
		while (cnt <= (end_year-START_YEAR)) {
			snprintf(year_buf+cnt*5, length-cnt*5, "%d\n", end_year-cnt);
			cnt++;
		}
		lv_dropdown_set_options(ui_year, year_buf);
		lv_obj_t * dd_list = lv_dropdown_get_list(ui_year);
		lv_obj_set_style_text_font(dd_list, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);
		free(year_buf);
	}

	// init color
	color_bg4 = lv_color_hex(0x096E3C);	 // dark green
	color_bd4 = lv_color_hex(0x0A6A3A);
	color_bg3 = lv_color_hex(0x059A50);
	color_bd3 = lv_color_hex(0x03A153);
	color_bg2 = lv_color_hex(0x16BA65);
	color_bd2 = lv_color_hex(0x15C469);
	color_bg1 = lv_color_hex(0x8BDDA3);	 // light green
	color_bd1 = lv_color_hex(0x92E9AB);
	color_bg0 = lv_color_hex(0xDFE1E4);  // grey
	color_bd0 = lv_color_hex(0xEBEDF0);
	color_bg_1 = lv_color_hex(0xFFFFFF);  // white
	color_bd_1 = lv_color_hex(0xFFFFFF);
	lv_draw_rect_dsc_init(&ui_git_dsc);
    ui_git_dsc.border_width = 1;
    ui_git_dsc.radius = 3;

    // init contribute panel
    ui_git_canvas = lv_canvas_create(ui_ContributionPanel);
	lv_obj_set_width(ui_git_canvas, CONTRIBUTION_PANEL_W);
    lv_obj_set_height(ui_git_canvas, CONTRIBUTION_PANEL_H);
    lv_canvas_set_buffer(ui_git_canvas, ui_git_cbuf, CONTRIBUTION_PANEL_W, CONTRIBUTION_PANEL_H, LV_IMG_CF_TRUE_COLOR);
	lv_canvas_fill_bg(ui_git_canvas, lv_color_make(0xff, 0xff, 0xff), LV_OPA_COVER);
	//lv_obj_set_style_radius(ui_git_canvas, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	//lv_obj_set_style_bg_color(ui_git_canvas, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_opa(ui_git_canvas, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_border_width(ui_git_canvas, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_center(ui_git_canvas);
	ui_update_contribution_panel(NULL);

	// init keyboard
	lv_obj_t *kb_git = lv_keyboard_create(ui_Git);
    lv_obj_set_x(kb_git, 0);
    lv_obj_set_y(kb_git, 0);
    lv_keyboard_set_mode(kb_git, LV_KEYBOARD_MODE_TEXT_LOWER);
    lv_keyboard_set_popovers(kb_git, true);
	lv_obj_add_flag(kb_git, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(ui_TextGitUserName, kb_event_cb, LV_EVENT_ALL, kb_git);
}

void ui_update_git_status(char percent) {
	static char cur_percent = 0;

	if (cur_percent != percent) {
		pthread_mutex_lock(&lvgl_mutex);
		if (percent != 100) {
			lv_obj_clear_flag(ui_Git_Slider_Loading, LV_OBJ_FLAG_HIDDEN);
		}
		ui_Loading_Animation(ui_Git_Slider_Loading, cur_percent, percent, 1000);
		if (percent == 100) {
			lv_obj_add_flag(ui_Git_Slider_Loading, LV_OBJ_FLAG_HIDDEN);
		}
		pthread_mutex_unlock(&lvgl_mutex);
		cur_percent = percent;
	}
}

void ui_update_contribution_panel(git_t *info) {
	const int x_start = 5;
	const int y_start = 5;
	const int w_h = 11;
	const int step = 3;

	if (info == NULL || info->max == 0) {
		ui_git_dsc.bg_color = color_bg0;
		ui_git_dsc.border_color = color_bd0;
		for (int j=0; j<=52; j++) {
			for (int k=0; k<7; k++) {
				lv_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, &ui_git_dsc);
			}
		}
	} else {
		float temp = info->max / 5.0;
		for (int j=0; j<=52; j++) {
			for (int k=0; k<7; k++) {
				if (info->contribution[j][k] == 0) {
					ui_git_dsc.bg_color = color_bg0;
					ui_git_dsc.border_color = color_bd0;
				} else {
					float cnt = (float)info->contribution[j][k] / temp;
					if (cnt <= 2.0f) {
						ui_git_dsc.bg_color = color_bg1;
						ui_git_dsc.border_color = color_bd1;
					} else if (cnt <= 3.0f) {
						ui_git_dsc.bg_color = color_bg2;
						ui_git_dsc.border_color = color_bd2;
					} else if (cnt <= 4.0f) {
						ui_git_dsc.bg_color = color_bg3;
						ui_git_dsc.border_color = color_bd3;
					} else if (cnt <= 5.0f) {
						ui_git_dsc.bg_color = color_bg4;
						ui_git_dsc.border_color = color_bd4;
					}
				}
				lv_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, &ui_git_dsc);
			}
		}
	}
}

void ui_update_contribution_panel1(git_t *info) {
	const int x_start = 5;
	const int y_start = 5;
	const int w_h = 11;
	const int step = 3;


	if (info == NULL) {
		ui_git_dsc.bg_color = color_bg0;
		ui_git_dsc.border_color = color_bd0;
		for (int j=0; j<=52; j++) {
			for (int k=0; k<7; k++) {
				lv_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, &ui_git_dsc);
			}
		}
	} else {
		for (int j=0; j<=52; j++) {
			for (int k=0; k<7; k++) {
				switch (info->contribution[j][k]) {
					case -1:
						ui_git_dsc.bg_color = color_bg_1;
						ui_git_dsc.border_color = color_bd_1;
						break;
					case 0:
						ui_git_dsc.bg_color = color_bg0;
						ui_git_dsc.border_color = color_bd0;
						break;
					case 1:
						ui_git_dsc.bg_color = color_bg1;
						ui_git_dsc.border_color = color_bd1;
						break;
					case 2:
						ui_git_dsc.bg_color = color_bg2;
						ui_git_dsc.border_color = color_bd2;
						break;
					case 3:
						ui_git_dsc.bg_color = color_bg3;
						ui_git_dsc.border_color = color_bd3;
						break;
					case 4:
						ui_git_dsc.bg_color = color_bg4;
						ui_git_dsc.border_color = color_bd4;
						break;
					default:
						ui_git_dsc.bg_color = color_bg_1;
						ui_git_dsc.border_color = color_bd_1;
						break;
				}
				lv_canvas_draw_rect(ui_git_canvas, x_start + j*(w_h+step), y_start + k*(w_h+step), w_h, w_h, &ui_git_dsc);
			}
		}
	}
}

void ui_update_contribution_panel_by_year(int year) {
	if (ui_git_info && year >= START_YEAR && year <= ui_git_end_year) {
		ui_update_contribution_panel1(ui_git_info[year-START_YEAR]);
	}
}

void ui_update_git(git_t **info) {
	ui_git_info = info;
	char dd_buf[8];
	lv_dropdown_get_selected_str(ui_year, dd_buf, sizeof(dd_buf));
	int year = atoi(dd_buf);
	ui_update_contribution_panel(ui_git_info[year-START_YEAR]);
}

int ui_git_check_username(const char *username) {
	char error_msg[128];

	int ret = git_check_username(username);
	if (ret) {
		snprintf(error_msg, sizeof(error_msg), "  Invalid username, error code: %d.", ret);
		lv_obj_t *msg_box = lv_msgbox_create(ui_Git, "Error", error_msg, NULL, true);
		lv_obj_center(msg_box);
		return 1;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

void ui_bili_reset(void) {
	lv_textarea_set_text(ui_TextFollower, " ");
	lv_textarea_set_text(ui_TextBiliUserID, "ID:");
	lv_textarea_set_text(ui_TextLike, " ");
	lv_textarea_set_text(ui_TextCoin, " ");
	lv_textarea_set_text(ui_TextFavorite, " ");
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

	snprintf(bili_buf, sizeof(bili_buf), "%d", info_all->coin);
	lv_textarea_set_text(ui_TextCoin, bili_buf);

	snprintf(bili_buf, sizeof(bili_buf), "%d", info_all->favorite);
	lv_textarea_set_text(ui_TextFavorite, bili_buf);
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


