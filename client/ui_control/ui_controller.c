#include "ui_controller.h"
#include "json_parser.h"
#include "../ui/ui_helpers.h"
#include <stdio.h>
#include <time.h>

#define portMAX_DELAY			(0xffff)
#define pdTRUE				(1)

#define CPU_USAGE_POINTER_START		(-170)
#define CPU_USAGE_POINTER_END		(1610)
#define GPU_USAGE_POINTER_START		(-170)
#define GPU_USAGE_POINTER_END		(1610)
#define MEM_USAGE_POINTER_START		(-450)
#define MEM_USAGE_POINTER_END		(2250)
#define GMEM_USAGE_POINTER_START	(-450)
#define GMEM_USAGE_POINTER_END		(2250)

#define GET_ANGLE_BY_PERCENT(start, end, percent) (percent/100.0f*(end-start)+start)

char buf[32] = {0};

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


void GpuSetUsagePointer(float usage) {
	int angle = GET_ANGLE_BY_PERCENT(GPU_USAGE_POINTER_START, GPU_USAGE_POINTER_END, usage);
        SetAnimation(ui_GpuUsagePointer, angle, 950);
}


void MemSetUsagePointer(float usage) {
	int angle = GET_ANGLE_BY_PERCENT(MEM_USAGE_POINTER_START, MEM_USAGE_POINTER_END, usage);
        SetAnimation(ui_MemUsagePointer, angle, 950);
}


void GMemSetUsagePointer(float usage) {
	int angle = GET_ANGLE_BY_PERCENT(GMEM_USAGE_POINTER_START, GMEM_USAGE_POINTER_END, usage);
	SetAnimation(ui_GMemUsagePointer, angle, 950);
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
        lv_textarea_set_text(ui_Upload, buf);
}

void NetSetDownload(int bytes) {
	AutoUnit(bytes, buf);
        lv_textarea_set_text(ui_Download, buf);
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

void ui_controller_init(void) {
	lv_img_set_angle(ui_CpuUsagePointer, CPU_USAGE_POINTER_START);
        CpuSetUsagePercent(0.0f);
        CpuSetFrequency(0.0f);

	lv_img_set_angle(ui_GpuUsagePointer, GPU_USAGE_POINTER_START);
	GpuSetUsagePercent(0.0f);
	GpuSetFrequency(0.0f);

	lv_img_set_angle(ui_MemUsagePointer, MEM_USAGE_POINTER_START);
	MemSetUsagePercent(0.0f);
	lv_img_set_angle(ui_GMemUsagePointer, GMEM_USAGE_POINTER_START);
	GMemSetUsagePercent(0.0f);

	NetSetUpload(0);
	NetSetDownload(0);

	IoSetRead(0);
	IoSetWrite(0);

	SetTime("--:--");
	SetWeek(" ");
	SetDate(" ");
}

void update_time() {
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

void update_ui(char *buffer) {
	parse_json(buffer);
	get_value("cpu_load");
	get_value("gpu_load");

	CpuSetUsagePointer(get_value("cpu_load"));
        CpuSetUsagePercent(get_value("cpu_load"));
	CpuSetFrequency(get_value("cpu_clock"));

        GpuSetUsagePointer(get_value("gpu_load"));
        GpuSetUsagePercent(get_value("gpu_load"));
        GpuSetFrequency(get_value("gpu_clock"));

        MemSetUsagePointer(get_value("ram_load"));
        MemSetUsagePercent(get_value("ram_load"));
        GMemSetUsagePointer(get_value("gram_load"));
        GMemSetUsagePercent(get_value("gram_load"));

        NetSetUpload(get_value("link_up"));
        NetSetDownload(get_value("link_dw"));
 
 	IoSetRead(get_value("io_write"));
        IoSetWrite(get_value("io_read"));
	
	update_time();
}












