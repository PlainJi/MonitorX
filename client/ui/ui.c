// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: DesktopBox

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void ui_Screen1_screen_init(void);
void StartCpuPointer_Animation(lv_obj_t * TargetObject, int delay);
void StartGpuPointer_Animation(lv_obj_t * TargetObject, int delay);
void StartCpuTemp_Animation(lv_obj_t * TargetObject, int delay);
void StartGpuTemp_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_Screen1(lv_event_t * e);
lv_obj_t * ui_Screen1;
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
void ui_event_Screen1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        StartGpuTemp_Animation(ui_GpuTemp, 0);
        StartCpuTemp_Animation(ui_CpuTemp, 0);
        StartGpuPointer_Animation(ui_GpuUsagePointer, 0);
        StartCpuPointer_Animation(ui_CpuUsagePointer, 0);
    }
}

void ui_Screen1_Start(void)
{
    StartGpuTemp_Animation(ui_GpuTemp, 0);
    StartCpuTemp_Animation(ui_CpuTemp, 0);
    StartGpuPointer_Animation(ui_GpuUsagePointer, 0);
    StartCpuPointer_Animation(ui_CpuUsagePointer, 0);
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PanelMonitor = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_PanelMonitor, 800);
    lv_obj_set_height(ui_PanelMonitor, 480);
    lv_obj_set_y(ui_PanelMonitor, -20);
    lv_obj_clear_flag(ui_PanelMonitor, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelMonitor, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelMonitor, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMonitor, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_PanelMonitor, &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelMonitor, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelMonitorCpu = lv_obj_create(ui_PanelMonitor);
    lv_obj_set_width(ui_PanelMonitorCpu, 392);
    lv_obj_set_height(ui_PanelMonitorCpu, 476);
    lv_obj_set_x(ui_PanelMonitorCpu, -16);
    lv_obj_set_y(ui_PanelMonitorCpu, -17);
    lv_obj_clear_flag(ui_PanelMonitorCpu, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
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
    lv_obj_set_style_text_align(ui_CpuModel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CpuModel, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MemCapacity = lv_label_create(ui_PanelMonitorCpu);
    lv_obj_set_width(ui_MemCapacity, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MemCapacity, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MemCapacity, -41);
    lv_obj_set_y(ui_MemCapacity, 105);
    lv_obj_set_align(ui_MemCapacity, LV_ALIGN_CENTER);
    lv_label_set_text(ui_MemCapacity, "16GB");
    lv_obj_set_style_text_align(ui_MemCapacity, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_MemCapacity, &ui_font_ShangShou20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CpuUsagePointer = lv_img_create(ui_PanelMonitorCpu);
    lv_img_set_src(ui_CpuUsagePointer, &ui_img_big_pointer_png);
    lv_obj_set_width(ui_CpuUsagePointer, LV_SIZE_CONTENT);   /// 144
    lv_obj_set_height(ui_CpuUsagePointer, LV_SIZE_CONTENT);    /// 4
    lv_obj_set_x(ui_CpuUsagePointer, -112);
    lv_obj_set_y(ui_CpuUsagePointer, -21);
    lv_obj_set_align(ui_CpuUsagePointer, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_CpuUsagePointer, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CpuUsagePointer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
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
    lv_obj_add_flag(ui_CpuTemp, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CpuTemp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_pivot(ui_CpuTemp, 72, 3);
    lv_img_set_angle(ui_CpuTemp, 300);

    ui_PanelMonitorGpu = lv_obj_create(ui_PanelMonitor);
    lv_obj_set_width(ui_PanelMonitorGpu, 391);
    lv_obj_set_height(ui_PanelMonitorGpu, 476);
    lv_obj_set_x(ui_PanelMonitorGpu, 386);
    lv_obj_set_y(ui_PanelMonitorGpu, -19);
    lv_obj_clear_flag(ui_PanelMonitorGpu, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
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
    lv_obj_set_style_text_align(ui_GpuModel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_GpuModel, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GMemCapacity = lv_label_create(ui_PanelMonitorGpu);
    lv_obj_set_width(ui_GMemCapacity, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_GMemCapacity, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_GMemCapacity, 37);
    lv_obj_set_y(ui_GMemCapacity, 106);
    lv_obj_set_align(ui_GMemCapacity, LV_ALIGN_CENTER);
    lv_label_set_text(ui_GMemCapacity, "8GB");
    lv_obj_set_style_text_align(ui_GMemCapacity, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_GMemCapacity, &ui_font_ShangShou20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GpuUsagePointer = lv_img_create(ui_PanelMonitorGpu);
    lv_img_set_src(ui_GpuUsagePointer, &ui_img_big_pointer_png);
    lv_obj_set_width(ui_GpuUsagePointer, LV_SIZE_CONTENT);   /// 144
    lv_obj_set_height(ui_GpuUsagePointer, LV_SIZE_CONTENT);    /// 4
    lv_obj_set_x(ui_GpuUsagePointer, -33);
    lv_obj_set_y(ui_GpuUsagePointer, -18);
    lv_obj_set_align(ui_GpuUsagePointer, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_GpuUsagePointer, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_GpuUsagePointer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
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
    lv_obj_add_flag(ui_GpuTemp, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_GpuTemp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_pivot(ui_GpuTemp, 72, 3);
    lv_img_set_angle(ui_GpuTemp, 300);

    ui_PanelMid = lv_obj_create(ui_PanelMonitor);
    lv_obj_set_width(ui_PanelMid, 250);
    lv_obj_set_height(ui_PanelMid, 480);
    lv_obj_set_align(ui_PanelMid, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelMid, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
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
    lv_textarea_set_text(ui_Time, " ");
    lv_textarea_set_one_line(ui_Time, true);
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
    lv_textarea_set_text(ui_Week, " ");
    lv_textarea_set_one_line(ui_Week, true);
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
    lv_textarea_set_text(ui_Date, " ");
    lv_textarea_set_one_line(ui_Date, true);
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
    lv_obj_set_style_text_align(ui_Write, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Write, &ui_font_ShangShou20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Write, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Write, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Write, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Write, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //lv_obj_add_event_cb(ui_Screen1, ui_event_Screen1, LV_EVENT_ALL, NULL);
}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
}
