// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: DesktopBox

#include "ui.h"
#include "ui_helpers.h"
#include "ui_controller.h"
#include "config.h"
#include <stdio.h>
#include <time.h>

///////////////////// VARIABLES ////////////////////
extern bool git_updating;
extern time_t git_last_update_time;
extern bool bili_updating;
extern time_t bili_last_update_relation;
extern time_t bili_last_update_stat;

// screen monitor
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

// screen git
void ui_event_Git(lv_event_t * e);
lv_obj_t * ui_Git;
lv_obj_t * ui_TextGitUserName;
lv_obj_t * ui_year;
lv_obj_t * ui_ContributionPanel;
lv_obj_t * ui_Git_ImgButtonLogo;
lv_obj_t * ui_Git_Slider_Loading;

// screen bili
void ui_event_Bili(lv_event_t * e);
lv_obj_t * ui_Bili;
lv_obj_t * ui_TextBiliUserName;
lv_obj_t * ui_TextBiliUserID;
lv_obj_t * ui_ImageFollower;
lv_obj_t * ui_ImageLike;
lv_obj_t * ui_ImageCoin;
lv_obj_t * ui_ImageFavorite;
lv_obj_t * ui_TextFollower;
lv_obj_t * ui_TextLike;
lv_obj_t * ui_TextCoin;
lv_obj_t * ui_TextFavorite;
lv_obj_t * ui_Bili_ImgButtonLogo;
lv_obj_t * ui_Bili_Slider_Loading;

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

void StartLoading_Animation(lv_obj_t * TargetObject, int v1, int v2, int time)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_exec_cb(&PropertyAnimation_0, (lv_anim_exec_xcb_t)_ui_slider_set_value);
    lv_anim_set_var(&PropertyAnimation_0, TargetObject);
    lv_anim_set_time(&PropertyAnimation_0, time);
    lv_anim_set_values(&PropertyAnimation_0, v1, v2);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
}

