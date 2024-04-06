



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
void ui_event_Bili(lv_event_t * e);
lv_obj_t * ui_Bili;
lv_obj_t * ui_TextBiliUserName;
lv_obj_t * ui_TextBiliUserID;
lv_obj_t * ui_TextBiliTitle;
lv_obj_t * ui_ImageFaceContent;
lv_obj_t * ui_ImageFace;
lv_obj_t * ui_ImageLike;
lv_obj_t * ui_ImageVideo;
lv_obj_t * ui_ImageFollower;
//lv_obj_t * ui_ImageCoin;
//lv_obj_t * ui_ImageFavorite;
lv_obj_t * ui_TextLike;
lv_obj_t * ui_TextVideo;
lv_obj_t * ui_TextFollower;
//lv_obj_t * ui_TextCoin;
//lv_obj_t * ui_TextFavorite;
lv_obj_t * ui_TextSign;
lv_obj_t * ui_Bili_ImgButtonLogo;
lv_obj_t * ui_Bili_Slider_Loading;




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

void ui_Bili_screen_init(void)
{
    ui_Bili = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Bili, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_Bili, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bili, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_creat_text_area(ui_Bili, &ui_TextBiliUserID, -295, -217, 200, "ID:", "User ID", NULL);
    lv_obj_set_style_text_align(ui_TextBiliUserID, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_TextBiliUserID, lv_color_hex(0x5B5B5B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui_TextBiliUserID, &style_font_fzht_14, 0);
    
    ui_TextBiliTitle = lv_label_create(ui_Bili);
    lv_obj_set_align(ui_TextBiliTitle, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_width(ui_TextBiliTitle, 300);
    lv_obj_set_height(ui_TextBiliTitle, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_TextBiliTitle, 20);
    lv_obj_set_y(ui_TextBiliTitle, 20);
    lv_label_set_long_mode(ui_TextBiliTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_TextBiliTitle, "");    // 2023百大UP主、2023年度最高人气奖UP主、2022年度多元创新奖UP主
    lv_obj_set_style_text_align(ui_TextBiliTitle, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_TextBiliTitle, lv_color_hex(0x5B5B5B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui_TextBiliTitle, &style_font_fzht_14, 0);

    ui_creat_text_area(ui_Bili, &ui_TextBiliUserName, -240, -72, 250, "", "Input UserID", NULL);
    lv_obj_set_style_text_letter_space(ui_TextBiliUserName, 1, 0);
    lv_obj_add_style(ui_TextBiliUserName, &style_font_fzht_32, 0);
    lv_obj_add_flag(ui_TextBiliUserName, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE);

    ui_ImageFaceContent = lv_obj_create(ui_Bili);
    lv_obj_clear_flag(ui_ImageFaceContent, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_align(ui_ImageFaceContent, LV_ALIGN_CENTER);
    lv_obj_set_width(ui_ImageFaceContent, 60);
    lv_obj_set_height(ui_ImageFaceContent, 60);
    lv_obj_set_x(ui_ImageFaceContent, 240);
    lv_obj_set_y(ui_ImageFaceContent, -72);
    lv_obj_set_style_radius(ui_ImageFaceContent, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(ui_ImageFaceContent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ImageFaceContent, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_ImageFace = lv_img_create(ui_ImageFaceContent);
    lv_obj_set_align(ui_ImageFace, LV_ALIGN_CENTER);
    lv_img_set_src(ui_ImageFace, IMG(face_unknown));
    lv_img_set_zoom(ui_ImageFace, (uint16_t)(60*256/(((lv_img_t*)ui_ImageFace)->w)));
    lv_obj_set_style_radius(ui_ImageFace, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui_ImageFace, true, LV_PART_MAIN);

    ui_creat_img(ui_Bili, &ui_ImageLike, -240,      40, 48, 48, IMG(like));
    ui_creat_img(ui_Bili, &ui_ImageVideo, 0,        40, 48, 48, IMG(video));
    ui_creat_img(ui_Bili, &ui_ImageFollower, 240,   40, 46, 48, IMG(follower));

    ui_creat_text_area(ui_Bili, &ui_TextLike, -240,     110, 220, "0", "", &ui_font_ascii_32);
    ui_creat_text_area(ui_Bili, &ui_TextVideo, 0,       110, 220, "0", "", &ui_font_ascii_32);
    ui_creat_text_area(ui_Bili, &ui_TextFollower, 240,  110, 220, "0", "", &ui_font_ascii_32);

    ui_TextSign = lv_label_create(ui_Bili);
    lv_obj_set_align(ui_TextSign, LV_ALIGN_CENTER);
    lv_obj_set_width(ui_TextSign, 500);
    lv_obj_set_height(ui_TextSign, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_TextSign, 0);
    lv_obj_set_y(ui_TextSign, 170);
    lv_label_set_long_mode(ui_TextSign, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_TextSign, "");     // 无限进步！｜商务合作请联系WX：ysjfBD（添加麻烦备注公司、咨询内容）
    lv_obj_add_style(ui_TextSign, &style_font_fzht_24, 0);
    lv_obj_set_style_text_align(ui_TextSign, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Bili_ImgButtonLogo = lv_imgbtn_create(ui_Bili);
    lv_imgbtn_set_src(ui_Bili_ImgButtonLogo, LV_IMGBTN_STATE_RELEASED, NULL, IMG(bili_released), NULL);
    lv_imgbtn_set_src(ui_Bili_ImgButtonLogo, LV_IMGBTN_STATE_PRESSED, NULL, IMG(bili_pressed), NULL);
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
    lv_obj_set_style_bg_img_src(ui_Bili_Slider_Loading, IMG(bili_released_loading), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Bili_Slider_Loading, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bili_Slider_Loading, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bili_Slider_Loading, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Bili_Slider_Loading, IMG(bili_released), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Bili_Slider_Loading, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bili_Slider_Loading, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bili_Slider_Loading, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Bili, ui_event_Bili, LV_EVENT_ALL, NULL);
}