#include "ui_page_git.h"

#include "../ui_helper.h"

extern bool git_updating;
extern time_t git_last_update_time;

DEFINE_IMG(git_released_loading);
DEFINE_IMG(git_released);
DEFINE_IMG(git_pressed);

// screen git
//void ui_event_git(lv_event_t * e);
lv_obj_t * ui_git;
lv_obj_t * ui_git_username;
lv_obj_t * ui_git_year;
lv_obj_t * ui_git_contri_panel;
lv_obj_t * ui_git_Jan;
lv_obj_t * ui_git_Feb;
lv_obj_t * ui_git_Mar;
lv_obj_t * ui_git_Apr;
lv_obj_t * ui_git_May;
lv_obj_t * ui_git_Jun;
lv_obj_t * ui_git_Jul;
lv_obj_t * ui_git_Aug;
lv_obj_t * ui_git_Sep;
lv_obj_t * ui_git_Oct;
lv_obj_t * ui_git_Nov;
lv_obj_t * ui_git_Dec;
lv_obj_t * ui_git_logo_button;
lv_obj_t * ui_git_loading_bar;

/*
void ui_event_git(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        _ui_screen_change(ui_Bili, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_Monitor, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
    if (target == ui_year && event_code == LV_EVENT_VALUE_CHANGED) {
        char buf[5];
        lv_dropdown_get_selected_str(ui_year, buf, sizeof(buf));
        ui_update_contribution_panel_by_year(atoi(buf));
    }
}
*/

void ui_git_init(void)
{
    ui_create_panel(NULL, &ui_git, 0, 0, 800, 480, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_git, LV_PART_MAIN, lv_color_black(), LV_OPA_COVER, NULL, LV_OPA_COVER);

    ui_create_textarea(ui_git, &ui_git_username, -240, -30, 250, LV_SIZE_CONTENT, \
                        &ui_font_ascii_32, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, \
                        3, 0, "", "Input Username");

    ui_git_year = lv_dropdown_create(ui_git);
    lv_dropdown_set_options(ui_git_year, "2023\n");
    ui_obj_set_style_basic(ui_git_year, 240, -30, 150, 40, LV_ALIGN_CENTER);
    ui_obj_set_style_text(ui_git_year, LV_PART_MAIN, &ui_font_ascii_32, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0);
    lv_obj_add_flag(ui_git_year, LV_OBJ_FLAG_EVENT_BUBBLE);     /// Flags

    int i = 0;
    double pos = -360;
    char *month_str[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nor", "Dec"};
    lv_obj_t *month_obj[] = {ui_git_Jan, ui_git_Feb, ui_git_Mar, ui_git_Apr, ui_git_May, ui_git_Jun, \
                            ui_git_Jul, ui_git_Aug, ui_git_Sep, ui_git_Oct, ui_git_Nov, ui_git_Dec};
    for (int i=0; i<12; i++) {
        ui_create_label(ui_git, &month_obj[i], (int)pos, 40, 50, LV_SIZE_CONTENT, &ui_font_ascii_14, \
                    LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, month_str[i]);
        pos += ((357+360)/12.0 + 2);
    }

    ui_create_panel(ui_git, &ui_git_contri_panel, 0, 100, 750, 105, LV_ALIGN_CENTER);

    ui_git_logo_button = lv_imagebutton_create(ui_git);
    ui_obj_set_style_basic(ui_git_logo_button, 0, -90, 177, 177, LV_ALIGN_CENTER);
    lv_imagebutton_set_src(ui_git_logo_button, LV_IMAGEBUTTON_STATE_RELEASED, NULL, IMG(git_released), NULL);
    lv_imagebutton_set_src(ui_git_logo_button, LV_IMAGEBUTTON_STATE_PRESSED, NULL, IMG(git_pressed), NULL);

    ui_git_loading_bar = lv_bar_create(ui_git);
    ui_obj_remove_state_flag(ui_git_loading_bar);
    ui_obj_set_style_basic(ui_git_loading_bar, 0, -90, 177, 178, LV_ALIGN_CENTER);
    ui_obj_set_style_radius(ui_git_loading_bar, LV_PART_INDICATOR, 0);
    ui_obj_set_style_bg(ui_git_loading_bar, LV_PART_MAIN, lv_color_hex(0), LV_OPA_0, IMG(git_released_loading), LV_OPA_COVER);
    ui_obj_set_style_bg(ui_git_loading_bar, LV_PART_INDICATOR, lv_color_hex(0), LV_OPA_0, IMG(git_released), LV_OPA_COVER);
#ifdef DEBUG
    ui_animation(ui_git_loading_bar, 0, 100, 1000, 1000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_bar_set_value);
#endif

//    lv_obj_add_event_cb(ui_Git, ui_event_Git, LV_EVENT_ALL, NULL);

}