void kb_event_cb(lv_event_t * e)
{
    int ret = 0;
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = lv_event_get_user_data(e);
    if(code == LV_EVENT_LONG_PRESSED) {
        lv_keyboard_set_textarea(kb, ta);
        lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
        if (ta == ui_TextGitUserName) {
            git_stop_update();
        } else if (ta == ui_TextBiliUserName) {
            bili_stop_update();
        }
    }
    if(code == LV_EVENT_DEFOCUSED) {
        
    }
    if (code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        //lv_event_send(ta, LV_EVENT_DEFOCUSED, NULL);
        const char *input = lv_textarea_get_text(ta);
        if (ta == ui_TextGitUserName) {
            if (ui_git_check_username(input)) {
                ret = 1;
            } else {
                config_set_git_username(input);
                git_reset();
            }
        } else if (ta == ui_TextBiliUserName) {
            if (ui_bili_check_userid(input)) {
                ret = 1;
            } else {
                config_set_bili_userid(input);
                bili_reset();
            }
        }
        if (!ret) {
            lv_keyboard_set_textarea(kb, NULL);
            lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
            lv_indev_reset(NULL, ta);
        }
    }
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
    lv_obj_clear_flag(ui_PanelMonitor, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
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
    lv_textarea_set_placeholder_text(ui_CpuUsagePercent, "");
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
    lv_textarea_set_placeholder_text(ui_CpuFrequency, "");
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
    lv_textarea_set_placeholder_text(ui_MemUsagePercent, "");
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
    lv_textarea_set_placeholder_text(ui_GpuUsagePercent, "");
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
    lv_textarea_set_placeholder_text(ui_GpuFrequency, "");
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
    lv_textarea_set_placeholder_text(ui_GMemUsagePercent, "");
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
    lv_textarea_set_placeholder_text(ui_Up, "");
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
    lv_textarea_set_placeholder_text(ui_Down, "");
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
    lv_textarea_set_placeholder_text(ui_Read, "");
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
    lv_textarea_set_placeholder_text(ui_Write, "");
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
    lv_obj_add_flag(ui_Git, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Git, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Git, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextGitUserName = lv_textarea_create(ui_Git);
    lv_obj_set_width(ui_TextGitUserName, 200);
    lv_obj_set_height(ui_TextGitUserName, LV_SIZE_CONTENT);    /// 40
    lv_obj_set_x(ui_TextGitUserName, -240);
    lv_obj_set_y(ui_TextGitUserName, -30);
    lv_obj_set_align(ui_TextGitUserName, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextGitUserName, "");
    lv_textarea_set_placeholder_text(ui_TextGitUserName, "Input Username");
    lv_textarea_set_one_line(ui_TextGitUserName, true);
    lv_obj_add_flag(ui_TextGitUserName, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_EVENT_BUBBLE);     /// Flags
    lv_obj_set_style_text_align(ui_TextGitUserName, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextGitUserName, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TextGitUserName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TextGitUserName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_TextGitUserName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_year = lv_dropdown_create(ui_Git);
    lv_dropdown_set_options(ui_year, "2023\n");
    lv_obj_set_width(ui_year, 150);
    lv_obj_set_height(ui_year, 40);
    lv_obj_set_x(ui_year, 240);
    lv_obj_set_y(ui_year, -30);
    lv_obj_set_align(ui_year, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_year, LV_OBJ_FLAG_EVENT_BUBBLE);     /// Flags
    lv_obj_set_style_text_font(ui_year, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_year, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_year, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_year, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ContributionPanel = lv_obj_create(ui_Git);
    lv_obj_set_width(ui_ContributionPanel, 750);
    lv_obj_set_height(ui_ContributionPanel, 105);
    lv_obj_set_x(ui_ContributionPanel, 0);
    lv_obj_set_y(ui_ContributionPanel, 100);
    lv_obj_set_align(ui_ContributionPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ContributionPanel, LV_OBJ_FLAG_SCROLLABLE);        // Flags
    lv_obj_add_flag(ui_ContributionPanel, LV_OBJ_FLAG_CLICKABLE);           // Flags
    lv_obj_set_style_radius(ui_ContributionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(ui_ContributionPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ContributionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ContributionPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Git_ImgButtonLogo = lv_imgbtn_create(ui_Git);
    lv_imgbtn_set_src(ui_Git_ImgButtonLogo, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_git_released_png, NULL);
    lv_imgbtn_set_src(ui_Git_ImgButtonLogo, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_git_pressed_png, NULL);
    lv_obj_set_width(ui_Git_ImgButtonLogo, 177);
    lv_obj_set_height(ui_Git_ImgButtonLogo, 177);
    lv_obj_set_x(ui_Git_ImgButtonLogo, 0);
    lv_obj_set_y(ui_Git_ImgButtonLogo, -90);
    lv_obj_set_align(ui_Git_ImgButtonLogo, LV_ALIGN_CENTER);
    //lv_obj_clear_flag(ui_Git_ImgButtonLogo, );     /// Flags

    ui_Git_Slider_Loading = lv_slider_create(ui_Git);
    lv_obj_set_width(ui_Git_Slider_Loading, 177);
    lv_obj_set_height(ui_Git_Slider_Loading, 178);
    lv_obj_set_x(ui_Git_Slider_Loading, 0);
    lv_obj_set_y(ui_Git_Slider_Loading, -90);
    lv_obj_set_align(ui_Git_Slider_Loading, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Git_Slider_Loading, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_set_style_radius(ui_Git_Slider_Loading, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Git_Slider_Loading, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Git_Slider_Loading, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Git_Slider_Loading, &ui_img_git_released_loading_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Git_Slider_Loading, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Git_Slider_Loading, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Git_Slider_Loading, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Git_Slider_Loading, &ui_img_git_released_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Git_Slider_Loading, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Git_Slider_Loading, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Git_Slider_Loading, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Git, ui_event_Git, LV_EVENT_ALL, NULL);
}

void ui_Bili_screen_init(void)
{
    ui_Bili = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Bili, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Bili, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bili, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextBiliUserID = lv_textarea_create(ui_Bili);
    lv_obj_set_width(ui_TextBiliUserID, 203);
    lv_obj_set_height(ui_TextBiliUserID, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_TextBiliUserID, -295);
    lv_obj_set_y(ui_TextBiliUserID, -217);
    lv_obj_set_align(ui_TextBiliUserID, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_TextBiliUserID, 128);
    lv_textarea_set_text(ui_TextBiliUserID, "");
    lv_textarea_set_placeholder_text(ui_TextBiliUserID, "UserID");
    lv_textarea_set_one_line(ui_TextBiliUserID, true);
    lv_obj_clear_flag(ui_TextBiliUserID, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scrollbar_mode(ui_TextBiliUserID, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_color(ui_TextBiliUserID, lv_color_hex(0x3B3B3B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TextBiliUserID, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TextBiliUserID, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextBiliUserID, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TextBiliUserID, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TextBiliUserID, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_TextBiliUserID, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextBiliUserName = lv_textarea_create(ui_Bili);
    lv_obj_set_width(ui_TextBiliUserName, 237);
    lv_obj_set_height(ui_TextBiliUserName, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_TextBiliUserName, -240);
    lv_obj_set_y(ui_TextBiliUserName, -72);
    lv_obj_set_align(ui_TextBiliUserName, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_TextBiliUserName, 128);
    lv_textarea_set_text(ui_TextBiliUserName, "");
    lv_textarea_set_placeholder_text(ui_TextBiliUserName, "Input UserID");
    lv_textarea_set_one_line(ui_TextBiliUserName, true);
    lv_obj_add_flag(ui_TextBiliUserName, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_EVENT_BUBBLE);     /// Flags
    //lv_obj_clear_flag(ui_TextBiliUserName, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_set_style_text_letter_space(ui_TextBiliUserName, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_TextBiliUserName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TextBiliUserName, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextBiliUserName, &ui_font_ShangShou32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TextBiliUserName, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TextBiliUserName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_TextBiliUserName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_ImageFollower = lv_img_create(ui_Bili);
    lv_img_set_src(ui_ImageFollower, &ui_img_follower_png);
    lv_obj_set_width(ui_ImageFollower, LV_SIZE_CONTENT);   /// 46
    lv_obj_set_height(ui_ImageFollower, LV_SIZE_CONTENT);    /// 48
    lv_obj_set_x(ui_ImageFollower, 240);
    lv_obj_set_y(ui_ImageFollower, -111);
    lv_obj_set_align(ui_ImageFollower, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageFollower, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageFollower, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImageCoin = lv_img_create(ui_Bili);
    lv_img_set_src(ui_ImageCoin, &ui_img_coin_png);
    lv_obj_set_width(ui_ImageCoin, 48);
    lv_obj_set_height(ui_ImageCoin, 48);
    lv_obj_set_x(ui_ImageCoin, 0);
    lv_obj_set_y(ui_ImageCoin, 60);
    lv_obj_set_align(ui_ImageCoin, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageCoin, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageCoin, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImageLike = lv_img_create(ui_Bili);
    lv_img_set_src(ui_ImageLike, &ui_img_like_png);
    lv_obj_set_width(ui_ImageLike, 48);
    lv_obj_set_height(ui_ImageLike, 48);
    lv_obj_set_x(ui_ImageLike, -240);
    lv_obj_set_y(ui_ImageLike, 60);
    lv_obj_set_align(ui_ImageLike, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageLike, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageLike, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImageFavorite = lv_img_create(ui_Bili);
    lv_img_set_src(ui_ImageFavorite, &ui_img_favorite_png);
    lv_obj_set_width(ui_ImageFavorite, 48);
    lv_obj_set_height(ui_ImageFavorite, 48);
    lv_obj_set_x(ui_ImageFavorite, 240);
    lv_obj_set_y(ui_ImageFavorite, 60);
    lv_obj_set_align(ui_ImageFavorite, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageFavorite, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageFavorite, LV_OBJ_FLAG_SCROLLABLE);      /// Flags



    ui_TextFollower = lv_textarea_create(ui_Bili);
    lv_obj_set_width(ui_TextFollower, 220);
    lv_obj_set_height(ui_TextFollower, LV_SIZE_CONTENT);    /// 49
    lv_obj_set_x(ui_TextFollower, 240);
    lv_obj_set_y(ui_TextFollower, -42);
    lv_obj_set_align(ui_TextFollower, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextFollower, "");
    lv_textarea_set_placeholder_text(ui_TextFollower, "");
    lv_textarea_set_one_line(ui_TextFollower, true);
    lv_obj_add_flag(ui_TextFollower, LV_OBJ_FLAG_EVENT_BUBBLE);     /// Flags
    lv_obj_clear_flag(ui_TextFollower, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_TextFollower, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextFollower, &ui_font_ShangShou32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TextFollower, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TextFollower, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_TextFollower, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextLike = lv_textarea_create(ui_Bili);
    lv_obj_set_width(ui_TextLike, 220);
    lv_obj_set_height(ui_TextLike, LV_SIZE_CONTENT);    /// 49
    lv_obj_set_x(ui_TextLike, -240);
    lv_obj_set_y(ui_TextLike, 130);
    lv_obj_set_align(ui_TextLike, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextLike, "");
    lv_textarea_set_placeholder_text(ui_TextLike, "");
    lv_textarea_set_one_line(ui_TextLike, true);
    lv_obj_add_flag(ui_TextLike, LV_OBJ_FLAG_EVENT_BUBBLE);     /// Flags
    lv_obj_clear_flag(ui_TextLike, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_TextLike, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextLike, &ui_font_ShangShou32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TextLike, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TextLike, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_TextLike, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextCoin = lv_textarea_create(ui_Bili);
    lv_obj_set_width(ui_TextCoin, 220);
    lv_obj_set_height(ui_TextCoin, LV_SIZE_CONTENT);    /// 49
    lv_obj_set_x(ui_TextCoin, 0);
    lv_obj_set_y(ui_TextCoin, 130);
    lv_obj_set_align(ui_TextCoin, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextCoin, "");
    lv_textarea_set_placeholder_text(ui_TextCoin, "");
    lv_textarea_set_one_line(ui_TextCoin, true);
    lv_obj_add_flag(ui_TextCoin, LV_OBJ_FLAG_EVENT_BUBBLE);     /// Flags
    lv_obj_clear_flag(ui_TextCoin, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_TextCoin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextCoin, &ui_font_ShangShou32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TextCoin, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TextCoin, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_TextCoin, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextFavorite = lv_textarea_create(ui_Bili);
    lv_obj_set_width(ui_TextFavorite, 220);
    lv_obj_set_height(ui_TextFavorite, LV_SIZE_CONTENT);    /// 49
    lv_obj_set_x(ui_TextFavorite, 240);
    lv_obj_set_y(ui_TextFavorite, 130);
    lv_obj_set_align(ui_TextFavorite, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextFavorite, "");
    lv_textarea_set_placeholder_text(ui_TextFavorite, "");
    lv_textarea_set_one_line(ui_TextFavorite, true);
    lv_obj_add_flag(ui_TextFavorite, LV_OBJ_FLAG_EVENT_BUBBLE);     /// Flags
    lv_obj_clear_flag(ui_TextFavorite, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_align(ui_TextFavorite, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextFavorite, &ui_font_ShangShou32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TextFavorite, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TextFavorite, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_TextFavorite, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_Bili_ImgButtonLogo = lv_imgbtn_create(ui_Bili);
    lv_imgbtn_set_src(ui_Bili_ImgButtonLogo, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_bili_released_png, NULL);
    lv_imgbtn_set_src(ui_Bili_ImgButtonLogo, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_bili_pressed_png, NULL);
    lv_obj_set_width(ui_Bili_ImgButtonLogo, 160);
    lv_obj_set_height(ui_Bili_ImgButtonLogo, 161);
    lv_obj_set_x(ui_Bili_ImgButtonLogo, 0);
    lv_obj_set_y(ui_Bili_ImgButtonLogo, -90);
    lv_obj_set_align(ui_Bili_ImgButtonLogo, LV_ALIGN_CENTER);

    ui_Bili_Slider_Loading = lv_slider_create(ui_Bili);
    lv_obj_set_width(ui_Bili_Slider_Loading, 160);
    lv_obj_set_height(ui_Bili_Slider_Loading, 161);
    lv_obj_set_x(ui_Bili_Slider_Loading, 0);
    lv_obj_set_y(ui_Bili_Slider_Loading, -90);
    lv_obj_set_align(ui_Bili_Slider_Loading, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Bili_Slider_Loading, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_Bili_Slider_Loading, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bili_Slider_Loading, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bili_Slider_Loading, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Bili_Slider_Loading, &ui_img_bili_released_loading_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Bili_Slider_Loading, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bili_Slider_Loading, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bili_Slider_Loading, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Bili_Slider_Loading, &ui_img_bili_released_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Bili_Slider_Loading, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bili_Slider_Loading, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bili_Slider_Loading, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

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
