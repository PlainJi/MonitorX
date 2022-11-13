// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: DesktopBox

#ifndef _DESKTOPBOX_UI_H
#define _DESKTOPBOX_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

void StartCpuPointer_Animation(lv_obj_t * TargetObject, int delay);
void StartGpuPointer_Animation(lv_obj_t * TargetObject, int delay);
void StartCpuTemp_Animation(lv_obj_t * TargetObject, int delay);
void StartGpuTemp_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_Screen1(lv_event_t * e);
void ui_Screen1_Start(void);
extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_PanelMonitor;
extern lv_obj_t * ui_PanelMonitorCpu;
extern lv_obj_t * ui_CpuModel;
extern lv_obj_t * ui_MemCapacity;
extern lv_obj_t * ui_CpuUsagePointer;
extern lv_obj_t * ui_CpuUsagePercent;
extern lv_obj_t * ui_CpuFrequency;
extern lv_obj_t * ui_MemUsageArc;
extern lv_obj_t * ui_MemUsagePercent;
extern lv_obj_t * ui_CpuTemp;
extern lv_obj_t * ui_PanelMonitorGpu;
extern lv_obj_t * ui_GpuModel;
extern lv_obj_t * ui_GMemCapacity;
extern lv_obj_t * ui_GpuUsagePointer;
extern lv_obj_t * ui_GpuUsagePercent;
extern lv_obj_t * ui_GpuFrequency;
extern lv_obj_t * ui_GMemUsageArc;
extern lv_obj_t * ui_GMemUsagePercent;
extern lv_obj_t * ui_GpuTemp;
extern lv_obj_t * ui_PanelMid;
extern lv_obj_t * ui_Time;
extern lv_obj_t * ui_Week;
extern lv_obj_t * ui_Date;
extern lv_obj_t * ui_Up;
extern lv_obj_t * ui_Down;
extern lv_obj_t * ui_Read;
extern lv_obj_t * ui_Write;


LV_IMG_DECLARE(ui_img_bg_png);    // assets\bg.png
LV_IMG_DECLARE(ui_img_big_pointer_png);    // assets\big_pointer.png
LV_IMG_DECLARE(ui_img_mem_usage1_png);    // assets\mem_usage1.png
LV_IMG_DECLARE(ui_img_mem_usage2_png);    // assets\mem_usage2.png
LV_IMG_DECLARE(ui_img_small_pointer_png);    // assets\small_pointer.png


LV_FONT_DECLARE(ui_font_ShangShou24);
LV_FONT_DECLARE(ui_font_ShangShou28);
LV_FONT_DECLARE(ui_font_ShangShou32);
LV_FONT_DECLARE(ui_font_ShangShou40);
LV_FONT_DECLARE(ui_font_ShangShou38);
LV_FONT_DECLARE(ui_font_ShangShou20);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
