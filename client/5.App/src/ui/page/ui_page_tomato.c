#include "ui_page_tomato.h"

#include "../ui_helper.h"

DEFINE_IMG(tomato);

//void ui_tomato_event(lv_event_t * e);
lv_obj_t * ui_tomato;
lv_obj_t * ui_tomato_clock;
lv_obj_t * ui_tomato_needle;

lv_scale_t * ui_tomato_scale;
lv_scale_t * ui_tomato_scale_num;
lv_style_t * ui_tomato_indic_pointer;
lv_style_t * ui_tomato_indic_pie;
lv_obj_t * ui_tomato_arc;
lv_scale_section_t * section;

/*
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
*/


static void ui_tomato_event_arc(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        //int minutes = (int)lv_arc_get_value(ta) * 5;
        int minutes = (int)lv_arc_get_value(ta);
        LV_LOG_INFO("%d\n", minutes);
        //ui_update_tomato_time(minutes);

        // static lv_style_t arc_width_style;
        // lv_style_set_arc_color(&arc_width_style, lv_palette_main(LV_PALETTE_RED));
        // lv_obj_add_style(ui_meter, &arc_width_style, LV_PART_INDICATOR);
        // lv_obj_set_style_arc_color(ui_meter, lv_palette_main(LV_PALETTE_RED), LV_PART_ITEMS);
    }
}

void _lv_scale_set_image_needle_value(void * obj, int32_t v)
{
    lv_scale_set_image_needle_value(obj, ui_tomato_needle, v);
}

void ui_tomato_init_page(void) {
    ui_create_panel(NULL, &ui_tomato, 0, 0, 800, 480, LV_ALIGN_CENTER);

    // creat meter obj & init style
    ui_tomato_clock = lv_scale_create(ui_tomato);
    ui_obj_set_style_basic(ui_tomato_clock, 0, 0, 380, 380, LV_ALIGN_CENTER);
    ui_obj_set_style_radius(ui_tomato_clock, LV_PART_MAIN, 200);
    ui_obj_set_style_bg(ui_tomato_clock, LV_PART_MAIN, lv_color_hex(0x303545), LV_OPA_COVER, NULL, LV_OPA_COVER);
    lv_obj_set_style_pad_all(ui_tomato_clock, 40, LV_PART_MAIN);

    lv_scale_set_label_show(ui_tomato_clock, true);
    lv_scale_set_mode(ui_tomato_clock, LV_SCALE_MODE_ROUND_OUTER);
    lv_scale_set_range(ui_tomato_clock, 0, 60);
    lv_scale_set_angle_range(ui_tomato_clock, 360);
    lv_scale_set_rotation(ui_tomato_clock, 270);

    lv_scale_set_total_tick_count(ui_tomato_clock, 61);
    lv_scale_set_major_tick_every(ui_tomato_clock, 5);
    static const char * hour_ticks[] = {"0", "5", "10", "15", "20", "25", "30", "35", "40", "45", "50", "55", NULL};
    lv_scale_set_text_src(ui_tomato_clock, hour_ticks);

    /* main line style */
    static lv_style_t main_line_style;
    lv_style_init(&main_line_style);
    lv_style_set_arc_width(&main_line_style, 0);
    lv_obj_add_style(ui_tomato_clock, &main_line_style, LV_PART_MAIN);
    /* scale indicator properties */
    static lv_style_t indicator_style;
    lv_style_init(&indicator_style);
    lv_style_set_text_font(&indicator_style, &lv_font_montserrat_10);
    lv_style_set_text_color(&indicator_style, lv_palette_main(LV_PALETTE_YELLOW));
    /* Major tick properties */
    lv_style_set_line_color(&indicator_style, lv_palette_main(LV_PALETTE_YELLOW));
    lv_style_set_length(&indicator_style, 10);
    lv_style_set_line_width(&indicator_style, 2);
    lv_obj_add_style(ui_tomato_clock, &indicator_style, LV_PART_INDICATOR);
    /* Minor tick properties */
    static lv_style_t minor_ticks_style;
    lv_style_init(&minor_ticks_style);
    lv_style_set_line_color(&minor_ticks_style, lv_palette_main(LV_PALETTE_YELLOW));
    lv_style_set_length(&minor_ticks_style, 6);
    lv_style_set_line_width(&minor_ticks_style, 2);
    lv_obj_add_style(ui_tomato_clock, &minor_ticks_style, LV_PART_ITEMS);
    /* add needle from image */
    ui_tomato_needle = lv_image_create(ui_tomato_clock);
    lv_image_set_src(ui_tomato_needle, IMG(tomato));
    lv_obj_align(ui_tomato_needle, LV_ALIGN_CENTER, 0, 0);
    // lv_image_set_pivot(ui_tomato_needle, 0, 0);
#if DEBUG
    ui_animation(ui_tomato_clock, 0, 59, 1000, -1, 0, 0, LV_ANIM_REPEAT_INFINITE, _lv_scale_set_image_needle_value);
#endif

    // creat an arc to set time
    ui_tomato_arc = lv_arc_create(ui_tomato);
    ui_obj_set_style_basic(ui_tomato_arc, 0, 0, 290, 290, LV_ALIGN_CENTER);
    ui_obj_set_style_arc(ui_tomato_arc, LV_PART_MAIN, 80, lv_color_hex(0x303545), LV_OPA_COVER, false, NULL);
    ui_obj_set_style_arc(ui_tomato_arc, LV_PART_INDICATOR, 80, lv_color_hex(0xff6347), LV_OPA_COVER, false, NULL);
    lv_arc_set_range(ui_tomato_arc, 0, 12);
    lv_arc_set_value(ui_tomato_arc, 0);
    lv_arc_set_bg_angles(ui_tomato_arc, 0, 360);
    lv_arc_set_rotation(ui_tomato_arc, 270);
    lv_obj_remove_style(ui_tomato_arc, NULL, LV_PART_KNOB);
    lv_obj_add_event_cb(ui_tomato_arc, ui_tomato_event_arc, LV_EVENT_ALL, NULL);

/*
    lv_obj_clear_flag(ui_ArcTomato, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_event_cb(ui_ArcTomato, ui_event_ArcTomato, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Tomato, ui_event_Tomato, LV_EVENT_ALL, NULL);
*/
}


