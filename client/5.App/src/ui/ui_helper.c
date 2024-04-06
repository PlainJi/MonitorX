#include "ui_helper.h"

#include <stdio.h>

void ui_obj_remove_state_flag(lv_obj_t *obj) {
    lv_obj_remove_state(obj, LV_STATE_ANY);
    lv_obj_remove_flag(obj, OBJ_DEFAULT_FLAG);
}

// radius: >= 0 radius, < 0 clip corner
// lv_obj_set_style_opa controls transparency of all widget
void ui_obj_set_style_basic(lv_obj_t *obj, \
                        int32_t x, int32_t y, int32_t width, int32_t height, \
                        lv_align_t align) {
    lv_obj_set_x(obj, x);
    lv_obj_set_y(obj, y);
    lv_obj_set_width(obj, width);
    lv_obj_set_height(obj, height);
    lv_obj_set_align(obj, align);
    //lv_obj_set_style_opa(obj, opa, selector);
}

void ui_obj_set_style_radius(lv_obj_t *obj, lv_style_selector_t selector, int32_t radius) {
    if (radius < 0) 
        lv_obj_set_style_clip_corner(obj, true, selector);
    else 
        lv_obj_set_style_radius(obj, radius, selector);
}

void ui_obj_set_style_bg(lv_obj_t *obj, lv_style_selector_t selector, \
                        lv_color_t color, lv_opa_t opa, \
                        const void *img, lv_opa_t img_opa) {
    lv_obj_set_style_bg_color(obj, color, selector);
    lv_obj_set_style_bg_opa(obj, opa, selector);
    if(img) {
        lv_obj_set_style_bg_image_src(obj, img, selector);
        lv_obj_set_style_bg_image_opa(obj, img_opa, selector);
    }
}

void ui_obj_set_style_border(lv_obj_t *obj, lv_style_selector_t selector, \
                            int32_t width, lv_color_t color, lv_opa_t opa) {
    lv_obj_set_style_border_width(obj, width, selector);
    lv_obj_set_style_border_color(obj, color, selector);
    lv_obj_set_style_border_opa(obj, opa, selector);
}

void ui_obj_set_style_outline(lv_obj_t *obj, lv_style_selector_t selector, \
                            int32_t width, lv_color_t color, lv_opa_t opa, int32_t pad) {
    lv_obj_set_style_outline_width(obj, width, selector);
    lv_obj_set_style_outline_color(obj, color, selector);
    lv_obj_set_style_outline_opa(obj, opa, selector);
    lv_obj_set_style_outline_pad(obj, pad, selector);
}

void ui_obj_set_style_shadow(lv_obj_t *obj, lv_style_selector_t selector, \
                            int32_t width, lv_color_t color, lv_opa_t opa, \
                            int32_t offset_x, int32_t offset_y) {
    lv_obj_set_style_shadow_width(obj, width, selector);
    lv_obj_set_style_shadow_color(obj, color, selector);
    lv_obj_set_style_shadow_opa(obj, opa, selector);
    lv_obj_set_style_shadow_offset_x(obj, offset_x, selector);
    lv_obj_set_style_shadow_offset_y(obj, offset_y, selector);
}

void ui_obj_set_style_line(lv_obj_t *obj, lv_style_selector_t selector, \
                            int32_t width, lv_color_t color, lv_opa_t opa, \
                            int32_t dash_width, int32_t dash_gap, bool round) {
    lv_obj_set_style_line_width(obj, width, selector);
    lv_obj_set_style_line_color(obj, color, selector);
    lv_obj_set_style_line_opa(obj, opa, selector);
    lv_obj_set_style_line_dash_width(obj, dash_width, selector);
    lv_obj_set_style_line_dash_gap(obj, dash_gap, selector);
    lv_obj_set_style_line_rounded(obj, round, selector);
}

