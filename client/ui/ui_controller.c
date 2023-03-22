#include "ui_controller.h"
#include "json_parser.h"
#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "monitor.h"
#include "git.h"
#include "bili.h"

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


#define GET_ANGLE_BY_PERCENT(start, end, percent) (percent/100.0f*(end-start)+start)

char buf[32] = {0};		// monitor temp string buffer
ui_git_t **ui_git_info;	// same as git_info**
int ui_git_end_year = 0;

void SetAnimation(lv_obj_t * TargetObject, int new_angle, int time)
{
	lv_anim_t PropertyAnimation_0;
	lv_anim_init(&PropertyAnimation_0);
	lv_anim_set_time(&PropertyAnimation_0, time);
	lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
	lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
	int start = lv_img_get_angle(TargetObject);
	if (start > 2700) start -= 65536;
	lv_anim_set_values(&PropertyAnimation_0, start, new_angle);
	lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
	lv_anim_set_delay(&PropertyAnimation_0, 0);
	lv_anim_set_playback_time(&PropertyAnimation_0, 0);
	lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
	lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
	lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
	lv_anim_set_early_apply(&PropertyAnimation_0, false);
	lv_anim_start(&PropertyAnimation_0);
}

void ImageRotation(lv_obj_t *obj, int start, int end, float usage) {
	int angle = (int)(usage / 100.0f * (end - start) + start);
	lv_img_set_angle(obj, angle);
}

void CpuSetUsagePointer(float usage) {
	int angle = GET_ANGLE_BY_PERCENT(CPU_USAGE_POINTER_START, CPU_USAGE_POINTER_END, usage);
	SetAnimation(ui_CpuUsagePointer, angle, 950);
}

void CpuSetTempPointer(float usage) {
	int angle = GET_ANGLE_BY_PERCENT(CPU_TEMP_POINTER_START, CPU_TEMP_POINTER_END, usage);
	SetAnimation(ui_CpuTemp, angle, 950);
}

void GpuSetUsagePointer(float usage) {
	int angle = GET_ANGLE_BY_PERCENT(GPU_USAGE_POINTER_START, GPU_USAGE_POINTER_END, usage);
	SetAnimation(ui_GpuUsagePointer, angle, 950);
}

void GpuSetTempPointer(float usage) {
	int angle = GET_ANGLE_BY_PERCENT(GPU_TEMP_POINTER_START, GPU_TEMP_POINTER_END, usage);
	SetAnimation(ui_GpuTemp, angle, 950);
}

void MemSetUsage(float usage) {
	lv_arc_set_value(ui_MemUsageArc, usage);
}

void GMemSetUsage(float usage) {
	lv_arc_set_value(ui_GMemUsageArc, usage);
}

void SetText(lv_obj_t *obj, char* str) {
	lv_textarea_set_text(obj, str);
}

void CpuSetUsagePercent(float usage) {
	sprintf(buf, "%d%%", (int)usage);
	SetText(ui_CpuUsagePercent, buf);
}

void GpuSetUsagePercent(float usage) {
	sprintf(buf, "%d%%", (int)usage);
	SetText(ui_GpuUsagePercent, buf);
}

void MemSetUsagePercent(float usage) {
	sprintf(buf, "%d%%", (int)usage);
	SetText(ui_MemUsagePercent, buf);
}

void GMemSetUsagePercent(float usage) {
	sprintf(buf, "%d%%", (int)usage);
	SetText(ui_GMemUsagePercent, buf);
}

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
	AutoUnit(bytes, buf);
	lv_textarea_set_text(ui_Up, buf);
}

void NetSetDownload(int bytes) {
	AutoUnit(bytes, buf);
	lv_textarea_set_text(ui_Down, buf);
}

void IoSetRead(int bytes) {
	AutoUnit(bytes, buf);
	lv_textarea_set_text(ui_Read, buf);
}

void IoSetWrite(int bytes) {
	AutoUnit(bytes, buf);
	lv_textarea_set_text(ui_Write, buf);
}

void CpuSetFrequency(float mhz) {
	float temp = 0;
	if (mhz > 999.0f) {
		temp = mhz / 1000.0f;
		sprintf(buf, "%3.1fGHz", (double)temp);
		SetText(ui_CpuFrequency, buf);
	} else {
		sprintf(buf, "%dMHz", (int)mhz);
		SetText(ui_CpuFrequency, buf);
	}
}

