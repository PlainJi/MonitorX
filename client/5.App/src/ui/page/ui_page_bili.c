#include "ui_page_bili.h"

#include "../ui_helper.h"
#include "../ui.h"

extern bool bili_updating;
extern time_t bili_last_update_relation;
extern time_t bili_last_update_stat;

DEFINE_IMG(bili_released_loading);
DEFINE_IMG(bili_released);
DEFINE_IMG(bili_pressed);
DEFINE_IMG(face_unknown);
DEFINE_IMG(like);
//DEFINE_IMG(coin);
DEFINE_IMG(video);
//DEFINE_IMG(favorite);
DEFINE_IMG(follower);

// screen bili
//void ui_event_Bili(lv_event_t * e);
lv_obj_t * ui_bili;
lv_obj_t * ui_bili_username;
lv_obj_t * ui_bili_userid;
lv_obj_t * ui_bili_title;
lv_obj_t * ui_bili_face_panel;
lv_obj_t * ui_bili_face;
lv_obj_t * ui_bili_like_image;
lv_obj_t * ui_bili_video_image;
lv_obj_t * ui_bili_follower_image;
//lv_obj_t * ui_bili_coin_image;
//lv_obj_t * ui_bili_favorite_image;
lv_obj_t * ui_bili_like_label;
lv_obj_t * ui_bili_video_label;
lv_obj_t * ui_bili_follower_label;
//lv_obj_t * ui_bili_coin_label;
//lv_obj_t * ui_bili_favorite_label;
lv_obj_t * ui_bili_sign;
lv_obj_t * ui_bili_logo_button;
lv_obj_t * ui_bili_loading_bar;


// void ui_event_Bili(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
//         _ui_screen_change(ui_Tomato, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
//     }
//     if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
//         _ui_screen_change(ui_Git, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
//     }
// }

void ui_bili_init(void)
{
    ui_create_panel(NULL, &ui_bili, 0, 0, 800, 480, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_bili, LV_PART_MAIN, lv_color_black(), LV_OPA_COVER, NULL, LV_OPA_COVER);

    ui_create_label(ui_bili, &ui_bili_userid, -295, -217, 200, LV_SIZE_CONTENT, lv_font_fzht_14, \
                    LV_TEXT_ALIGN_LEFT, lv_color_hex(0x5B5B5B), LV_OPA_COVER, 0, 0, "ID:");
    ui_create_label(ui_bili, &ui_bili_title, 20, 20, 300, LV_SIZE_CONTENT, lv_font_fzht_14, \
                    LV_TEXT_ALIGN_RIGHT, lv_color_hex(0x5B5B5B), LV_OPA_COVER, 0, 0, "2023百大UP主、2023年度最高人气奖UP主、2022年度多元创新奖UP主");
    lv_obj_set_align(ui_bili_title, LV_ALIGN_TOP_RIGHT);
    lv_label_set_long_mode(ui_bili_title, LV_LABEL_LONG_SCROLL_CIRCULAR);
    ui_create_textarea(ui_bili, &ui_bili_username, -240, -72, 250, LV_SIZE_CONTENT, lv_font_fzht_32, LV_TEXT_ALIGN_CENTER, \
                        lv_color_white(), LV_OPA_COVER, 1, 0, "", "Input UserID");

    ui_create_image(ui_bili, &ui_bili_face, 240, -72, 60, 60, 20, true, LV_IMAGE_ALIGN_STRETCH, IMG(face_unknown));
    ui_create_image(ui_bili, &ui_bili_like_image,    -240, 40, 48, 48, 20, false, LV_IMAGE_ALIGN_DEFAULT, IMG(like));
    ui_create_image(ui_bili, &ui_bili_video_image,      0, 40, 48, 48, 20, false, LV_IMAGE_ALIGN_DEFAULT, IMG(video));
    ui_create_image(ui_bili, &ui_bili_follower_image, 240, 40, 48, 48, 20, false, LV_IMAGE_ALIGN_DEFAULT, IMG(follower));

    ui_create_label(ui_bili, &ui_bili_like_label,    -240, 110, 220, LV_SIZE_CONTENT, &ui_font_ascii_32, \
                    LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "0");
    ui_create_label(ui_bili, &ui_bili_video_label,      0, 110, 220, LV_SIZE_CONTENT, &ui_font_ascii_32, \
                    LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "0");
    ui_create_label(ui_bili, &ui_bili_follower_label, 240, 110, 220, LV_SIZE_CONTENT, &ui_font_ascii_32, \
                    LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "0");

    ui_create_label(ui_bili, &ui_bili_sign, 0, 170, 500, LV_SIZE_CONTENT, lv_font_fzht_24, \
                    LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "保持热爱，奔赴星海。");
    lv_label_set_long_mode(ui_bili_sign, LV_LABEL_LONG_SCROLL_CIRCULAR);

    ui_bili_logo_button = lv_imagebutton_create(ui_bili);
    ui_obj_set_style_basic(ui_bili_logo_button, 0, -90, 160, 161, LV_ALIGN_CENTER);
    lv_imagebutton_set_src(ui_bili_logo_button, LV_IMAGEBUTTON_STATE_RELEASED, NULL, IMG(bili_released), NULL);
    lv_imagebutton_set_src(ui_bili_logo_button, LV_IMAGEBUTTON_STATE_PRESSED, NULL, IMG(bili_pressed), NULL);

    ui_bili_loading_bar = lv_bar_create(ui_bili);
    ui_obj_remove_state_flag(ui_bili_loading_bar);
    ui_obj_set_style_basic(ui_bili_loading_bar, 0, -90, 160, 161, LV_ALIGN_CENTER);
    ui_obj_set_style_radius(ui_bili_loading_bar, LV_PART_INDICATOR, 0);
    ui_obj_set_style_bg(ui_bili_loading_bar, LV_PART_MAIN, lv_color_hex(0), LV_OPA_0, IMG(bili_released_loading), LV_OPA_COVER);
    ui_obj_set_style_bg(ui_bili_loading_bar, LV_PART_INDICATOR, lv_color_hex(0), LV_OPA_0, IMG(bili_released), LV_OPA_COVER);

    // lv_obj_add_event_cb(ui_Bili, ui_event_Bili, LV_EVENT_ALL, NULL);
}