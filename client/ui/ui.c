// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void Pointer_Animation(lv_obj_t * TargetObject, int delay);
lv_obj_t * ui_Screen1;
lv_obj_t * ui_bg;
lv_obj_t * ui_CpuUsagePointer;
lv_obj_t * ui_MemUsagePointer;
lv_obj_t * ui_GMemUsagePointer;
lv_obj_t * ui_GpuUsagePointer;
lv_obj_t * ui_Time;
lv_obj_t * ui_Week;
lv_obj_t * ui_Date;
lv_obj_t * ui_CpuUsagePercent;
lv_obj_t * ui_GpuUsagePercent;
lv_obj_t * ui_MemUsagePercent;
lv_obj_t * ui_GMemUsagePercent;
lv_obj_t * ui_Upload;
lv_obj_t * ui_Download;
lv_obj_t * ui_Read;
lv_obj_t * ui_Write;
lv_obj_t * ui_CpuFrequency;
lv_obj_t * ui_GpuFrequency;
lv_obj_t * ui_CPUModel;
lv_obj_t * ui_GPUModel;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void Pointer_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, 2000);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 1);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_bg = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_bg, &ui_img_bg2_png);
    lv_obj_set_width(ui_bg, 1920);
    lv_obj_set_height(ui_bg, 480);
    lv_obj_set_align(ui_bg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_bg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_bg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_CpuUsagePointer = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_CpuUsagePointer, &ui_img_bigpointer_png);
    lv_obj_set_width(ui_CpuUsagePointer, LV_SIZE_CONTENT);   /// 380
    lv_obj_set_height(ui_CpuUsagePointer, LV_SIZE_CONTENT);    /// 380
    lv_obj_set_x(ui_CpuUsagePointer, 25);
    lv_obj_set_y(ui_CpuUsagePointer, 22);
    lv_obj_set_align(ui_CpuUsagePointer, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_CpuUsagePointer, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CpuUsagePointer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(ui_CpuUsagePointer, -170);

    ui_MemUsagePointer = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_MemUsagePointer, &ui_img_smallpointer_png);
    lv_obj_set_width(ui_MemUsagePointer, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MemUsagePointer, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MemUsagePointer, -218);
    lv_obj_set_y(ui_MemUsagePointer, -123);
    lv_obj_set_align(ui_MemUsagePointer, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_MemUsagePointer, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_MemUsagePointer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(ui_MemUsagePointer, -450);

    ui_GMemUsagePointer = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_GMemUsagePointer, &ui_img_smallpointer_png);
    lv_obj_set_width(ui_GMemUsagePointer, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_GMemUsagePointer, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_GMemUsagePointer, 884);
    lv_obj_set_y(ui_GMemUsagePointer, -123);
    lv_obj_set_align(ui_GMemUsagePointer, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_GMemUsagePointer, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_GMemUsagePointer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(ui_GMemUsagePointer, -450);

    ui_GpuUsagePointer = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_GpuUsagePointer, &ui_img_bigpointer_png);
    lv_obj_set_width(ui_GpuUsagePointer, LV_SIZE_CONTENT);   /// 380
    lv_obj_set_height(ui_GpuUsagePointer, LV_SIZE_CONTENT);    /// 380
    lv_obj_set_x(ui_GpuUsagePointer, 649);
    lv_obj_set_y(ui_GpuUsagePointer, 21);
    lv_obj_set_align(ui_GpuUsagePointer, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_GpuUsagePointer, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_GpuUsagePointer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(ui_GpuUsagePointer, -170);

    ui_Time = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_Time, 164);
    lv_obj_set_height(ui_Time, LV_SIZE_CONTENT);    /// 53
    lv_obj_set_x(ui_Time, 337);
    lv_obj_set_y(ui_Time, -10);
    lv_obj_set_align(ui_Time, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Time, "00:00");
    lv_textarea_set_one_line(ui_Time, true);
    lv_obj_set_style_text_align(ui_Time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Time, &ui_font_ShangShou48, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Time, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Time, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Week = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_Week, 164);
    lv_obj_set_height(ui_Week, LV_SIZE_CONTENT);    /// 53
    lv_obj_set_x(ui_Week, 333);
    lv_obj_set_y(ui_Week, 33);
    lv_obj_set_align(ui_Week, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Week, "Sun.");
    lv_textarea_set_one_line(ui_Week, true);
    lv_obj_set_style_text_align(ui_Week, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Week, &ui_font_ShangShou40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Week, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Date = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_Date, 230);
    lv_obj_set_height(ui_Date, LV_SIZE_CONTENT);    /// 53
    lv_obj_set_x(ui_Date, 337);
    lv_obj_set_y(ui_Date, 72);
    lv_obj_set_align(ui_Date, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Date, "2022-01-01");
    lv_textarea_set_one_line(ui_Date, true);
    lv_obj_set_style_text_align(ui_Date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Date, &ui_font_ShangShou32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Date, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CpuUsagePercent = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_CpuUsagePercent, 219);
    lv_obj_set_height(ui_CpuUsagePercent, LV_SIZE_CONTENT);    /// 53
    lv_obj_set_x(ui_CpuUsagePercent, 23);
    lv_obj_set_y(ui_CpuUsagePercent, 24);
    lv_obj_set_align(ui_CpuUsagePercent, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_CpuUsagePercent, "0%");
    lv_textarea_set_one_line(ui_CpuUsagePercent, true);
    lv_obj_set_style_text_align(ui_CpuUsagePercent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CpuUsagePercent, &ui_font_ShangShou48, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CpuUsagePercent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CpuUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CpuUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GpuUsagePercent = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_GpuUsagePercent, 219);
    lv_obj_set_height(ui_GpuUsagePercent, LV_SIZE_CONTENT);    /// 53
    lv_obj_set_x(ui_GpuUsagePercent, 649);
    lv_obj_set_y(ui_GpuUsagePercent, 21);
    lv_obj_set_align(ui_GpuUsagePercent, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_GpuUsagePercent, "0%");
    lv_textarea_set_one_line(ui_GpuUsagePercent, true);
    lv_obj_set_style_text_align(ui_GpuUsagePercent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_GpuUsagePercent, &ui_font_ShangShou48, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_GpuUsagePercent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_GpuUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_GpuUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MemUsagePercent = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_MemUsagePercent, 219);
    lv_obj_set_height(ui_MemUsagePercent, LV_SIZE_CONTENT);    /// 53
    lv_obj_set_x(ui_MemUsagePercent, -217);
    lv_obj_set_y(ui_MemUsagePercent, -118);
    lv_obj_set_align(ui_MemUsagePercent, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_MemUsagePercent, "0%");
    lv_textarea_set_one_line(ui_MemUsagePercent, true);
    lv_obj_set_style_text_align(ui_MemUsagePercent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_MemUsagePercent, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_MemUsagePercent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MemUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_MemUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GMemUsagePercent = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_GMemUsagePercent, 219);
    lv_obj_set_height(ui_GMemUsagePercent, LV_SIZE_CONTENT);    /// 53
    lv_obj_set_x(ui_GMemUsagePercent, 885);
    lv_obj_set_y(ui_GMemUsagePercent, -118);
    lv_obj_set_align(ui_GMemUsagePercent, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_GMemUsagePercent, "0%");
    lv_textarea_set_one_line(ui_GMemUsagePercent, true);
    lv_obj_set_style_text_align(ui_GMemUsagePercent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_GMemUsagePercent, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_GMemUsagePercent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_GMemUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_GMemUsagePercent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Upload = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_Upload, 219);
    lv_obj_set_height(ui_Upload, LV_SIZE_CONTENT);    /// 53
    lv_obj_set_x(ui_Upload, 310);
    lv_obj_set_y(ui_Upload, 144);
    lv_obj_set_align(ui_Upload, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Upload, "0.0KB");
    lv_textarea_set_one_line(ui_Upload, true);
    lv_obj_set_style_text_align(ui_Upload, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Upload, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Upload, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Upload, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Upload, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Download = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_Download, 219);
    lv_obj_set_height(ui_Download, LV_SIZE_CONTENT);    /// 53
    lv_obj_set_x(ui_Download, 426);
    lv_obj_set_y(ui_Download, 143);
    lv_obj_set_align(ui_Download, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Download, "0.0KB");
    lv_textarea_set_one_line(ui_Download, true);
    lv_obj_set_style_text_align(ui_Download, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Download, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Download, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Download, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Download, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Read = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_Read, 219);
    lv_obj_set_height(ui_Read, LV_SIZE_CONTENT);    /// 53
    lv_obj_set_x(ui_Read, 310);
    lv_obj_set_y(ui_Read, 176);
    lv_obj_set_align(ui_Read, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Read, "0.0MB");
    lv_textarea_set_one_line(ui_Read, true);
    lv_obj_set_style_text_align(ui_Read, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Read, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Read, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Read, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Read, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Write = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_Write, 219);
    lv_obj_set_height(ui_Write, LV_SIZE_CONTENT);    /// 53
    lv_obj_set_x(ui_Write, 426);
    lv_obj_set_y(ui_Write, 176);
    lv_obj_set_align(ui_Write, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Write, "0.0MB");
    lv_textarea_set_one_line(ui_Write, true);
    lv_obj_set_style_text_align(ui_Write, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Write, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Write, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Write, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Write, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CpuFrequency = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_CpuFrequency, 219);
    lv_obj_set_height(ui_CpuFrequency, LV_SIZE_CONTENT);    /// 53
    lv_obj_set_x(ui_CpuFrequency, 25);
    lv_obj_set_y(ui_CpuFrequency, 175);
    lv_obj_set_align(ui_CpuFrequency, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_CpuFrequency, "0.0GHz");
    lv_textarea_set_one_line(ui_CpuFrequency, true);
    lv_obj_set_style_text_align(ui_CpuFrequency, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CpuFrequency, &ui_font_ShangShou28, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CpuFrequency, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CpuFrequency, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CpuFrequency, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GpuFrequency = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_GpuFrequency, 219);
    lv_obj_set_height(ui_GpuFrequency, LV_SIZE_CONTENT);    /// 53
    lv_obj_set_x(ui_GpuFrequency, 648);
    lv_obj_set_y(ui_GpuFrequency, 174);
    lv_obj_set_align(ui_GpuFrequency, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_GpuFrequency, "0.0GHz");
    lv_textarea_set_one_line(ui_GpuFrequency, true);
    lv_obj_set_style_text_align(ui_GpuFrequency, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_GpuFrequency, &ui_font_ShangShou28, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_GpuFrequency, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_GpuFrequency, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_GpuFrequency, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CPUModel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_CPUModel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_CPUModel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_CPUModel, 26);
    lv_obj_set_y(ui_CPUModel, 144);
    lv_obj_set_align(ui_CPUModel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_CPUModel, "i7-6700K");
    lv_obj_set_style_text_font(ui_CPUModel, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GPUModel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_GPUModel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_GPUModel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_GPUModel, 649);
    lv_obj_set_y(ui_GPUModel, 142);
    lv_obj_set_align(ui_GPUModel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_GPUModel, "GTX-1080");
    lv_obj_set_style_text_font(ui_GPUModel, &ui_font_ShangShou24, LV_PART_MAIN | LV_STATE_DEFAULT);

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