void ui_obj_set_style_arc(lv_obj_t *obj, lv_style_selector_t selector, \
                            int32_t width, lv_color_t color, lv_opa_t opa, \
                            bool round, const void *img) {
    lv_obj_set_style_arc_width(obj, width, selector);
    lv_obj_set_style_arc_color(obj, color, selector);
    lv_obj_set_style_arc_opa(obj, opa, selector);
    lv_obj_set_style_arc_rounded(obj, round, selector);
    if (img) lv_obj_set_style_arc_image_src(obj, img, selector);
}

// can be used for label and textarea
void ui_obj_set_style_text(lv_obj_t *obj, lv_style_selector_t selector, \
                            const lv_font_t *font, lv_text_align_t align, lv_color_t color, \
                            lv_opa_t opa, int32_t letter_space, int32_t line_space) {
    if (font) lv_obj_set_style_text_font(obj, font, selector);
    lv_obj_set_style_text_align(obj, align, selector);
    lv_obj_set_style_text_color(obj, color, selector);
    lv_obj_set_style_text_opa(obj, opa, selector);
    lv_obj_set_style_text_letter_space(obj, letter_space, selector);
    lv_obj_set_style_text_line_space(obj, line_space, selector);
}

//void lv_label_set_long_mode(lv_obj_t * obj, lv_label_long_mode_t long_mode)
//void lv_label_set_text(lv_obj_t * obj, const char * text)
//void lv_label_set_text_fmt(lv_obj_t * obj, const char * fmt, ...)

void ui_textarea_set_property(lv_obj_t *obj, \
                            const char *place_holder, bool one_line) {
    lv_textarea_set_placeholder_text(obj, place_holder);
    lv_textarea_set_one_line(obj, one_line);
}

//lv_textarea_set_text(*obj, text);
void lv_textarea_set_text_fmt(lv_obj_t * obj, const char * fmt, ...) {
    char buf[128];
    va_list args;

    va_start(args, fmt);
    int printed = vsprintf(buf, fmt, args);
    va_end(args);

    lv_textarea_set_text(obj, buf);
}

/////////////////////////////////////////////////////////////

void ui_creat_panel(lv_obj_t *parent, lv_obj_t **obj, int32_t x, int32_t y, int32_t width, int32_t height, lv_align_t align) {
    *obj = lv_obj_create(parent);
    
    ui_obj_remove_state_flag(*obj);
    ui_obj_set_style_basic(*obj, x, y, width, height, align);
    ui_obj_set_style_radius(*obj, LV_PART_MAIN, 0);
    ui_obj_set_style_bg(*obj, LV_PART_MAIN, lv_color_black(), LV_OPA_COVER, NULL, LV_OPA_COVER);
    ui_obj_set_style_border(*obj, LV_PART_MAIN, 0, lv_color_black(), LV_OPA_COVER);
}

void ui_create_label(lv_obj_t *parent, lv_obj_t **obj, int32_t x, int32_t y, int32_t width, int32_t height, \
                    const lv_font_t *font, lv_text_align_t align, lv_color_t color, lv_opa_t opa, \
                    int32_t letter_space, int32_t line_space, const char *str) {
    *obj = lv_label_create(parent);
    ui_obj_set_style_basic(*obj, x, y, width, height, LV_ALIGN_CENTER);
    ui_obj_set_style_text(*obj, LV_PART_MAIN, font, align, color, opa, letter_space, line_space);
    lv_label_set_text(*obj, str);
}

