/*
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#include "thread_warpper.h"
#include "lvgl.h"
#include "lv_drv_conf.h"
//#include "ui_helpers.h"
#include "ui_controller.h"
//#include "monitor.h"
// #include "git.h"
// #include "bili.h"
#include "tomato.h"
#include "config.h"
#include "util.h"


pthread_mutex_t lvgl_mutex = PTHREAD_MUTEX_INITIALIZER;

int main(void)
{
    time_t t;
    srand((unsigned)time(&t));
    time_t last_refresh_time = 0;
    
    lv_init();

#if USE_SDL
    init_simulator();
#elif USE_FBDEV
    init_fbdev();
#endif

#if LV_BUILD_EXAMPLES
    //lv_demo_widgets();
    //lv_demo_benchmark();
    //lv_example_freetype_1();
    //json_parser_test();
    //lv_example_btn_1();
    //lv_example_arc_2();
    //lv_example_roller_2();
    //lv_example_ffmpeg_2();
    //lv_example_sjpg_1();
    //lv_example_png_1();
    lv_example_label_1();
    while(1) {
        lv_timer_handler();
        usleep(5000);
    }
#else
    wait_for_timesync();
    config_init();
    ui_init();
    task_creat("monitor", 80, 32*1024, (FUNC)monitor_thread, NULL);
    task_creat("git", 80, 128*1024, (FUNC)git_thread, NULL);
    task_creat("bili", 80, 128*1024, (FUNC)bili_thread, NULL);
    task_creat("tomato", 80, 32*1024, (FUNC)tomato_thread, NULL);

    while(1) {
        pthread_mutex_lock(&lvgl_mutex);
        lv_timer_handler();
        pthread_mutex_unlock(&lvgl_mutex);
        usleep(5000);

        if (time(NULL) - last_refresh_time > 5) {
            last_refresh_time = time(NULL);
            sync();
        }
    }
    config_uninit();
#endif

    return 0;
}
*/

#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include "ui_helper.h"
#include "ui.h"

static void hal_init(void) {
#if defined ARM
    /*Linux frame buffer device init*/
    lv_display_t * disp = lv_linux_fbdev_create();
    lv_linux_fbdev_set_file(disp, "/dev/fb0");
    lv_indev_t *indev = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event1");
#elif defined X86
    lv_disp_t * disp = lv_sdl_window_create(800, 480);

    lv_group_t * g = lv_group_create();
    lv_group_set_default(g);

    lv_sdl_mouse_create();
    lv_indev_t * mousewheel = lv_sdl_mousewheel_create();
    lv_indev_set_group(mousewheel, lv_group_get_default());

    lv_indev_t * keyboard = lv_sdl_keyboard_create();
    lv_indev_set_group(keyboard, lv_group_get_default());
#endif
}

