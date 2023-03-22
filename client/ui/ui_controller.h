#ifndef __UI_CONTROLLER_H__
#define __UI_CONTROLLER_H__

#include "lvgl.h"
#include "ui.h"
#include "json_parser.h"

void SetAnimation(lv_obj_t * TargetObject, int new_angle, int time);
void ImageRotation(lv_obj_t *obj, int start, int end, float usage);
void SetText(lv_obj_t *obj, char *str);
void AutoUnit(int bytes, char *dest_buf);

void CpuSetUsagePointer(float usage);
void CpuSetUsagePercent(float usage);
void CpuSetFrequency(float mhz);
void CpuSetTempPointer(float usage);

void GpuSetUsagePointer(float usage);
void GpuSetUsagePercent(float usage);
void GpuSetFrequency(float mhz);
void GpuSetTempPointer(float usage);

void MemSetUsage(float usage);
void MemSetUsagePercent(float usage);
void GMemSetUsage(float usage);
void GMemSetUsagePercent(float usage);

void NetSetUpload(int bytes);
void NetSetDownload(int bytes);

void IoSetRead(int bytes);
void IoSetWrite(int bytes);

void SetTime(char *buf);
void SetWeek(char *buf);
void SetDate(char *buf);

void ui_controller_init(void);
void update_time_from_local(void);
void ui_Start(void);

void ui_update_monitor(ui_monitor_t *pMonitor);

void ui_git_init(int end_year);
void ui_update_git_status(char status);
void ui_update_contribution_panel(ui_git_t *info);
void ui_update_contribution_panel_by_year(int year);
void ui_update_git(ui_git_t **git_info);

void ui_update_bili(char *buffer);

#endif
