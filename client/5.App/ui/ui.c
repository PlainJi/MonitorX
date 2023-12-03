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
static lv_style_t style_my_font;
extern bool git_updating;
extern time_t git_last_update_time;
extern bool bili_updating;
extern time_t bili_last_update_relation;
extern time_t bili_last_update_stat;

// screen monitor
lv_obj_t * ui_Monitor;
lv_obj_t * ui_PanelMonitor;
lv_obj_t * ui_PanelDisconnect;
lv_obj_t * ui_ArcDisconnect;
lv_obj_t * ui_TextDisconnect;
lv_anim_t * ui_AnimDisconnect;
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
lv_obj_t * ui_TextGitJan;
lv_obj_t * ui_TextGitJan;
lv_obj_t * ui_TextGitFeb;
lv_obj_t * ui_TextGitMar;
lv_obj_t * ui_TextGitApr;
lv_obj_t * ui_TextGitMay;
lv_obj_t * ui_TextGitJun;
lv_obj_t * ui_TextGitJul;
lv_obj_t * ui_TextGitAug;
lv_obj_t * ui_TextGitSep;
lv_obj_t * ui_TextGitOct;
lv_obj_t * ui_TextGitNov;
lv_obj_t * ui_TextGitDec;
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

// screen tomato
void ui_event_Tomato(lv_event_t * e);
lv_obj_t * ui_Tomato;
lv_obj_t * ui_meter;
lv_meter_scale_t * ui_scale;
lv_meter_scale_t * ui_scale_num;
lv_meter_indicator_t * ui_indic_pointer;
lv_meter_indicator_t * ui_indic_pie;
lv_obj_t * ui_ArcTomato;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void ui_InitAnimationForPointer(lv_obj_t *TargetObject, int start, int stop) {
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, start, stop);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, 0);
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
    lv_anim_set_values(&PropertyAnimation_1, stop, start);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_1, 1000);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);
}

void ui_InitAnimationForArc(lv_obj_t *TargetObject, int start, int stop) {
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_arc);
    lv_anim_set_values(&PropertyAnimation_0, start, stop);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, 0);
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
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_arc);
    lv_anim_set_values(&PropertyAnimation_1, stop, start);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_1, 1000);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);
}

void ui_AnimationForPointer(lv_obj_t * TargetObject, int new_angle, int time)
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

void ui_AnimationForArc(lv_obj_t * TargetObject, int new_angle, int time)
{
	lv_anim_t PropertyAnimation_0;
	lv_anim_init(&PropertyAnimation_0);
	lv_anim_set_time(&PropertyAnimation_0, time);
	lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
	lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_arc);
	int start = (int)lv_arc_get_value(TargetObject);
	if (start > 100) start = 100;
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

void ui_Loading_Animation(lv_obj_t * TargetObject, int v1, int v2, int time)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_slider_set_value);
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

void ui_AnimationForDisconnectStart(void) {
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_user_data(&a, ui_ArcDisconnect);
    lv_anim_set_custom_exec_cb(&a, _ui_anim_callback_set_arc);
    lv_anim_set_time(&a, 1000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_values(&a, 0, 100);
    ui_AnimDisconnect = lv_anim_start(&a);
}

void ui_AnimationForDisconnectStop(void) {
    lv_anim_del(ui_AnimDisconnect, NULL);
}

///////////////////// Event ////////////////////

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

    if (code == LV_EVENT_READY) {
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
            lv_obj_clear_state(ta, LV_STATE_ANY);
            lv_indev_reset(NULL, ta);
        }
    } else if (code == LV_EVENT_CANCEL) {
        if (ta == ui_TextGitUserName) {
            lv_textarea_set_text(ui_TextGitUserName, conf.git_username);
            git_start_update();
        } else if (ta == ui_TextBiliUserName) {
            bili_start_update();
        }
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_state(ta, LV_STATE_ANY);
        lv_indev_reset(NULL, ta);
    }
}

