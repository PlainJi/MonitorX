#pragma once

#include "lvgl/lvgl.h"

#define INVALID_ANGLE       (INT32_MAX)
#define OBJ_DEFAULT_BG_COLOR    lv_color_hex(0xFFFFFF)
#define OBJ_DEFAULT_FLAG    (LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |  \
                            LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE |        \
                            LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN)

#define DEFINE_IMG(name)    const char *ui_img_##name##_png = "A:./res/image/"#name".png"
#define IMG(name)           ui_img_##name##_png

LV_FONT_DECLARE(ui_font_ascii_14);
LV_FONT_DECLARE(ui_font_ascii_20);
LV_FONT_DECLARE(ui_font_ascii_24);
LV_FONT_DECLARE(ui_font_ascii_28);
LV_FONT_DECLARE(ui_font_ascii_32);
LV_FONT_DECLARE(ui_font_ascii_38);
LV_FONT_DECLARE(ui_font_ascii_40);

void ui_obj_remove_state_flag(lv_obj_t *obj);

void ui_obj_set_style_basic(lv_obj_t *obj, \
                        int32_t x, int32_t y, int32_t width, int32_t height, \
                        lv_align_t align);

void ui_obj_set_style_radius(lv_obj_t *obj, lv_style_selector_t selector, int32_t radius);

void ui_obj_set_style_bg(lv_obj_t *obj, lv_style_selector_t selector, \
                        lv_color_t color, lv_opa_t opa, \
                        const void *img, lv_opa_t img_opa);

void ui_obj_set_style_border(lv_obj_t *obj, lv_style_selector_t selector, \
                            int32_t width, lv_color_t color, lv_opa_t opa);

void ui_obj_set_style_outline(lv_obj_t *obj, lv_style_selector_t selector, \
                            int32_t width, lv_color_t color, lv_opa_t opa, int32_t pad);

void ui_obj_set_style_shadow(lv_obj_t *obj, lv_style_selector_t selector, \
                            int32_t width, lv_color_t color, lv_opa_t opa, \
                            int32_t offset_x, int32_t offset_y);

void ui_obj_set_style_line(lv_obj_t *obj, lv_style_selector_t selector, \
                            int32_t width, lv_color_t color, lv_opa_t opa, \
                            int32_t dash_width, int32_t dash_gap, bool round);

void ui_obj_set_style_arc(lv_obj_t *obj, lv_style_selector_t selector, \
                            int32_t width, lv_color_t color, lv_opa_t opa, \
                            bool round, const void *img);

// can be used for label and textarea
void ui_obj_set_style_text(lv_obj_t *obj, lv_style_selector_t selector, \
                            const lv_font_t *font, lv_text_align_t align, lv_color_t color, \
                            lv_opa_t opa, int32_t letter_space, int32_t line_space);

//void lv_label_set_long_mode(lv_obj_t * obj, lv_label_long_mode_t long_mode)
//void lv_label_set_text(lv_obj_t * obj, const char * text)
//void lv_label_set_text_fmt(lv_obj_t * obj, const char * fmt, ...)

void ui_textarea_set_property(lv_obj_t *obj, \
                            const char *place_holder, bool one_line);

void lv_textarea_set_text_fmt(lv_obj_t * obj, const char * fmt, ...);

///////////////////////////////////////////////////

void ui_create_panel(lv_obj_t *parent, lv_obj_t **obj, int32_t x, int32_t y, int32_t width, int32_t height, lv_align_t align);

void ui_create_label(lv_obj_t *parent, lv_obj_t **obj, int32_t x, int32_t y, int32_t width, int32_t height, lv_align_t align, \
                    const lv_font_t *font, lv_text_align_t text_align, lv_color_t color, lv_opa_t opa, \
                    int32_t letter_space, int32_t line_space, const char *str);

void ui_create_textarea(lv_obj_t *parent, lv_obj_t **obj, int32_t x, int32_t y, int32_t width, int32_t height, \
                        const lv_font_t *font, lv_text_align_t align, lv_color_t color, lv_opa_t opa, \
                        int32_t letter_space, int32_t line_space, const char *str, const char *placeholder);

void ui_create_image_pointer(lv_obj_t *parent, lv_obj_t **obj, int32_t x, int32_t y, int32_t width, int32_t height, \
                    const void *image, int32_t pivot_x, int32_t pivot_y, int32_t rotation);

void ui_create_image_arc(lv_obj_t *parent, lv_obj_t **obj, int32_t x, int32_t y, int32_t width, int32_t height, \
                        int32_t angle_start, int32_t angle_end, lv_arc_mode_t mode, const void *img_main, const void *img_indicator);

void ui_create_image(lv_obj_t *parent, lv_obj_t **obj, int32_t x, int32_t y, int32_t width, int32_t height, \
                        int32_t radius, bool clip_corner, lv_image_align_t align, const void *image);


void ui_create_roller(lv_obj_t *parent, lv_obj_t **obj, int32_t x, int32_t y, int32_t width,  int32_t vis_row, \
                        lv_color_t color, lv_opa_t opa, const void *img, lv_opa_t img_opa, \
                        lv_font_t *font, lv_color_t font_color, lv_text_align_t text_align, \
                        const char *options, lv_roller_mode_t roller_mode);

///////////////////////////////////////////////////

void _lv_image_set_rotation(void *obj, int32_t v);
void _lv_arc_set_value(void *obj, int32_t v);
void _lv_slider_set_value(void *obj, int32_t v);
void _lv_bar_set_value(void *obj, int32_t v);

lv_anim_t *ui_animation(lv_obj_t *obj, int start, int stop, int duration, int playback_duration, \
                                    int playback_delay, int repeat_delay, int repeat_cnt, \
                                    lv_anim_exec_xcb_t cb);
void ui_animation_for_pointer(lv_obj_t *obj, int new_angle, int time);
void ui_animation_for_arc(lv_obj_t *obj, int new_angle, int time);