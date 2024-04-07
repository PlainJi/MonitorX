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
    //lv_example_scale_4();

    ui_init();
    while(1) {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}