void ui_create_textarea(lv_obj_t *parent, lv_obj_t **obj, int32_t x, int32_t y, int32_t width, int32_t height, \
                        const lv_font_t *font, lv_text_align_t align, lv_color_t color, lv_opa_t opa, \
                        int32_t letter_space, int32_t line_space, const char *str, const char *placeholder) {
    *obj = lv_textarea_create(parent);
    ui_obj_set_style_basic(*obj, x, y, width, height, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(*obj, LV_PART_MAIN, lv_color_black(), LV_OPA_0, NULL, LV_OPA_COVER);
    ui_obj_set_style_border(*obj, LV_PART_MAIN, 0, lv_color_black(), LV_OPA_COVER);
    ui_obj_set_style_text(*obj, LV_PART_MAIN, font, align, color, opa, letter_space, line_space);
    ui_textarea_set_property(*obj, placeholder, true);
    lv_obj_add_flag(*obj, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_textarea_set_text(*obj, str);
}

void ui_create_image_pointer(lv_obj_t *parent, lv_obj_t **obj, int32_t x, int32_t y, int32_t width, int32_t height, \
                            const void *image, int32_t pivot_x, int32_t pivot_y, int32_t rotation) {
    *obj = lv_image_create(parent);
    ui_obj_set_style_basic(*obj, x, y, width, height, LV_ALIGN_CENTER);
    lv_image_set_src(*obj, image);
    lv_image_set_pivot(*obj, pivot_x, pivot_y);
    lv_image_set_rotation(*obj, rotation);
}

void ui_create_image_arc(lv_obj_t *parent, lv_obj_t **obj, int32_t x, int32_t y, int32_t width, int32_t height, \
                        int32_t angle_start, int32_t angle_end, lv_arc_mode_t mode, const void *img_main, const void *img_indicator) {
    *obj = lv_arc_create(parent);
    ui_obj_set_style_basic(*obj, x, y, width, height, LV_ALIGN_CENTER);
    lv_obj_remove_style(*obj, NULL, LV_PART_KNOB);
    ui_obj_remove_state_flag(*obj);
    lv_arc_set_bg_angles(*obj, angle_start, angle_end);
    lv_arc_set_mode(*obj, mode);
    ui_obj_set_style_arc(*obj, LV_PART_MAIN, 50, lv_color_black(), LV_OPA_COVER, false, img_main);
    ui_obj_set_style_arc(*obj, LV_PART_INDICATOR, 50, lv_color_black(), LV_OPA_COVER, false, img_indicator);

    lv_arc_set_value(*obj, 0);
}

///////////////////// ANIMATIONS ////////////////////

void _lv_image_set_rotation(void *obj, int32_t v) {
    lv_image_set_rotation((lv_obj_t*)obj, v);
}

void _lv_arc_set_value(void *obj, int32_t v) {
    lv_arc_set_value((lv_obj_t*)obj, v);
}

void _lv_slider_set_value(void *obj, int32_t v) {
    lv_slider_set_value((lv_obj_t*)obj, v, LV_ANIM_ON);
}

void _lv_bar_set_value(void *obj, int32_t v) {
    lv_bar_set_value(obj, v, LV_ANIM_ON);
}

lv_anim_t *ui_animation(lv_obj_t *obj, int start, int stop, int duration, int playback_duration, \
                                    int playback_delay, int repeat_delay, int repeat_cnt, \
                                    lv_anim_exec_xcb_t cb) {
    lv_anim_t a0;
    lv_anim_init(&a0);
    lv_anim_set_var(&a0, obj);
    lv_anim_set_values(&a0, start, stop);
    
    lv_anim_set_duration(&a0, duration);
    //lv_anim_set_delay(&a0, 0);

    if (playback_duration>0){
        lv_anim_set_playback_duration(&a0, playback_duration);
        lv_anim_set_playback_delay(&a0, playback_delay);
    }

    lv_anim_set_repeat_count(&a0, repeat_cnt);
    lv_anim_set_repeat_delay(&a0, repeat_delay);

    lv_anim_set_path_cb(&a0, lv_anim_path_ease_in_out);
    lv_anim_set_exec_cb(&a0, cb);
    
    return lv_anim_start(&a0);
}


/*
void ui_screen_change(lv_obj_t * target, lv_scr_load_anim_t fademode, int spd, int delay)
{
    lv_screen_load_anim(target, fademode, spd, delay, false);
}
*/