void GpuSetFrequency(float mhz) {
	float temp = 0;
	if (mhz > 999.0f) {
		temp = mhz / 1000.0f;
		sprintf(buf, "%3.1fGHz", (double)temp);
		SetText(ui_GpuFrequency, buf);
	} else {
		sprintf(buf, "%dMHz", (int)mhz);
		SetText(ui_GpuFrequency, buf);
	}
}

void SetTime(char *str) {
	lv_textarea_set_text(ui_Time, str);
}

void SetWeek(char *str) {
	lv_textarea_set_text(ui_Week, str);
}

void SetDate(char *str) {
	lv_textarea_set_text(ui_Date, str);
}

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

void ui_Start(void) {
	StartGpuTemp_Animation(ui_GpuTemp, 0);
    StartCpuTemp_Animation(ui_CpuTemp, 0);
    StartGpuPointer_Animation(ui_GpuUsagePointer, 0);
    StartCpuPointer_Animation(ui_CpuUsagePointer, 0);
}

void ui_controller_init(void) {
	// lv_img_set_angle(ui_CpuUsagePointer, CPU_USAGE_POINTER_START);
	// CpuSetUsagePercent(0.0f);
	// CpuSetFrequency(0.0f);

	// lv_img_set_angle(ui_GpuUsagePointer, GPU_USAGE_POINTER_START);
	// GpuSetUsagePercent(0.0f);
	// GpuSetFrequency(0.0f);

	// //lv_img_set_angle(ui_MemUsagePointer, MEM_USAGE_POINTER_START);
	// MemSetUsagePercent(0.0f);
	// //lv_img_set_angle(ui_GMemUsagePointer, GMEM_USAGE_POINTER_START);
	// GMemSetUsagePercent(0.0f);

	// NetSetUpload(0);
	// NetSetDownload(0);

	// IoSetRead(0);
	// IoSetWrite(0);

	// SetTime(" ");
	// SetWeek(" ");
	// SetDate(" ");

	ui_Start();
}

void ui_update_monitor(ui_monitor_t *pMonitor) {
	CpuSetUsagePointer(pMonitor->cpu_load);
	CpuSetUsagePercent(pMonitor->cpu_load);
	MemSetUsage(pMonitor->ram_load);
	MemSetUsagePercent(pMonitor->ram_load);
	CpuSetFrequency(pMonitor->cpu_clock);
	CpuSetTempPointer(pMonitor->cpu_temp);

	GpuSetUsagePointer(pMonitor->gpu_load);
	GpuSetUsagePercent(pMonitor->gpu_load);
	GMemSetUsage(pMonitor->gram_load);
	GMemSetUsagePercent(pMonitor->gram_load);
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

/////////////////////////////////////////////////////////////////////////////

static uint8_t ui_git_cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(750, 142)];
lv_obj_t *ui_git_canvas;
lv_color_t color_bg0, color_bd0;
lv_color_t color_bg1, color_bd1;
lv_color_t color_bg2, color_bd2;
lv_color_t color_bg3, color_bd3;
lv_color_t color_bg4, color_bd4;
lv_draw_rect_dsc_t ui_git_dsc;

void ui_git_init(int end_year) {
	// init username
	SetText(ui_username, "PlainJi");

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
	lv_draw_rect_dsc_init(&ui_git_dsc);
    ui_git_dsc.border_width = 1;
    ui_git_dsc.radius = 3;

    // init contribute panel
    ui_git_canvas = lv_canvas_create(ui_ContributionPanel);
    lv_canvas_set_buffer(ui_git_canvas, ui_git_cbuf, 750, 142, LV_IMG_CF_TRUE_COLOR);
    lv_canvas_fill_bg(ui_git_canvas, lv_color_make(0xff, 0xff, 0xff), LV_OPA_COVER);
    lv_obj_center(ui_git_canvas);
	ui_update_contribution_panel(NULL);
}

void ui_update_git_status(char status) {
	//pthread_mutex_lock(&lvgl_mutex);
	//printf("ui_update_git_status: %d\n", status);
	//pthread_mutex_unlock(&lvgl_mutex);
}

void ui_update_contribution_panel(ui_git_t *info) {
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

void ui_update_contribution_panel_by_year(int year) {
	if (ui_git_info && year >= START_YEAR && year <= ui_git_end_year) {
		ui_update_contribution_panel(ui_git_info[year-START_YEAR]);
	}
}

void ui_update_git(ui_git_t **info) {
	ui_git_info = info;
	char dd_buf[8];
	lv_dropdown_get_selected_str(ui_year, dd_buf, sizeof(dd_buf));
	int year = atoi(dd_buf);
	ui_update_contribution_panel(ui_git_info[year-START_YEAR]);
}

void ui_update_bili(char *buffer) {
	
}








