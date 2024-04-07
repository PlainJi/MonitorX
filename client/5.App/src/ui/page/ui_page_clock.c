#include "ui_page_clock.h"

#include "../ui.h"
#include "../ui_helper.h"


lv_obj_t *ui_clock;
lv_obj_t *ui_roller_hour1;
lv_obj_t *ui_roller_hour2;
lv_obj_t *ui_roller_min1;
lv_obj_t *ui_roller_min2;
lv_obj_t *ui_roller_sec1;
lv_obj_t *ui_roller_sec2;

const char *num0to9 = {
    "0\n"
    "1\n"
    "2\n"
    "3\n"
    "4\n"
    "5\n"
    "6\n"
    "7\n"
    "8\n"
    "9"
};

const char *num0to2 = {
    "0\n"
    "1\n"
    "2"
};

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        char buf[32];
        lv_roller_get_selected_str(obj, buf, sizeof(buf));
        LV_LOG_USER("Selected month: %s\n", buf);
    }
}


static void mask_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);

    static int16_t mask_top_id = -1;
    static int16_t mask_bottom_id = -1;

    if(code == LV_EVENT_COVER_CHECK) {
        lv_event_set_cover_res(e, LV_COVER_RES_MASKED);

    }
    else if(code == LV_EVENT_DRAW_MAIN_BEGIN) {
        /* add mask */
        const lv_font_t * font = lv_obj_get_style_text_font(obj, LV_PART_MAIN);
        int32_t line_space = lv_obj_get_style_text_line_space(obj, LV_PART_MAIN);
        int32_t font_h = lv_font_get_line_height(font);

        lv_area_t roller_coords;
        lv_obj_get_coords(obj, &roller_coords);

        lv_area_t rect_area;
        rect_area.x1 = roller_coords.x1;
        rect_area.x2 = roller_coords.x2;
        rect_area.y1 = roller_coords.y1;
        rect_area.y2 = roller_coords.y1 + (lv_obj_get_height(obj) - font_h - line_space) / 2;

        lv_draw_sw_mask_fade_param_t * fade_mask_top = lv_malloc(sizeof(lv_draw_sw_mask_fade_param_t));
        lv_draw_sw_mask_fade_init(fade_mask_top, &rect_area, LV_OPA_TRANSP, rect_area.y1, LV_OPA_COVER, rect_area.y2);
        //mask_top_id = lv_draw_mask_add(fade_mask_top, NULL);

        rect_area.y1 = rect_area.y2 + font_h + line_space - 1;
        rect_area.y2 = roller_coords.y2;

        lv_draw_sw_mask_fade_param_t * fade_mask_bottom = lv_malloc(sizeof(lv_draw_sw_mask_fade_param_t));
        lv_draw_sw_mask_fade_init(fade_mask_bottom, &rect_area, LV_OPA_COVER, rect_area.y1, LV_OPA_TRANSP, rect_area.y2);
        //mask_bottom_id = lv_draw_mask_add(fade_mask_bottom, NULL);

    }
    else if(code == LV_EVENT_DRAW_POST_END) {
        //lv_draw_sw_mask_fade_param_t * fade_mask_top = lv_draw_mask_remove_id(mask_top_id);
        //lv_draw_sw_mask_fade_param_t * fade_mask_bottom = lv_draw_mask_remove_id(mask_bottom_id);
        //lv_draw_mask_free_param(fade_mask_top);
        //lv_draw_mask_free_param(fade_mask_bottom);
        //lv_free(fade_mask_top);
        //lv_free(fade_mask_bottom);
        //mask_top_id = -1;
        //mask_bottom_id = -1;
    }
}

void _lv_roller_set_selected(void *obj, int32_t v) {
    lv_roller_set_selected(obj, v, LV_ANIM_ON);
}

void ui_clock_init(void) {
    ui_create_panel(NULL, &ui_clock, 0, 0, 800, 480, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_clock, LV_PART_MAIN, lv_color_black(), LV_OPA_COVER, NULL, LV_OPA_COVER);

    ui_create_roller(ui_clock, &ui_roller_hour1, -200, 0, 100,  2, \
                        lv_color_hex(0x303545), LV_OPA_COVER, NULL, LV_OPA_COVER, \
                        lv_font_fzht_96, lv_color_white(), LV_TEXT_ALIGN_CENTER, \
                        num0to2, LV_ROLLER_MODE_INFINITE);
    ui_create_roller(ui_clock, &ui_roller_hour2, -90, 0, 100,  2, \
                        lv_color_hex(0x303545), LV_OPA_COVER, NULL, LV_OPA_COVER, \
                        lv_font_fzht_96, lv_color_white(), LV_TEXT_ALIGN_CENTER, \
                        num0to9, LV_ROLLER_MODE_INFINITE);
    ui_create_roller(ui_clock, &ui_roller_min1, 90, 0, 100,  2, \
                        lv_color_hex(0x303545), LV_OPA_COVER, NULL, LV_OPA_COVER, \
                        lv_font_fzht_96, lv_color_white(), LV_TEXT_ALIGN_CENTER, \
                        num0to9, LV_ROLLER_MODE_INFINITE);
    ui_create_roller(ui_clock, &ui_roller_min2, 200, 0, 100,  2, \
                        lv_color_hex(0x303545), LV_OPA_COVER, NULL, LV_OPA_COVER, \
                        lv_font_fzht_96, lv_color_white(), LV_TEXT_ALIGN_CENTER, \
                        num0to9, LV_ROLLER_MODE_INFINITE);
    //lv_obj_add_event_cb(ui_roller_hour1, mask_event_cb, LV_EVENT_ALL, NULL);
    
#if DEBUG
    ui_animation(ui_roller_hour1, 0, 3, 3000, -1, 0, 0, LV_ANIM_REPEAT_INFINITE, _lv_roller_set_selected);
    lv_obj_add_event_cb(ui_roller_hour2, event_handler, LV_EVENT_ALL, NULL);
#endif
}