void ui_event_Monitor(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);

    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        _ui_screen_change(ui_Git, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Tomato, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
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
        _ui_screen_change(ui_Tomato, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Git, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}

void ui_event_Tomato(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        _ui_screen_change(ui_Monitor, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Bili, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}

//////////////////////////////////////////// SCREENS ///////////////////////////////////////////////////////
void ui_Monitor_screen_init(void)
{
    ui_Monitor = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Monitor, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_Monitor, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

    // display disconnection by icon
    // ui_Disconnect = lv_img_create(ui_Monitor);
    // lv_img_set_src(ui_Disconnect, &ui_img_disconnect_png_48);
    // lv_obj_set_align(ui_Disconnect, LV_ALIGN_CENTER);

    // display disconnection by spinning arc
    // Panel Disconnect
    ui_creat_panel(ui_Monitor, &ui_PanelDisconnect, 0, 0, 800, 480);
    ui_creat_text_area(ui_PanelDisconnect, &ui_TextDisconnect, 0, 100, LV_SIZE_CONTENT, "Disconnect", "", &ui_font_ShangShou20);
    lv_obj_set_style_text_letter_space(ui_TextDisconnect, 2, 0);
    ui_ArcDisconnect = lv_arc_create(ui_PanelDisconnect);
    lv_obj_set_width(ui_ArcDisconnect, 100);
    lv_obj_set_height(ui_ArcDisconnect, 100);
    lv_arc_set_rotation(ui_ArcDisconnect, 270);
    lv_arc_set_bg_angles(ui_ArcDisconnect, 0, 360);
    lv_obj_remove_style(ui_ArcDisconnect, NULL, LV_PART_KNOB);
    lv_obj_clear_flag(ui_ArcDisconnect, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_center(ui_ArcDisconnect);

    // Panel Monitor
    ui_creat_panel(ui_Monitor, &ui_PanelMonitor, 0, -20, 800, 480);
    lv_obj_set_style_bg_img_src(ui_PanelMonitor, &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelMonitor, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ///////////////////////////////////////////////
    ui_creat_panel(ui_PanelMonitor, &ui_PanelMonitorCpu, -199, 48, 391, 476);
    ui_creat_text_area(ui_PanelMonitorCpu, &ui_CpuModel,        -40, -185, LV_SIZE_CONTENT, "CPU", "", &ui_font_ShangShou24);
    ui_creat_text_area(ui_PanelMonitorCpu, &ui_CpuUsagePercent, -40, -21, 150, "--", "", &ui_font_ShangShou38);
    ui_creat_text_area(ui_PanelMonitorCpu, &ui_CpuFrequency,    -40, 5, 150, "--", "", &ui_font_ShangShou20);
    ui_creat_text_area(ui_PanelMonitorCpu, &ui_MemUsagePercent, -40, 69, 150, "--", "", &ui_font_ShangShou28);
    ui_creat_text_area(ui_PanelMonitorCpu, &ui_MemCapacity,     -43, 105, 150, "--", "", &ui_font_ShangShou20);

    ui_CpuUsagePointer = lv_img_create(ui_PanelMonitorCpu);
    lv_img_set_src(ui_CpuUsagePointer, &ui_img_big_pointer_png);
    lv_obj_set_width(ui_CpuUsagePointer, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CpuUsagePointer, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_CpuUsagePointer, -114);
    lv_obj_set_y(ui_CpuUsagePointer, -18);
    lv_obj_set_align(ui_CpuUsagePointer, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_CpuUsagePointer,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);
    lv_img_set_pivot(ui_CpuUsagePointer, 144, 2);
    lv_img_set_angle(ui_CpuUsagePointer, -180);

    ui_MemUsageArc = lv_arc_create(ui_PanelMonitorCpu);
    lv_obj_set_width(ui_MemUsageArc, 295);
    lv_obj_set_height(ui_MemUsageArc, 295);
    lv_obj_set_x(ui_MemUsageArc, -40);
    lv_obj_set_y(ui_MemUsageArc, -16);
    lv_obj_set_align(ui_MemUsageArc, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_MemUsageArc, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);
    lv_arc_set_value(ui_MemUsageArc, 0);
    lv_arc_set_bg_angles(ui_MemUsageArc, 54, 126);
    lv_arc_set_mode(ui_MemUsageArc, LV_ARC_MODE_REVERSE);
    lv_obj_set_style_arc_img_src(ui_MemUsageArc, &ui_img_mem_usage1_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_img_src(ui_MemUsageArc, &ui_img_mem_usage2_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_MemUsageArc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MemUsageArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);    

    ui_CpuTemp = lv_img_create(ui_PanelMonitorCpu);
    lv_img_set_src(ui_CpuTemp, &ui_img_small_pointer_png);
    lv_obj_set_width(ui_CpuTemp, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CpuTemp, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_CpuTemp, 91);
    lv_obj_set_y(ui_CpuTemp, -126);
    lv_obj_set_align(ui_CpuTemp, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_CpuTemp, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);
    lv_img_set_pivot(ui_CpuTemp, 72, 3);
    lv_img_set_angle(ui_CpuTemp, 300);

    ///////////////////////////////////////////////
    ui_creat_panel(ui_PanelMonitor, &ui_PanelMonitorGpu, 200, 47, 391, 476);
    ui_creat_text_area(ui_PanelMonitorGpu, &ui_GpuModel,        40, -185, LV_SIZE_CONTENT, "GPU", "", &ui_font_ShangShou24);
    ui_creat_text_area(ui_PanelMonitorGpu, &ui_GpuUsagePercent, 40, -16, 150, "--", "", &ui_font_ShangShou38);
    ui_creat_text_area(ui_PanelMonitorGpu, &ui_GpuFrequency,    40, 8, 150, "--", "", &ui_font_ShangShou20);
    ui_creat_text_area(ui_PanelMonitorGpu, &ui_GMemUsagePercent, 40, 71, 150, "--", "", &ui_font_ShangShou28);
    ui_creat_text_area(ui_PanelMonitorGpu, &ui_GMemCapacity,    40, 106, LV_SIZE_CONTENT, "--", "", &ui_font_ShangShou20);

    ui_GpuUsagePointer = lv_img_create(ui_PanelMonitorGpu);
    lv_img_set_src(ui_GpuUsagePointer, &ui_img_big_pointer_png);
    lv_obj_set_width(ui_GpuUsagePointer, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_GpuUsagePointer, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_GpuUsagePointer, -33);
    lv_obj_set_y(ui_GpuUsagePointer, -18);
    lv_obj_set_align(ui_GpuUsagePointer, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_GpuUsagePointer,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);
    lv_img_set_pivot(ui_GpuUsagePointer, 144, 2);
    lv_img_set_angle(ui_GpuUsagePointer, -180);

    ui_GMemUsageArc = lv_arc_create(ui_PanelMonitorGpu);
    lv_obj_set_width(ui_GMemUsageArc, 295);
    lv_obj_set_height(ui_GMemUsageArc, 295);
    lv_obj_set_x(ui_GMemUsageArc, 38);
    lv_obj_set_y(ui_GMemUsageArc, -14);
    lv_obj_set_align(ui_GMemUsageArc, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_GMemUsageArc, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);
    lv_arc_set_value(ui_GMemUsageArc, 0);
    lv_arc_set_bg_angles(ui_GMemUsageArc, 54, 126);
    lv_arc_set_mode(ui_GMemUsageArc, LV_ARC_MODE_REVERSE);
    lv_obj_set_style_arc_img_src(ui_GMemUsageArc, &ui_img_mem_usage1_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_img_src(ui_GMemUsageArc, &ui_img_mem_usage2_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_GMemUsageArc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_GMemUsageArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_GpuTemp = lv_img_create(ui_PanelMonitorGpu);
    lv_img_set_src(ui_GpuTemp, &ui_img_small_pointer_png);
    lv_obj_set_width(ui_GpuTemp, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_GpuTemp, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_GpuTemp, -162);
    lv_obj_set_y(ui_GpuTemp, -124);
    lv_obj_set_align(ui_GpuTemp, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_GpuTemp, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);
    lv_img_set_pivot(ui_GpuTemp, 72, 3);
    lv_img_set_angle(ui_GpuTemp, 300);

    ///////////////////////////////////////////////
    ui_creat_panel(ui_PanelMonitor, &ui_PanelMid, 0, 45, 250, 480);
    ui_creat_text_area(ui_PanelMid, &ui_Time,   1, -38, 150, "", "", &ui_font_ShangShou40);
    ui_creat_text_area(ui_PanelMid, &ui_Week,   1, -1, 150, "", "", &ui_font_ShangShou32);
    ui_creat_text_area(ui_PanelMid, &ui_Date,   2, 36, 200, "", "", &ui_font_ShangShou24);
    ui_creat_text_area(ui_PanelMid, &ui_Up,   -30, 86, 90, "0KB", "", &ui_font_ShangShou20);
    ui_creat_text_area(ui_PanelMid, &ui_Down,  78, 86, 90, "0KB", "", &ui_font_ShangShou20);
    ui_creat_text_area(ui_PanelMid, &ui_Read, -30, 114, 90, "0KB", "", &ui_font_ShangShou20);
    ui_creat_text_area(ui_PanelMid, &ui_Write, 78, 114, 90, "0KB", "", &ui_font_ShangShou20);
    lv_obj_set_style_text_align(ui_Up, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Down, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Read, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Write, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Monitor, ui_event_Monitor, LV_EVENT_ALL, NULL);
}


void ui_Git_screen_init(void)
{
    ui_Git = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Git, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_Git, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Git, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Git, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_creat_text_area(ui_Git, &ui_TextGitUserName, -240, -30, 250, " ", "Input Username", &ui_font_ShangShou32);
    lv_obj_add_flag(ui_TextGitUserName, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_set_style_text_letter_space(ui_TextGitUserName, 3, 0);

    ui_year = lv_dropdown_create(ui_Git);
    lv_dropdown_set_options(ui_year, "2023\n");
    lv_obj_set_width(ui_year, 150);
    lv_obj_set_height(ui_year, 40);
    lv_obj_set_x(ui_year, 240);
    lv_obj_set_y(ui_year, -30);
    lv_obj_set_align(ui_year, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_year, LV_OBJ_FLAG_EVENT_BUBBLE);     /// Flags
    lv_obj_set_style_text_font(ui_year, &ui_font_ShangShou32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_year, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_year, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_year, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_creat_panel(ui_Git, &ui_ContributionPanel, 0, 100, 750, 105);

    double pos = -360;
    ui_creat_label(ui_Git, &ui_TextGitJan, (int)pos, 40, 50, "Jan", &ui_font_ShangShou14);
    pos += ((357+360)/12.0 + 2);
    ui_creat_label(ui_Git, &ui_TextGitFeb, (int)pos, 40, 50, "Feb", &ui_font_ShangShou14);
    pos += ((357+360)/12.0 + 2);
    ui_creat_label(ui_Git, &ui_TextGitMar, (int)pos, 40, 50, "Mar", &ui_font_ShangShou14);
    pos += ((357+360)/12.0 + 2);
    ui_creat_label(ui_Git, &ui_TextGitApr, (int)pos, 40, 50, "Apr", &ui_font_ShangShou14);
    pos += ((357+360)/12.0 + 2);
    ui_creat_label(ui_Git, &ui_TextGitMay, (int)pos, 40, 50, "May", &ui_font_ShangShou14);
    pos += ((357+360)/12.0 + 2);
    ui_creat_label(ui_Git, &ui_TextGitJun, (int)pos, 40, 50, "Jun", &ui_font_ShangShou14);
    pos += ((357+360)/12.0 + 2);
    ui_creat_label(ui_Git, &ui_TextGitJul, (int)pos, 40, 50, "Jul", &ui_font_ShangShou14);
    pos += ((357+360)/12.0 + 2);
    ui_creat_label(ui_Git, &ui_TextGitAug, (int)pos, 40, 50, "Aug", &ui_font_ShangShou14);
    pos += ((357+360)/12.0 + 2);
    ui_creat_label(ui_Git, &ui_TextGitSep, (int)pos, 40, 50, "Sep", &ui_font_ShangShou14);
    pos += ((357+360)/12.0 + 2);
    ui_creat_label(ui_Git, &ui_TextGitOct, (int)pos, 40, 50, "Oct", &ui_font_ShangShou14);
    pos += ((357+360)/12.0 + 2);
    ui_creat_label(ui_Git, &ui_TextGitNov, (int)pos, 40, 50, "Nor", &ui_font_ShangShou14);
    pos += ((357+360)/12.0 + 2);
    ui_creat_label(ui_Git, &ui_TextGitDec, (int)pos, 40, 50, "Dec", &ui_font_ShangShou14);

    ui_Git_ImgButtonLogo = lv_imgbtn_create(ui_Git);
    lv_imgbtn_set_src(ui_Git_ImgButtonLogo, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_git_released_png, NULL);
    lv_imgbtn_set_src(ui_Git_ImgButtonLogo, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_git_pressed_png, NULL);
    lv_obj_set_width(ui_Git_ImgButtonLogo, 177);
    lv_obj_set_height(ui_Git_ImgButtonLogo, 177);
    lv_obj_set_x(ui_Git_ImgButtonLogo, 0);
    lv_obj_set_y(ui_Git_ImgButtonLogo, -90);
    lv_obj_set_align(ui_Git_ImgButtonLogo, LV_ALIGN_CENTER);

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
    lv_obj_clear_flag(ui_Bili, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_Bili, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bili, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_creat_text_area(ui_Bili, &ui_TextBiliUserID, -295, -217, 200, "ID:", "UserID", &ui_font_ShangShou14);
    lv_obj_set_style_text_align(ui_TextBiliUserID, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_TextBiliUserID, lv_color_hex(0x3B3B3B), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_creat_text_area(ui_Bili, &ui_TextBiliUserName, -240, -72, 250, " ", "Input UserID", NULL);
    lv_obj_add_flag(ui_TextBiliUserName, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_set_style_text_letter_space(ui_TextBiliUserName, 1, 0);
    lv_obj_add_style(ui_TextBiliUserName, &style_my_font, 0);

    ui_creat_img(ui_Bili, &ui_ImageFollower, 240, -111, LV_SIZE_CONTENT, LV_SIZE_CONTENT, &ui_img_follower_png);
    ui_creat_img(ui_Bili, &ui_ImageCoin, 0, 60, 48, 48, &ui_img_coin_png);
    ui_creat_img(ui_Bili, &ui_ImageLike, -240, 60, 48, 48, &ui_img_like_png);
    ui_creat_img(ui_Bili, &ui_ImageFavorite, 240, 60, 48, 48, &ui_img_favorite_png);

    ui_creat_text_area(ui_Bili, &ui_TextFollower, 240, -42, 220, "", "", &ui_font_ShangShou32);
    ui_creat_text_area(ui_Bili, &ui_TextLike, -240, 130, 220, "", "", &ui_font_ShangShou32);
    ui_creat_text_area(ui_Bili, &ui_TextCoin, 0, 130, 220, "", "", &ui_font_ShangShou32);
    ui_creat_text_area(ui_Bili, &ui_TextFavorite, 240, 130, 220, "", "", &ui_font_ShangShou32);

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

/////////////////////////////////////////////////////////////////////////////////////

static void ui_event_ArcTomato(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        int minutes = (int)lv_arc_get_value(ta) * 5;
        ui_tomato_set_time(minutes);
        ui_update_tomato_time(minutes);

        // static lv_style_t arc_width_style;
        // lv_style_set_arc_color(&arc_width_style, lv_palette_main(LV_PALETTE_RED));
        // lv_obj_add_style(ui_meter, &arc_width_style, LV_PART_INDICATOR);
        // lv_obj_set_style_arc_color(ui_meter, lv_palette_main(LV_PALETTE_RED), LV_PART_ITEMS);
    }
}

void ui_Tomato_screen_init(void) 
{
    // new page for tomato clock
    ui_Tomato = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Tomato, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_Tomato, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Tomato, 255, LV_PART_MAIN | LV_STATE_DEFAULT);


    // creat meter obj & init style
    ui_meter = lv_meter_create(ui_Tomato);
    lv_obj_center(ui_meter);
    lv_obj_set_size(ui_meter, 400, 400);
    // set meter background style
    lv_obj_set_style_radius(ui_meter, 200, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(ui_meter, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_bg_color(ui_meter, lv_color_hex(0x303545), LV_PART_MAIN);
    lv_obj_set_style_pad_all(ui_meter, 10, LV_PART_MAIN);
    // set meter indicator(the square (or circle) in the center) style
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, 0);
    lv_style_set_width(&style, 0);
    lv_style_set_height(&style, 0);
    lv_style_set_bg_opa(&style, LV_OPA_TRANSP);
    lv_obj_add_style(ui_meter, &style, LV_PART_INDICATOR);

    // Add minute to the scale
    ui_scale = lv_meter_add_scale(ui_meter);
    lv_meter_set_scale_ticks(ui_meter, ui_scale, 61, 2, 5, lv_color_white());
    lv_meter_set_scale_range(ui_meter, ui_scale, 0, 60, 360, 270);
    // add hour to the scale
    ui_scale_num = lv_meter_add_scale(ui_meter);
    lv_meter_set_scale_ticks(ui_meter, ui_scale_num, 12, 2, 5, lv_color_white());
    lv_meter_set_scale_major_ticks(ui_meter, ui_scale_num, 1, 2, 10, lv_color_white(), 15);
    lv_meter_set_scale_range(ui_meter, ui_scale_num, 0, 55, 330, 270);
    // Add the hands from images
    // ui_indic_pointer = lv_meter_add_needle_line(ui_meter, ui_scale, 15, lv_palette_main(LV_PALETTE_GREY), -60);
    ui_indic_pointer = lv_meter_add_needle_img(ui_meter, ui_scale, &ui_img_tomato_png_100, 50, 50);
    lv_meter_set_indicator_value(ui_meter, ui_indic_pointer, 0);
    // Add a red arc to the start
    ui_indic_pie = lv_meter_add_arc(ui_meter, ui_scale, 130, lv_color_hex(0xff6347), 0);
    lv_meter_set_indicator_start_value(ui_meter, ui_indic_pie, 0);
    lv_meter_set_indicator_end_value(ui_meter, ui_indic_pie, 0);

    // creat an arc to set time
    ui_ArcTomato = lv_arc_create(ui_Tomato);
    lv_obj_set_width(ui_ArcTomato, 370);
    lv_obj_set_height(ui_ArcTomato, 370);
    lv_obj_set_align(ui_ArcTomato, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_ArcTomato, 1, 11);
    lv_arc_set_value(ui_ArcTomato, 1);
    lv_arc_set_bg_angles(ui_ArcTomato, 300, 240);
    // set arc background style
    lv_obj_set_style_arc_width(ui_ArcTomato, 20, LV_PART_MAIN);
    lv_obj_set_style_arc_opa(ui_ArcTomato, LV_OPA_TRANSP, LV_PART_MAIN);
    // set arc indicator style
    lv_obj_set_style_arc_width(ui_ArcTomato, 70, LV_PART_INDICATOR);
    lv_obj_set_style_arc_opa(ui_ArcTomato, LV_OPA_TRANSP, LV_PART_INDICATOR);
    // remove arc knob style
    lv_obj_remove_style(ui_ArcTomato, NULL, LV_PART_KNOB);
    
    lv_obj_clear_flag(ui_ArcTomato, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_event_cb(ui_ArcTomato, ui_event_ArcTomato, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Tomato, ui_event_Tomato, LV_EVENT_ALL, NULL);
}

void ui_init(void)
{
    // init font
    static lv_ft_info_t info;
    info.name = "./thirdparty/FangZhengHeiTi-GBK-1.ttf";
    info.weight = 32;
    info.style = FT_FONT_STYLE_NORMAL;
    info.mem = NULL;
    if(!lv_ft_font_init(&info)) {
        LV_LOG_ERROR("init font failed.");
        return;
    }
    lv_style_init(&style_my_font);
    lv_style_set_text_font(&style_my_font, info.font);

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), \
                                lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Monitor_screen_init();
    ui_Git_screen_init();
    ui_Bili_screen_init();
    ui_Tomato_screen_init();
    lv_disp_load_scr(ui_Monitor);
}
