#ifndef __UI_CONTROLLER_H__
#define __UI_CONTROLLER_H__

#include "lvgl.h"
#include "ui.h"
#include "json_parser.h"

void ImageRotation(lv_obj_t *obj, int start, int end, float usage);
void SetText(lv_obj_t *obj, char *str);
void AutoUnit(int bytes, char *dest_buf);

void CpuSetModel(char *model);
void CpuSetUsagePointer(float usage);
void CpuSetUsagePercent(float usage);
void CpuSetFrequency(float mhz);
void CpuSetTempPointer(float usage);

void GpuSetModel(char *model);
void GpuSetUsagePointer(float usage);
void GpuSetUsagePercent(float usage);
void GpuSetFrequency(float mhz);
void GpuSetTempPointer(float usage);

void MemSetUsage(float usage);
void MemSetUsagePercent(float usage);
void MemSetCapacity(const char *str);
void GMemSetUsage(float usage);
void GMemSetUsagePercent(float usage);
void GMemSetCapacity(const char *str);

void NetSetUpload(int bytes);
void NetSetDownload(int bytes);

void IoSetRead(int bytes);
void IoSetWrite(int bytes);

void SetTime(char *buf);
void SetWeek(char *buf);
void SetDate(char *buf);

void update_time_from_local(void);
void ui_monitor_init(void);
void ui_update_monitor(monitor_t *pMonitor);

void ui_bili_reset(void);
void ui_git_init(int end_year);
void ui_update_git_status(char percent);
void ui_update_contribution_panel(git_t *info);
void ui_update_contribution_panel_by_year(int year);
void ui_update_git(git_t **git_info);
int ui_git_check_username(const char *username);


void ui_bili_init(void);
void ui_update_bili_status(char percent);
void ui_update_bili_relation(bili_relation_t *relation);
void ui_update_bili(bili_t *info);
int ui_bili_check_userid(const char *userid);

#endif
