// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: DesktopBox

#include "ui.h"
#include "ui_helpers.h"
#include "ui_controller.h"
#include <stdio.h>

///////////////////// VARIABLES ////////////////////
void StartCpuPointer_Animation(lv_obj_t * TargetObject, int delay);
void StartGpuPointer_Animation(lv_obj_t * TargetObject, int delay);
void StartCpuTemp_Animation(lv_obj_t * TargetObject, int delay);
void StartGpuTemp_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_Monitor(lv_event_t * e);
lv_obj_t * ui_Monitor;
lv_obj_t * ui_PanelMonitor;
lv_obj_t * ui_PanelMonitorCpu;
lv_obj_t * ui_CpuModel;
lv_obj_t * ui_MemCapacity;
lv_obj_t * ui_CpuUsagePointer;
lv_obj_t * ui_CpuUsagePercent;
lv_obj_t * ui_CpuFrequency;
lv_obj_t * ui_MemUsageArc;
lv_obj_t * ui_MemUsagePercent;
lv_obj_t * ui_CpuTemp;
lv_obj_t * ui_PanelMonitorGpu;
lv_obj_t * ui_GpuModel;
lv_obj_t * ui_GMemCapacity;
lv_obj_t * ui_GpuUsagePointer;
lv_obj_t * ui_GpuUsagePercent;
lv_obj_t * ui_GpuFrequency;
lv_obj_t * ui_GMemUsageArc;
lv_obj_t * ui_GMemUsagePercent;
lv_obj_t * ui_GpuTemp;
lv_obj_t * ui_PanelMid;
lv_obj_t * ui_Time;
lv_obj_t * ui_Week;
lv_obj_t * ui_Date;
lv_obj_t * ui_Up;
lv_obj_t * ui_Down;
lv_obj_t * ui_Read;
lv_obj_t * ui_Write;
void ui_event_Git(lv_event_t * e);
lv_obj_t * ui_Git;
lv_obj_t * ui_ContributionPanel;
lv_obj_t * ui_username;
lv_obj_t * ui_year;
lv_obj_t * ui_Git_ImgButton2;
void ui_event_Bili(lv_event_t * e);
lv_obj_t * ui_Bili;
lv_obj_t * ui_LabelLikes;
lv_obj_t * ui_LabelFollowers;
lv_obj_t * ui_LabelViews;
lv_obj_t * ui_views;
lv_obj_t * ui_followers;
lv_obj_t * ui_likes;
lv_obj_t * ui_nickname;
lv_obj_t * ui_userid;
lv_obj_t * ui_Bili_ImgButton3;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void StartCpuPointer_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, -180, 1620);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 2000);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_1, 1620, -180);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 1000);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);

}
void StartGpuPointer_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, -180, 1620);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 2000);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_1, 1620, -180);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 1000);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);

}
void StartCpuTemp_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 300, 1500);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 2000);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_1, 1500, 300);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 1000);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);

}
void StartGpuTemp_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 300, 1500);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 2000);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_1, 1500, 300);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 1000);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_Monitor(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    // if(event_code == LV_EVENT_SCREEN_LOADED) {
    //     StartGpuTemp_Animation(ui_GpuTemp, 0);
    //     StartCpuTemp_Animation(ui_CpuTemp, 0);
    //     StartGpuPointer_Animation(ui_GpuUsagePointer, 0);
    //     StartCpuPointer_Animation(ui_CpuUsagePointer, 0);
    // }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        _ui_screen_change(ui_Git, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Bili, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}

void ui_event_Git(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        _ui_screen_change(ui_Bili, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Monitor, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
    if (target == ui_year && event_code == LV_EVENT_VALUE_CHANGED) {
        char buf[5];
        lv_dropdown_get_selected_str(ui_year, buf, sizeof(buf));
        ui_update_contribution_panel_by_year(atoi(buf));
    }
}

void ui_event_Bili(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        _ui_screen_change(ui_Monitor, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Git, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Monitor_screen_init(void)
{
    ui_Monitor = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Monitor, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Monitor, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Monitor, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelMonitor = lv_obj_create(ui_Monitor);
    lv_obj_set_width(ui_PanelMonitor, 800);
    lv_obj_set_height(ui_PanelMonitor, 480);
    lv_obj_set_x(ui_PanelMonitor, 0);
    lv_obj_set_y(ui_PanelMonitor, -20);
    lv_obj_clear_flag(ui_PanelMonitor, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE |
                      LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_PanelMonitor, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelMonitor, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMonitor, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_PanelMonitor, &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelMonitor, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelMonitorCpu = lv_obj_create(ui_PanelMonitor);
    lv_obj_set_width(ui_PanelMonitorCpu, 392);
    lv_obj_set_height(ui_PanelMonitorCpu, 476);
    lv_obj_set_x(ui_PanelMonitorCpu, -16);
    lv_obj_set_y(ui_PanelMonitorCpu, 31);
    lv_obj_clear_flag(ui_PanelMonitorCpu,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_PanelMonitorCpu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelMonitorCpu, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMonitorCpu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelMonitorCpu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CpuModel = lv_label_create(ui_PanelMonitorCpu);
    lv_obj_set_width(ui_CpuModel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_CpuModel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_CpuModel, -40);
    lv_obj_set_y(ui_CpuModel, -185);
    lv_obj_set_align(ui_CpuModel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_CpuModel, "i7-6700K");
    lv_obj_clear_flag(ui_CpuModel, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_CpuModel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CpuModel, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MemCapacity = lv_label_create(ui_PanelMonitorCpu);
    lv_obj_set_width(ui_MemCapacity, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MemCapacity, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MemCapacity, -41);
    lv_obj_set_y(ui_MemCapacity, 105);
    lv_obj_set_align(ui_MemCapacity, LV_ALIGN_CENTER);
    lv_label_set_text(ui_MemCapacity, "16GB");
    lv_obj_clear_flag(ui_MemCapacity, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_MemCapacity, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_MemCapacity, &ui_font_ShangShou20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CpuUsagePointer = lv_img_create(ui_PanelMonitorCpu);
    lv_img_set_src(ui_CpuUsagePointer, &ui_img_big_pointer_png);
    lv_obj_set_width(ui_CpuUsagePointer, LV_SIZE_CONTENT);   /// 144
    lv_obj_set_height(ui_CpuUsagePointer, LV_SIZE_CONTENT);    /// 4
    lv_obj_set_x(ui_CpuUsagePointer, -112);
    lv_obj_set_y(ui_CpuUsagePointer, -21);
    lv_obj_set_align(ui_CpuUsagePointer, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_CpuUsagePointer,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_img_set_pivot(ui_CpuUsagePointer, 144, 2);
    lv_img_set_angle(ui_CpuUsagePointer, -180);

    ui_CpuUsagePercent = lv_textarea_create(ui_PanelMonitorCpu);
    lv_obj_set_width(ui_CpuUsagePercent, 150);
    lv_obj_set_height(ui_CpuUsagePercent, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_CpuUsagePercent, -40);
    lv_obj_set_y(ui_CpuUsagePercent, -21);
    lv_obj_set_align(ui_CpuUsagePercent, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_CpuUsagePercent, "--");
    lv_textarea_set_placeholder_text(ui_CpuUsagePercent, "Placeholder...");
    lv_textarea_set_one_line(ui_CpuUsagePercent, true);
    lv_obj_clear_flag(ui_CpuUsagePercent,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_CpuUsagePercent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CpuUsagePercent, &ui_font_ShangShou38, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_CpuUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CpuUsagePercent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CpuUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CpuUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CpuFrequency = lv_textarea_create(ui_PanelMonitorCpu);
    lv_obj_set_width(ui_CpuFrequency, 150);
    lv_obj_set_height(ui_CpuFrequency, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_CpuFrequency, -41);
    lv_obj_set_y(ui_CpuFrequency, 5);
    lv_obj_set_align(ui_CpuFrequency, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_CpuFrequency, "--");
    lv_textarea_set_placeholder_text(ui_CpuFrequency, "Placeholder...");
    lv_textarea_set_one_line(ui_CpuFrequency, true);
    lv_obj_clear_flag(ui_CpuFrequency, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_CpuFrequency, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CpuFrequency, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_CpuFrequency, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CpuFrequency, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CpuFrequency, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CpuFrequency, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MemUsageArc = lv_arc_create(ui_PanelMonitorCpu);
    lv_obj_set_width(ui_MemUsageArc, 295);
    lv_obj_set_height(ui_MemUsageArc, 295);
    lv_obj_set_x(ui_MemUsageArc, -40);
    lv_obj_set_y(ui_MemUsageArc, -16);
    lv_obj_set_align(ui_MemUsageArc, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_MemUsageArc, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_arc_set_value(ui_MemUsageArc, 0);
    lv_arc_set_bg_angles(ui_MemUsageArc, 54, 126);
    lv_arc_set_mode(ui_MemUsageArc, LV_ARC_MODE_REVERSE);
    lv_obj_set_style_arc_img_src(ui_MemUsageArc, &ui_img_mem_usage1_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_img_src(ui_MemUsageArc, &ui_img_mem_usage2_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_MemUsageArc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MemUsageArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_MemUsagePercent = lv_textarea_create(ui_PanelMonitorCpu);
    lv_obj_set_width(ui_MemUsagePercent, 150);
    lv_obj_set_height(ui_MemUsagePercent, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_MemUsagePercent, -40);
    lv_obj_set_y(ui_MemUsagePercent, 69);
    lv_obj_set_align(ui_MemUsagePercent, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_MemUsagePercent, "--");
    lv_textarea_set_placeholder_text(ui_MemUsagePercent, "Placeholder...");
    lv_textarea_set_one_line(ui_MemUsagePercent, true);
    lv_obj_clear_flag(ui_MemUsagePercent,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_MemUsagePercent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_MemUsagePercent, &ui_font_ShangShou28, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_MemUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_MemUsagePercent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MemUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_MemUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CpuTemp = lv_img_create(ui_PanelMonitorCpu);
    lv_img_set_src(ui_CpuTemp, &ui_img_small_pointer_png);
    lv_obj_set_width(ui_CpuTemp, LV_SIZE_CONTENT);   /// 72
    lv_obj_set_height(ui_CpuTemp, LV_SIZE_CONTENT);    /// 5
    lv_obj_set_x(ui_CpuTemp, 91);
    lv_obj_set_y(ui_CpuTemp, -126);
    lv_obj_set_align(ui_CpuTemp, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_CpuTemp, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_img_set_pivot(ui_CpuTemp, 72, 3);
    lv_img_set_angle(ui_CpuTemp, 300);

    ui_PanelMonitorGpu = lv_obj_create(ui_PanelMonitor);
    lv_obj_set_width(ui_PanelMonitorGpu, 391);
    lv_obj_set_height(ui_PanelMonitorGpu, 476);
    lv_obj_set_x(ui_PanelMonitorGpu, 386);
    lv_obj_set_y(ui_PanelMonitorGpu, 29);
    lv_obj_clear_flag(ui_PanelMonitorGpu,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_PanelMonitorGpu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelMonitorGpu, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMonitorGpu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelMonitorGpu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GpuModel = lv_label_create(ui_PanelMonitorGpu);
    lv_obj_set_width(ui_GpuModel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_GpuModel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_GpuModel, 35);
    lv_obj_set_y(ui_GpuModel, -185);
    lv_obj_set_align(ui_GpuModel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_GpuModel, "GTX-1080");
    lv_obj_clear_flag(ui_GpuModel, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_GpuModel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_GpuModel, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GMemCapacity = lv_label_create(ui_PanelMonitorGpu);
    lv_obj_set_width(ui_GMemCapacity, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_GMemCapacity, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_GMemCapacity, 37);
    lv_obj_set_y(ui_GMemCapacity, 106);
    lv_obj_set_align(ui_GMemCapacity, LV_ALIGN_CENTER);
    lv_label_set_text(ui_GMemCapacity, "8GB");
    lv_obj_clear_flag(ui_GMemCapacity, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_GMemCapacity, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_GMemCapacity, &ui_font_ShangShou20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GpuUsagePointer = lv_img_create(ui_PanelMonitorGpu);
    lv_img_set_src(ui_GpuUsagePointer, &ui_img_big_pointer_png);
    lv_obj_set_width(ui_GpuUsagePointer, LV_SIZE_CONTENT);   /// 144
    lv_obj_set_height(ui_GpuUsagePointer, LV_SIZE_CONTENT);    /// 4
    lv_obj_set_x(ui_GpuUsagePointer, -33);
    lv_obj_set_y(ui_GpuUsagePointer, -18);
    lv_obj_set_align(ui_GpuUsagePointer, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_GpuUsagePointer,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_img_set_pivot(ui_GpuUsagePointer, 144, 2);
    lv_img_set_angle(ui_GpuUsagePointer, -180);

    ui_GpuUsagePercent = lv_textarea_create(ui_PanelMonitorGpu);
    lv_obj_set_width(ui_GpuUsagePercent, 150);
    lv_obj_set_height(ui_GpuUsagePercent, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_GpuUsagePercent, 40);
    lv_obj_set_y(ui_GpuUsagePercent, -16);
    lv_obj_set_align(ui_GpuUsagePercent, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_GpuUsagePercent, "--");
    lv_textarea_set_placeholder_text(ui_GpuUsagePercent, "Placeholder...");
    lv_textarea_set_one_line(ui_GpuUsagePercent, true);
    lv_obj_clear_flag(ui_GpuUsagePercent,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_GpuUsagePercent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_GpuUsagePercent, &ui_font_ShangShou38, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_GpuUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_GpuUsagePercent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_GpuUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_GpuUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GpuFrequency = lv_textarea_create(ui_PanelMonitorGpu);
    lv_obj_set_width(ui_GpuFrequency, 150);
    lv_obj_set_height(ui_GpuFrequency, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_GpuFrequency, 38);
    lv_obj_set_y(ui_GpuFrequency, 8);
    lv_obj_set_align(ui_GpuFrequency, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_GpuFrequency, "--");
    lv_textarea_set_placeholder_text(ui_GpuFrequency, "Placeholder...");
    lv_textarea_set_one_line(ui_GpuFrequency, true);
    lv_obj_clear_flag(ui_GpuFrequency, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_GpuFrequency, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_GpuFrequency, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_GpuFrequency, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_GpuFrequency, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_GpuFrequency, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_GpuFrequency, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GMemUsageArc = lv_arc_create(ui_PanelMonitorGpu);
    lv_obj_set_width(ui_GMemUsageArc, 295);
    lv_obj_set_height(ui_GMemUsageArc, 295);
    lv_obj_set_x(ui_GMemUsageArc, 38);
    lv_obj_set_y(ui_GMemUsageArc, -14);
    lv_obj_set_align(ui_GMemUsageArc, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_GMemUsageArc, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_arc_set_value(ui_GMemUsageArc, 0);
    lv_arc_set_bg_angles(ui_GMemUsageArc, 54, 126);
    lv_arc_set_mode(ui_GMemUsageArc, LV_ARC_MODE_REVERSE);
    lv_obj_set_style_arc_img_src(ui_GMemUsageArc, &ui_img_mem_usage1_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_img_src(ui_GMemUsageArc, &ui_img_mem_usage2_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_GMemUsageArc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_GMemUsageArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_GMemUsagePercent = lv_textarea_create(ui_PanelMonitorGpu);
    lv_obj_set_width(ui_GMemUsagePercent, 150);
    lv_obj_set_height(ui_GMemUsagePercent, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_GMemUsagePercent, 40);
    lv_obj_set_y(ui_GMemUsagePercent, 71);
    lv_obj_set_align(ui_GMemUsagePercent, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_GMemUsagePercent, "--");
    lv_textarea_set_placeholder_text(ui_GMemUsagePercent, "Placeholder...");
    lv_textarea_set_one_line(ui_GMemUsagePercent, true);
    lv_obj_clear_flag(ui_GMemUsagePercent,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_GMemUsagePercent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_GMemUsagePercent, &ui_font_ShangShou28, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_GMemUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_GMemUsagePercent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_GMemUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_GMemUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GpuTemp = lv_img_create(ui_PanelMonitorGpu);
    lv_img_set_src(ui_GpuTemp, &ui_img_small_pointer_png);
    lv_obj_set_width(ui_GpuTemp, LV_SIZE_CONTENT);   /// 72
    lv_obj_set_height(ui_GpuTemp, LV_SIZE_CONTENT);    /// 5
    lv_obj_set_x(ui_GpuTemp, -162);
    lv_obj_set_y(ui_GpuTemp, -124);
    lv_obj_set_align(ui_GpuTemp, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_GpuTemp, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_img_set_pivot(ui_GpuTemp, 72, 3);
    lv_img_set_angle(ui_GpuTemp, 300);

    ui_PanelMid = lv_obj_create(ui_PanelMonitor);
    lv_obj_set_width(ui_PanelMid, 250);
    lv_obj_set_height(ui_PanelMid, 480);
    lv_obj_set_x(ui_PanelMid, 0);
    lv_obj_set_y(ui_PanelMid, 45);
    lv_obj_set_align(ui_PanelMid, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelMid, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_PanelMid, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelMid, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMid, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelMid, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Time = lv_textarea_create(ui_PanelMid);
    lv_obj_set_width(ui_Time, 150);
    lv_obj_set_height(ui_Time, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_Time, 1);
    lv_obj_set_y(ui_Time, -38);
    lv_obj_set_align(ui_Time, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Time, "00:00");
    lv_textarea_set_one_line(ui_Time, true);
    lv_obj_clear_flag(ui_Time, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_letter_space(ui_Time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Time, &ui_font_ShangShou40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Time, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Week = lv_textarea_create(ui_PanelMid);
    lv_obj_set_width(ui_Week, 150);
    lv_obj_set_height(ui_Week, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_Week, -1);
    lv_obj_set_y(ui_Week, -1);
    lv_obj_set_align(ui_Week, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Week, "Sun.");
    lv_textarea_set_one_line(ui_Week, true);
    lv_obj_clear_flag(ui_Week, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_letter_space(ui_Week, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Week, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Week, &ui_font_ShangShou32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Week, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Date = lv_textarea_create(ui_PanelMid);
    lv_obj_set_width(ui_Date, 199);
    lv_obj_set_height(ui_Date, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_Date, 2);
    lv_obj_set_y(ui_Date, 36);
    lv_obj_set_align(ui_Date, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Date, "2000.01.01");
    lv_textarea_set_one_line(ui_Date, true);
    lv_obj_clear_flag(ui_Date, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_letter_space(ui_Date, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Date, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Date, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Up = lv_textarea_create(ui_PanelMid);
    lv_obj_set_width(ui_Up, 90);
    lv_obj_set_height(ui_Up, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_Up, -23);
    lv_obj_set_y(ui_Up, 84);
    lv_obj_set_align(ui_Up, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Up, "0.0KB");
    lv_textarea_set_placeholder_text(ui_Up, "Placeholder...");
    lv_textarea_set_one_line(ui_Up, true);
    lv_obj_clear_flag(ui_Up, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_Up, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Up, &ui_font_ShangShou20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Up, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Up, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Up, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Up, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Down = lv_textarea_create(ui_PanelMid);
    lv_obj_set_width(ui_Down, 95);
    lv_obj_set_height(ui_Down, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_Down, 87);
    lv_obj_set_y(ui_Down, 84);
    lv_obj_set_align(ui_Down, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Down, "0.0KB");
    lv_textarea_set_placeholder_text(ui_Down, "Placeholder...");
    lv_textarea_set_one_line(ui_Down, true);
    lv_obj_clear_flag(ui_Down, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_Down, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Down, &ui_font_ShangShou20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Down, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Down, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Down, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Down, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Read = lv_textarea_create(ui_PanelMid);
    lv_obj_set_width(ui_Read, 97);
    lv_obj_set_height(ui_Read, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_Read, -23);
    lv_obj_set_y(ui_Read, 112);
    lv_obj_set_align(ui_Read, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Read, "0.0MB");
    lv_textarea_set_placeholder_text(ui_Read, "Placeholder...");
    lv_textarea_set_one_line(ui_Read, true);
    lv_obj_clear_flag(ui_Read, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_Read, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Read, &ui_font_ShangShou20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Read, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Read, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Read, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Read, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Write = lv_textarea_create(ui_PanelMid);
    lv_obj_set_width(ui_Write, 91);
    lv_obj_set_height(ui_Write, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_Write, 87);
    lv_obj_set_y(ui_Write, 112);
    lv_obj_set_align(ui_Write, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Write, "0.0MB");
    lv_textarea_set_placeholder_text(ui_Write, "Placeholder...");
    lv_textarea_set_one_line(ui_Write, true);
    lv_obj_clear_flag(ui_Write, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_Write, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Write, &ui_font_ShangShou20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Write, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Write, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Write, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Write, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Monitor, ui_event_Monitor, LV_EVENT_ALL, NULL);

}
void ui_Git_screen_init(void)
{
    ui_Git = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Git, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Git, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Git, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ContributionPanel = lv_obj_create(ui_Git);
    lv_obj_set_width(ui_ContributionPanel, 750);
    lv_obj_set_height(ui_ContributionPanel, 142);
    lv_obj_set_x(ui_ContributionPanel, 10);
    lv_obj_set_y(ui_ContributionPanel, 119);
    lv_obj_set_align(ui_ContributionPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ContributionPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ContributionPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_username = lv_textarea_create(ui_Git);
    lv_obj_set_width(ui_username, 150);
    lv_obj_set_height(ui_username, LV_SIZE_CONTENT);    /// 40
    lv_obj_set_x(ui_username, -200);
    lv_obj_set_y(ui_username, -30);
    lv_obj_set_align(ui_username, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_username, "user name");
    lv_textarea_set_one_line(ui_username, true);
    lv_obj_clear_flag(ui_username, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_username, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_username, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_username, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_username, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_username, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_year = lv_dropdown_create(ui_Git);
    lv_dropdown_set_options(ui_year, "2022\n2021\n2020\n2019\n2018\n2017\n2016\n2015");
    lv_obj_set_width(ui_year, 110);
    lv_obj_set_height(ui_year, 40);
    lv_obj_set_x(ui_year, 200);
    lv_obj_set_y(ui_year, -30);
    lv_obj_set_align(ui_year, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_year, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_font(ui_year, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_year, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_year, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_year, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Git_ImgButton2 = lv_imgbtn_create(ui_Git);
    lv_imgbtn_set_src(ui_Git_ImgButton2, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_git_released_png, NULL);
    lv_imgbtn_set_src(ui_Git_ImgButton2, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_git_pressed_png, NULL);
    lv_obj_set_width(ui_Git_ImgButton2, 177);
    lv_obj_set_height(ui_Git_ImgButton2, 177);
    lv_obj_set_x(ui_Git_ImgButton2, 0);
    lv_obj_set_y(ui_Git_ImgButton2, -90);
    lv_obj_set_align(ui_Git_ImgButton2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Git_ImgButton2,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags

    lv_obj_add_event_cb(ui_Git, ui_event_Git, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_year, ui_event_Git, LV_EVENT_ALL, NULL);

}
void ui_Bili_screen_init(void)
{
    ui_Bili = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Bili, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Bili, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bili, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelLikes = lv_label_create(ui_Bili);
    lv_obj_set_width(ui_LabelLikes, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelLikes, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelLikes, 240);
    lv_obj_set_y(ui_LabelLikes, 50);
    lv_obj_set_align(ui_LabelLikes, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelLikes, "Likes");
    lv_obj_set_style_text_letter_space(ui_LabelLikes, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_LabelLikes, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelLikes, &ui_font_ShangShou28, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFollowers = lv_label_create(ui_Bili);
    lv_obj_set_width(ui_LabelFollowers, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelFollowers, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelFollowers, 0);
    lv_obj_set_y(ui_LabelFollowers, 50);
    lv_obj_set_align(ui_LabelFollowers, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelFollowers, "Followers");
    lv_obj_set_style_text_letter_space(ui_LabelFollowers, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_LabelFollowers, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFollowers, &ui_font_ShangShou28, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelViews = lv_label_create(ui_Bili);
    lv_obj_set_width(ui_LabelViews, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelViews, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelViews, -240);
    lv_obj_set_y(ui_LabelViews, 50);
    lv_obj_set_align(ui_LabelViews, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelViews, "Views");
    lv_obj_set_style_text_letter_space(ui_LabelViews, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_LabelViews, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelViews, &ui_font_ShangShou28, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_views = lv_label_create(ui_Bili);
    lv_obj_set_width(ui_views, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_views, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_views, -240);
    lv_obj_set_y(ui_views, 130);
    lv_obj_set_align(ui_views, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_views, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_views, "");
    lv_obj_clear_flag(ui_views, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_views, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_views, &ui_font_ShangShou32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_followers = lv_label_create(ui_Bili);
    lv_obj_set_width(ui_followers, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_followers, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_followers, 0);
    lv_obj_set_y(ui_followers, 130);
    lv_obj_set_align(ui_followers, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_followers, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_followers, "");
    lv_obj_clear_flag(ui_followers, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_followers, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_followers, &ui_font_ShangShou32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_likes = lv_label_create(ui_Bili);
    lv_obj_set_width(ui_likes, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_likes, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_likes, 240);
    lv_obj_set_y(ui_likes, 130);
    lv_obj_set_align(ui_likes, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_likes, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_likes, "");
    lv_obj_clear_flag(ui_likes, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_likes, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_likes, &ui_font_ShangShou32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_nickname = lv_textarea_create(ui_Bili);
    lv_obj_set_width(ui_nickname, 150);
    lv_obj_set_height(ui_nickname, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_nickname, -240);
    lv_obj_set_y(ui_nickname, -30);
    lv_obj_set_align(ui_nickname, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_nickname, "nickname");
    lv_textarea_set_one_line(ui_nickname, true);
    lv_obj_clear_flag(ui_nickname, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_nickname, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_nickname, &ui_font_ShangShou20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_nickname, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_nickname, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_nickname, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_userid = lv_textarea_create(ui_Bili);
    lv_obj_set_width(ui_userid, 150);
    lv_obj_set_height(ui_userid, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_userid, 240);
    lv_obj_set_y(ui_userid, -30);
    lv_obj_set_align(ui_userid, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_userid, "userid");
    lv_textarea_set_one_line(ui_userid, true);
    lv_obj_clear_flag(ui_userid, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_userid, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_userid, &ui_font_ShangShou20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_userid, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_userid, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_userid, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Bili_ImgButton3 = lv_imgbtn_create(ui_Bili);
    lv_imgbtn_set_src(ui_Bili_ImgButton3, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_bili_released_png, NULL);
    lv_imgbtn_set_src(ui_Bili_ImgButton3, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_bili_pressed_png, NULL);
    lv_obj_set_height(ui_Bili_ImgButton3, 156);
    lv_obj_set_width(ui_Bili_ImgButton3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_Bili_ImgButton3, 0);
    lv_obj_set_y(ui_Bili_ImgButton3, -90);
    lv_obj_set_align(ui_Bili_ImgButton3, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Bili, ui_event_Bili, LV_EVENT_ALL, NULL);
}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Monitor_screen_init();
    ui_Git_screen_init();
    ui_Bili_screen_init();
    lv_disp_load_scr(ui_Monitor);
}
