// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

void Pointer_Animation(lv_obj_t * TargetObject, int delay);
extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_bg;
extern lv_obj_t * ui_CpuUsagePointer;
extern lv_obj_t * ui_MemUsagePointer;
extern lv_obj_t * ui_GMemUsagePointer;
extern lv_obj_t * ui_GpuUsagePointer;
extern lv_obj_t * ui_Time;
extern lv_obj_t * ui_Week;
extern lv_obj_t * ui_Date;
extern lv_obj_t * ui_CpuUsagePercent;
extern lv_obj_t * ui_GpuUsagePercent;
extern lv_obj_t * ui_MemUsagePercent;
extern lv_obj_t * ui_GMemUsagePercent;
extern lv_obj_t * ui_Upload;
extern lv_obj_t * ui_Download;
extern lv_obj_t * ui_Read;
extern lv_obj_t * ui_Write;
extern lv_obj_t * ui_CpuFrequency;
extern lv_obj_t * ui_GpuFrequency;
extern lv_obj_t * ui_CPUModel;
extern lv_obj_t * ui_GPUModel;


LV_IMG_DECLARE(ui_img_bg2_png);    // assets\bg2.png
LV_IMG_DECLARE(ui_img_bigpointer_png);    // assets\BigPointer.png
LV_IMG_DECLARE(ui_img_smallpointer_png);    // assets\SmallPointer.png


LV_FONT_DECLARE(ui_font_ShangShou16);
LV_FONT_DECLARE(ui_font_ShangShou32);
LV_FONT_DECLARE(ui_font_ShangShou24);
LV_FONT_DECLARE(ui_font_ShangShou48);
LV_FONT_DECLARE(ui_font_ShangShou40);
LV_FONT_DECLARE(ui_font_ShangShou28);

void ui_Screen1_screen_init(void);
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