int main(void)
{
    lv_init();
    hal_init();

    /*Create a Demo*/
    //lv_demo_widgets();
    //lv_demo_widgets_start_slideshow();
    //lv_demo_benchmark();
    //lv_demo_stress();
    //lv_example_libjpeg_turbo_1();

    //lv_obj_t *obj = lv_label_create(lv_screen_active());
    //ui_obj_set_style_basic(obj, -20, 20, 300, LV_SIZE_CONTENT, LV_ALIGN_CENTER);
    //ui_obj_remove_state_flag(obj);
    //ui_obj_set_style_bg(obj, LV_STATE_DEFAULT, lv_color_hex(0x0), LV_OPA_20, NULL, LV_OPA_COVER);
    //ui_obj_set_style_text(obj, LV_STATE_DEFAULT, NULL, LV_TEXT_ALIGN_LEFT, lv_color_hex(0x00ff00), LV_OPA_COVER, 0, 5);
    //ui_obj_set_style_text(obj, LV_STATE_PRESSED, NULL, LV_TEXT_ALIGN_RIGHT, lv_color_hex(0xff0000), LV_OPA_COVER, 0, 5);
    //ui_obj_set_style_text(obj, LV_STATE_DEFAULT, NULL, LV_TEXT_ALIGN_CENTER, lv_color_hex(0xff0000), LV_OPA_COVER, 0, 5);
    //lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
    //lv_label_set_text_fmt(obj, "abcd %d", 123);

    //lv_obj_t *obj = lv_textarea_create(lv_screen_active());
    //ui_obj_set_style_basic(obj, -20, 20, 200, 200, LV_ALIGN_TOP_RIGHT);
    //ui_obj_remove_state_flag(obj);
    //ui_obj_set_style_text(obj, LV_STATE_DEFAULT, NULL, LV_TEXT_ALIGN_LEFT, lv_color_hex(0), LV_OPA_COVER, 0, 5);
    //ui_obj_set_style_text(obj, LV_STATE_HOVERED, NULL, LV_TEXT_ALIGN_RIGHT, lv_color_hex(0), LV_OPA_COVER, 0, 5);
    //ui_textarea_set_property(obj, "placeholder", true);
    //lv_textarea_set_text(obj, "abcdefggggggggggg 123");
    //lv_textarea_set_text_fmt(obj, "abc %4.2f", 12.3456);


    // DEFINE_IMG(git_released_loading);
    // DEFINE_IMG(git_released);
    // lv_obj_t *obj = lv_bar_create(lv_screen_active());
    // ui_obj_remove_state_flag(obj);
    // ui_obj_set_style_basic(obj, 0, 0, 177, 178, LV_ALIGN_CENTER);
    // ui_obj_set_style_radius(obj, LV_PART_INDICATOR, 0);
    // ui_obj_set_style_bg(obj, LV_PART_MAIN, lv_color_hex(0), LV_OPA_0, IMG(git_released_loading), LV_OPA_COVER);
    // ui_obj_set_style_bg(obj, LV_PART_INDICATOR, lv_color_hex(0), LV_OPA_0, IMG(git_released), LV_OPA_COVER);
    // ui_animation(obj, 0, 100, 1000, 1000, 200, 1000, LV_ANIM_REPEAT_INFINITE, anim_slider_cb);


    // lv_obj_t *obj = lv_arc_create(lv_screen_active());
    // ui_obj_set_style_basic(obj, 0, 0, 300, 300, LV_ALIGN_CENTER);
    // ui_obj_set_style_arc(obj, LV_PART_MAIN, 50, lv_color_hex(0xff0000), LV_OPA_COVER, false, NULL);
    // ui_obj_set_style_arc(obj, LV_PART_INDICATOR, 50, lv_color_hex(0x00ff00), LV_OPA_COVER, false, NULL);
    // //ui_obj_set_style_arc(obj, LV_PART_KNOB, 5, lv_color_hex(0x0000ff), LV_OPA_COVER, false, NULL);
    // lv_obj_remove_style(obj, NULL, LV_PART_KNOB);

    // lv_obj_t *rec = lv_obj_create(lv_screen_active());
    // ui_obj_set_style_basic(rec, 0, 0, 50, 50, LV_ALIGN_CENTER);
    // ui_obj_set_style_radius(rec, LV_PART_MAIN, 0);
    // ui_obj_set_style_bg(rec, LV_PART_MAIN, lv_color_hex(0x0000ff), LV_OPA_100, NULL, LV_OPA_COVER);
    // ui_obj_set_style_border(rec, LV_PART_MAIN, 0, lv_color_hex(0), LV_OPA_COVER);
    
    // lv_arc_align_obj_to_angle(obj, rec, 40);
    // //lv_arc_rotate_obj_to_angle(obj, rec, 50);
 
 
 /*
    lv_obj_t *ui_Monitor = lv_obj_create(lv_screen_active());
    ui_obj_set_style_basic(ui_Monitor, 0, 0, 800, 480, LV_ALIGN_CENTER);
    ui_obj_set_style_radius(ui_Monitor, LV_PART_MAIN, 0);
    ui_obj_set_style_border(ui_Monitor, LV_PART_MAIN, 2, lv_color_hex(0xffffff), LV_OPA_0);
    lv_obj_set_style_bg_color(ui_Monitor, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_Monitor, LV_OBJ_FLAG_SCROLLABLE);

    DEFINE_IMG(mem_usage1);
    DEFINE_IMG(mem_usage2);
    lv_obj_t *obj = lv_arc_create(ui_Monitor);
    ui_obj_set_style_basic(obj, 0, 0, 295, 295, LV_ALIGN_CENTER);
    lv_arc_set_value(obj, 0);
    lv_arc_set_bg_angles(obj, 54, 126);
    lv_arc_set_mode(obj, LV_ARC_MODE_REVERSE);
    ui_obj_set_style_arc(obj, LV_PART_MAIN, 50, lv_color_hex(0), LV_OPA_COVER, false, IMG(mem_usage1));
    ui_obj_set_style_arc(obj, LV_PART_INDICATOR, 50, lv_color_hex(0), LV_OPA_COVER, false, IMG(mem_usage2));
    lv_obj_remove_style(obj, NULL, LV_PART_KNOB);
    ui_animation(obj, 0, 100, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, anim_arc_cb);
*/


/*
    lv_obj_t * scale = lv_scale_create(lv_screen_active());
    ui_obj_set_style_basic(scale, 2, 20, 240, 240, LV_ALIGN_CENTER);
    lv_scale_set_label_show(scale, false);
    lv_scale_set_mode(scale, LV_SCALE_MODE_ROUND_INNER);

    lv_scale_set_total_tick_count(scale, 11);
    lv_scale_set_major_tick_every(scale, 5);

    lv_obj_set_style_length(scale, 5, LV_PART_ITEMS);
    lv_obj_set_style_length(scale, 10, LV_PART_INDICATOR);
    lv_scale_set_range(scale, 0, 100);
    lv_scale_set_angle_range(scale, 74);
    lv_scale_set_rotation(scale, 180-(74/2+90));



    static lv_style_t line_style1;
    lv_style_init(&line_style1);
    lv_style_set_arc_color(&line_style1, lv_palette_darken(LV_PALETTE_GREEN, 3));
    lv_style_set_arc_width(&line_style1, 4U);
    lv_obj_add_style(scale, &line_style1, LV_PART_MAIN);

    static lv_style_t line_style2;
    lv_style_init(&line_style2);

    lv_style_set_arc_color(&line_style2, lv_palette_darken(LV_PALETTE_YELLOW, 3));
    lv_style_set_arc_width(&line_style2, 4U);
    lv_scale_section_t * section_yellow = lv_scale_add_section(scale);
    lv_scale_section_set_range(section_yellow, 20, 40);
    lv_scale_section_set_style(section_yellow, LV_PART_MAIN, &line_style2);

    static lv_style_t line_style3;
    lv_style_init(&line_style3);

    lv_style_set_arc_color(&line_style3, lv_palette_darken(LV_PALETTE_RED, 3));
    lv_style_set_arc_width(&line_style3, 4U);
    lv_scale_section_t * section_red = lv_scale_add_section(scale);
    lv_scale_section_set_range(section_red, 0, 20);
    lv_scale_section_set_style(section_red, LV_PART_MAIN, &line_style3);



    static lv_style_t indicator_style;
    lv_style_init(&indicator_style);

    lv_style_set_line_color(&indicator_style, lv_color_white());
    lv_style_set_length(&indicator_style, 8);
    lv_style_set_line_width(&indicator_style, 2);
    lv_obj_add_style(scale, &indicator_style, LV_PART_INDICATOR);

    static lv_style_t minor_ticks_style;
    lv_style_init(&minor_ticks_style);
    lv_style_set_line_color(&minor_ticks_style, lv_color_white());
    lv_style_set_length(&minor_ticks_style, 6);
    lv_style_set_line_width(&minor_ticks_style, 2);
    lv_obj_add_style(scale, &minor_ticks_style, LV_PART_ITEMS);

    lv_point_precise_t minute_hand_points[2];
    minute_hand = lv_line_create(scale);
    lv_line_set_points_mutable(minute_hand, minute_hand_points, 2);

    lv_obj_set_style_line_width(minute_hand, 3, 0);
    lv_obj_set_style_line_rounded(minute_hand, true, 0);
    lv_obj_set_style_line_color(minute_hand, lv_color_white(), 0);
    lv_scale_set_line_needle_value(scale, minute_hand, 100, 80);
    ui_animation(scale, 0, 100, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, anim_scale_cb);
*/

    //lv_obj_set_ext_click_area(obj, 10);


    ui_init();
    while(1) {
        lv_timer_handler();
        usleep(5000);
        // if (!(i++ % 1000)) {
        //     lv_label_set_text_fmt(label, "abcdefggggggggggg %d", i);
        //     LV_LOG_INFO("%d\n", i);
        // }
    }

    return 0;
}
