#include "ui_page_monitor.h"

#include "../ui_helper.h"

DEFINE_IMG(bg);
DEFINE_IMG(small_pointer);
DEFINE_IMG(big_pointer);
DEFINE_IMG(mem_usage1);
DEFINE_IMG(mem_usage2);

lv_obj_t * ui_monitor;
lv_obj_t * ui_monitor_connect_panel;
lv_obj_t * ui_monitor_disconnect_panel;
lv_obj_t * ui_disconnect_arc;
lv_obj_t * ui_disconnect_text;
lv_anim_t * ui_disconnect_anim;

lv_obj_t * ui_monitor_cpu_panel;
lv_obj_t * ui_cpu_model;
lv_obj_t * ui_cpu_usage_pointer;
lv_obj_t * ui_cpu_usage_percent;
lv_obj_t * ui_cpu_frequency;
lv_obj_t * ui_cpu_mem_capacity;
lv_obj_t * ui_cpu_mem_usage_arc;
lv_obj_t * ui_cpu_mem_usage_percent;
lv_obj_t * ui_cpu_temp_pointer;

lv_obj_t * ui_monitor_gpu_panel;
lv_obj_t * ui_gpu_model;
lv_obj_t * ui_gpu_usage_pointer;
lv_obj_t * ui_gpu_usage_percent;
lv_obj_t * ui_gpu_frequency;
lv_obj_t * ui_gpu_mem_capacity;
lv_obj_t * ui_gpu_mem_usage_arc;
lv_obj_t * ui_gpu_mem_usage_percent;
lv_obj_t * ui_gpu_temp_pointer;

lv_obj_t * ui_monitor_middle_panel;
lv_obj_t * ui_middle_time;
lv_obj_t * ui_middle_week;
lv_obj_t * ui_middle_date;
lv_obj_t * ui_middle_up;
lv_obj_t * ui_middle_down;
lv_obj_t * ui_middle_read;
lv_obj_t * ui_middle_write;



// void ui_event_Monitor(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);

//     if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
//         _ui_screen_change(ui_Git, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
//     }
//     if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
//         _ui_screen_change(ui_Tomato, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
//     }
// }

void ui_monitor_disconnect(void) {
    ui_disconnect_anim = ui_animation(ui_disconnect_arc, 0, 100, 1000, -1, 0, 500, LV_ANIM_REPEAT_INFINITE, _lv_arc_set_value);
}

void ui_monitor_connect(void) {
    lv_anim_delete(ui_disconnect_anim, NULL);
}

