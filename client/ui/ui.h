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
void StartLoading_Animation(lv_obj_t * TargetObject, int v1, int v2, int time);
void kb_event_cb(lv_event_t * e);
void ui_event_Monitor(lv_event_t * e);
extern lv_obj_t * ui_Monitor;
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

void ui_event_Git(lv_event_t * e);
extern lv_obj_t * ui_Git;
extern lv_obj_t * ui_ContributionPanel;
extern lv_obj_t * ui_TextGitUserName;
extern lv_obj_t * ui_year;
extern lv_obj_t * ui_Git_ImgButtonLogo;
extern lv_obj_t * ui_Git_Slider_Loading;

void ui_event_Bili(lv_event_t * e);
extern lv_obj_t * ui_Bili;
extern lv_obj_t * ui_TextBiliUserName;
extern lv_obj_t * ui_TextBiliUserID;
extern lv_obj_t * ui_ImageFollower;
extern lv_obj_t * ui_ImageLike;
extern lv_obj_t * ui_ImageCoin;
extern lv_obj_t * ui_ImageFavorite;
extern lv_obj_t * ui_TextFollower;
extern lv_obj_t * ui_TextLike;
extern lv_obj_t * ui_TextCoin;
extern lv_obj_t * ui_TextFavorite;
extern lv_obj_t * ui_Bili_ImgButtonLogo;
extern lv_obj_t * ui_Bili_Slider_Loading;


LV_IMG_DECLARE(ui_img_bg_png);    // assets\bg.png
LV_IMG_DECLARE(ui_img_big_pointer_png);    // assets\big_pointer.png
LV_IMG_DECLARE(ui_img_mem_usage1_png);    // assets\mem_usage1.png
LV_IMG_DECLARE(ui_img_mem_usage2_png);    // assets\mem_usage2.png
LV_IMG_DECLARE(ui_img_small_pointer_png);    // assets\small_pointer.png
LV_IMG_DECLARE(ui_img_git_released_loading_png);
LV_IMG_DECLARE(ui_img_git_released_png);    // assets\git_released.png
LV_IMG_DECLARE(ui_img_git_pressed_png);    // assets\git_pressed.png
LV_IMG_DECLARE(ui_img_bili_released_loading_png);
LV_IMG_DECLARE(ui_img_bili_released_png);    // assets\bili_released.png
LV_IMG_DECLARE(ui_img_bili_pressed_png);    // assets\bili_pressed.png
LV_IMG_DECLARE(ui_img_like_png);
LV_IMG_DECLARE(ui_img_coin_png);
LV_IMG_DECLARE(ui_img_favorite_png);
LV_IMG_DECLARE(ui_img_follower_png);

LV_FONT_DECLARE(ui_font_ShangShou14);
LV_FONT_DECLARE(ui_font_ShangShou20);
LV_FONT_DECLARE(ui_font_ShangShou24);
LV_FONT_DECLARE(ui_font_ShangShou28);
LV_FONT_DECLARE(ui_font_ShangShou32);
LV_FONT_DECLARE(ui_font_ShangShou38);
LV_FONT_DECLARE(ui_font_ShangShou40);


void ui_init(void);
void ui_Monitor_screen_init(void);
void ui_Git_add_text(lv_obj_t *obj, int x, int y, const char *string);
void ui_Git_screen_init(void);
void ui_Bili_screen_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
