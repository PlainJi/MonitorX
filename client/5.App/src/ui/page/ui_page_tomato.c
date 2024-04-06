




DEFINE_IMG(tomato_clock);

// screen tomato
void ui_event_Tomato(lv_event_t * e);
lv_obj_t * ui_Tomato;
lv_obj_t * ui_meter;
lv_meter_scale_t * ui_scale;
lv_meter_scale_t * ui_scale_num;
lv_meter_indicator_t * ui_indic_pointer;
lv_meter_indicator_t * ui_indic_pie;
lv_obj_t * ui_ArcTomato;


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
    lv_obj_set_style_bg_opa(ui_meter, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
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
    ui_indic_pointer = lv_meter_add_needle_img(ui_meter, ui_scale, IMG(tomato_clock), 50, 50);
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