void ui_monitor_init(void)
{
    // Panel Disconnect
    ui_creat_panel(NULL, &ui_monitor_disconnect_panel, 0, 0, 800, 480, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_monitor_disconnect_panel, LV_PART_MAIN, lv_color_black(), LV_OPA_COVER, IMG(bg), LV_OPA_20);
    ui_disconnect_text = lv_label_create(ui_monitor_disconnect_panel);
    ui_obj_set_style_basic(ui_disconnect_text, 0, 100, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER);
    ui_obj_set_style_text(ui_disconnect_text, LV_PART_MAIN, &ui_font_ascii_20, LV_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 2, 0);
    lv_label_set_text(ui_disconnect_text, "Disconnect");
    ui_disconnect_arc = lv_arc_create(ui_monitor_disconnect_panel);
    ui_obj_set_style_basic(ui_disconnect_arc, 0, 0, 100, 100, LV_ALIGN_CENTER);
    lv_arc_set_rotation(ui_disconnect_arc, 270);
    lv_arc_set_bg_angles(ui_disconnect_arc, 0, 360);
    lv_obj_remove_style(ui_disconnect_arc, NULL, LV_PART_KNOB);

    // Panel Connect
    ui_creat_panel(NULL, &ui_monitor_connect_panel, 0, 0, 800, 480, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_monitor_connect_panel, LV_PART_MAIN, lv_color_black(), LV_OPA_80, IMG(bg), LV_OPA_COVER);

    ///////////////////--CPU--/////////////////////////

    ui_creat_panel(ui_monitor_connect_panel, &ui_monitor_cpu_panel, -196, 0, 388, 344, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_monitor_cpu_panel, LV_PART_MAIN, lv_color_black(), LV_OPA_0, NULL, LV_OPA_0);
    ui_create_label(ui_monitor_cpu_panel, &ui_cpu_model, -40, -145, LV_SIZE_CONTENT, LV_SIZE_CONTENT, \
                    &ui_font_ascii_24, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "CPU");
    ui_create_label(ui_monitor_cpu_panel, &ui_cpu_usage_percent, -40, 21, LV_SIZE_CONTENT, LV_SIZE_CONTENT, \
                    &ui_font_ascii_38, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");
    ui_create_label(ui_monitor_cpu_panel, &ui_cpu_frequency, -40, 45, LV_SIZE_CONTENT, LV_SIZE_CONTENT, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");
    ui_create_label(ui_monitor_cpu_panel, &ui_cpu_mem_usage_percent, -40, 109, LV_SIZE_CONTENT, LV_SIZE_CONTENT, \
                    &ui_font_ascii_28, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");
    ui_create_label(ui_monitor_cpu_panel, &ui_cpu_mem_capacity, -40, 145, LV_SIZE_CONTENT, LV_SIZE_CONTENT, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");

    ui_create_image_pointer(ui_monitor_cpu_panel, &ui_cpu_usage_pointer, \
                            -114, 17, LV_SIZE_CONTENT, LV_SIZE_CONTENT, IMG(big_pointer), 144, 2, -180);
    ui_create_image_pointer(ui_monitor_cpu_panel, &ui_cpu_temp_pointer, \
                            89, -88, LV_SIZE_CONTENT, LV_SIZE_CONTENT, IMG(small_pointer), 72, 3, 300);
    ui_create_image_arc(ui_monitor_cpu_panel, &ui_cpu_mem_usage_arc, -40, 20, 295, 295, \
                        54, 126, LV_ARC_MODE_REVERSE, IMG(mem_usage1), IMG(mem_usage2));
#if DEBUG
    ui_animation(ui_cpu_usage_pointer, -180, 1650, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_image_set_rotation);
    ui_animation(ui_cpu_temp_pointer, 300, 1650, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_image_set_rotation);
    ui_animation(ui_cpu_mem_usage_arc, 0, 100, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_arc_set_value);
#endif
    ///////////////////--GPU--/////////////////////////

    ui_creat_panel(ui_monitor_connect_panel, &ui_monitor_gpu_panel, 196, 0, 388, 344, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_monitor_gpu_panel, LV_PART_MAIN, lv_color_black(), LV_OPA_0, NULL, LV_OPA_0);
    ui_create_label(ui_monitor_gpu_panel, &ui_gpu_model, 40, -145, LV_SIZE_CONTENT, LV_SIZE_CONTENT, \
                    &ui_font_ascii_24, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "GPU");
    ui_create_label(ui_monitor_gpu_panel, &ui_gpu_usage_percent, 40, 21, LV_SIZE_CONTENT, LV_SIZE_CONTENT, \
                    &ui_font_ascii_38, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");
    ui_create_label(ui_monitor_gpu_panel, &ui_gpu_frequency, 40, 45, LV_SIZE_CONTENT, LV_SIZE_CONTENT, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");
    ui_create_label(ui_monitor_gpu_panel, &ui_gpu_mem_usage_percent, 40, 109, LV_SIZE_CONTENT, LV_SIZE_CONTENT, \
                    &ui_font_ascii_28, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");
    ui_create_label(ui_monitor_gpu_panel, &ui_gpu_mem_capacity, 40, 145, LV_SIZE_CONTENT, LV_SIZE_CONTENT, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");

    ui_create_image_pointer(ui_monitor_gpu_panel, &ui_gpu_usage_pointer, \
                            -26, 18, LV_SIZE_CONTENT, LV_SIZE_CONTENT, IMG(big_pointer), 144, 2, -180);
    ui_create_image_pointer(ui_monitor_gpu_panel, &ui_gpu_temp_pointer, \
                            -156, -88, LV_SIZE_CONTENT, LV_SIZE_CONTENT, IMG(small_pointer), 72, 3, 300);
    ui_create_image_arc(ui_monitor_gpu_panel, &ui_gpu_mem_usage_arc, 40, 20, 295, 295, \
                        54, 126, LV_ARC_MODE_REVERSE, IMG(mem_usage1), IMG(mem_usage2));
#if DEBUG
    ui_animation(ui_gpu_usage_pointer, -180, 1650, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_image_set_rotation);
    ui_animation(ui_gpu_temp_pointer, 300, 1650, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_image_set_rotation);
    ui_animation(ui_gpu_mem_usage_arc, 0, 100, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_arc_set_value);
#endif

    ///////////////////--NET--/////////////////////////

    ui_creat_panel(ui_monitor_connect_panel, &ui_monitor_middle_panel, 0, 45, 250, 480, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_monitor_middle_panel, LV_PART_MAIN, lv_color_black(), LV_OPA_0, NULL, LV_OPA_0);
    ui_create_label(ui_monitor_middle_panel, &ui_middle_time, 1, -48, 150, LV_SIZE_CONTENT, \
                    &ui_font_ascii_40, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "");
    ui_create_label(ui_monitor_middle_panel, &ui_middle_week, 1, -11, 150, LV_SIZE_CONTENT, \
                    &ui_font_ascii_32, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "");
    ui_create_label(ui_monitor_middle_panel, &ui_middle_date, 2, 26, 200, LV_SIZE_CONTENT, \
                    &ui_font_ascii_24, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "");
    ui_create_label(ui_monitor_middle_panel, &ui_middle_up, -30, 76, 90, LV_SIZE_CONTENT, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_RIGHT, lv_color_white(), LV_OPA_COVER, 0, 0, "0KB");
    ui_create_label(ui_monitor_middle_panel, &ui_middle_down, 78, 76, 90, LV_SIZE_CONTENT, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_RIGHT, lv_color_white(), LV_OPA_COVER, 0, 0, "0KB");
    ui_create_label(ui_monitor_middle_panel, &ui_middle_read, -30, 104, 90, LV_SIZE_CONTENT, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_RIGHT, lv_color_white(), LV_OPA_COVER, 0, 0, "0KB");
    ui_create_label(ui_monitor_middle_panel, &ui_middle_write, 78, 104, 90, LV_SIZE_CONTENT, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_RIGHT, lv_color_white(), LV_OPA_COVER, 0, 0, "0KB");

    //lv_obj_add_event_cb(ui_Monitor, ui_event_Monitor, LV_EVENT_ALL, NULL);

}