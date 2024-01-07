#include "lvgl.h"
#include "lv_drv_conf.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include "thread_warpper.h"
#include "ui.h"
#include "ui_helpers.h"
#include "ui_controller.h"
#include "monitor.h"
#include "git.h"
#include "bili.h"
#include "tomato.h"
#include "config.h"
#include "util.h"

// #include "demos/lv_demos.h"
// #include "examples/lv_examples.h"

#if USE_SDL
#include <SDL2/SDL.h>
#include "lv_drivers/sdl/sdl_common.h"
#define DISP_BUF_SIZE (HOR_RES*VER_RES)

static void init_simulator(void)
{
  sdl_init();
  /* Tick init.
   * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about
   * how much time were elapsed Create an SDL thread to do this*/
  //SDL_CreateThread(tick_thread, "tick", NULL);

  // Create a display buffer
  static lv_disp_draw_buf_t disp_buf;
  static lv_color_t buf1[DISP_BUF_SIZE];
  static lv_color_t buf2[DISP_BUF_SIZE];
  lv_disp_draw_buf_init(&disp_buf, buf1, buf2, DISP_BUF_SIZE);

  // Create a display
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.draw_buf = &disp_buf;
  disp_drv.flush_cb = sdl_display_flush;
  disp_drv.hor_res = SDL_HOR_RES;
  disp_drv.ver_res = SDL_VER_RES;
  disp_drv.antialiasing = 1;

  lv_disp_t * disp = lv_disp_drv_register(&disp_drv);

  lv_theme_t * th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp, th);

  lv_group_t * g = lv_group_create();
  lv_group_set_default(g);

  // Add the mouse as input device
  // Use the 'mouse' driver which reads the PC's mouse
  static lv_indev_drv_t indev_drv_1;
  lv_indev_drv_init(&indev_drv_1);
  indev_drv_1.type = LV_INDEV_TYPE_POINTER;
  // This function will be called periodically (by the library) to get the mouse position and state
  indev_drv_1.read_cb = sdl_mouse_read;
  lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

  static lv_indev_drv_t indev_drv_2;
  lv_indev_drv_init(&indev_drv_2);
  indev_drv_2.type = LV_INDEV_TYPE_KEYPAD;
  indev_drv_2.read_cb = sdl_keyboard_read;
  lv_indev_t *kb_indev = lv_indev_drv_register(&indev_drv_2);
  lv_indev_set_group(kb_indev, g);

  static lv_indev_drv_t indev_drv_3;
  lv_indev_drv_init(&indev_drv_3);
  indev_drv_3.type = LV_INDEV_TYPE_ENCODER;
  indev_drv_3.read_cb = sdl_mousewheel_read;
  lv_indev_t * enc_indev = lv_indev_drv_register(&indev_drv_3);
  lv_indev_set_group(enc_indev, g);

  // Set a cursor for the mouse
  LV_IMG_DECLARE(mouse_cursor_icon);                        /*Declare the image file.*/
  lv_obj_t * cursor_obj = lv_img_create(lv_scr_act());      /*Create an image object for the cursor */
  lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
  lv_indev_set_cursor(mouse_indev, cursor_obj);             /*Connect the image  object to the driver*/
}

#elif USE_FBDEV
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#define DISP_BUF_SIZE (HOR_RES*VER_RES)

static void init_fbdev(void)
{
    // display
    // Linux frame buffer device init
    fbdev_init();
    // A small buffer for LittlevGL to draw the screen's content
    static lv_color_t buf1[DISP_BUF_SIZE];
    static lv_color_t buf2[DISP_BUF_SIZE];

    // Initialize a descriptor for the buffer
    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, DISP_BUF_SIZE);

    // Initialize and register a display driver
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = fbdev_flush;
    disp_drv.hor_res    = HOR_RES;
    disp_drv.ver_res    = VER_RES;
    disp_drv.sw_rotate	= 1;
    //disp_drv.rotated	= LV_DISP_ROT_270;
    lv_disp_drv_register(&disp_drv);

    // input
    evdev_init();
    static lv_indev_drv_t indev_drv_1;
    lv_indev_drv_init(&indev_drv_1);                        /*Basic initialization*/
    indev_drv_1.type = LV_INDEV_TYPE_POINTER;
    //indev_drv_1.type = LV_INDEV_TYPE_NONE;
    //indev_drv_1.type = LV_INDEV_TYPE_KEYPAD;
    // This function will be called periodically (by the library) to get the mouse position and state
    indev_drv_1.read_cb = evdev_read;
    lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);
    // Set a cursor for the mouse
    LV_IMG_DECLARE(mouse_cursor_icon)
    lv_obj_t * cursor_obj = lv_img_create(lv_scr_act());    /*Create an image object for the cursor */
    lv_img_set_src(cursor_obj, &mouse_cursor_icon);         /*Set the image source*/
    lv_indev_set_cursor(mouse_indev, cursor_obj);           /*Connect the image  object to the driver*/
}
#endif

pthread_mutex_t lvgl_mutex = PTHREAD_MUTEX_INITIALIZER;
void wait_for_timesync();

void wait_for_timesync() {
    int year = 1970;
    time_t t = 0;
    while (year == 1970) {
        printf("checking timesync...\n");
        t = time(NULL);
	    struct tm *s_tm = localtime(&t);
	    year = s_tm->tm_year+1900;
        sleep(1);
    }
    printf("%s\n", getasctime(&t));
}

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
    lv_demo_benchmark();
    //lv_example_freetype_1();
    //json_parser_test();
    //lv_example_btn_1();
    //lv_example_arc_2();
    //lv_example_roller_2();
    //lv_example_ffmpeg_2();
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

/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void);

uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = ((uint64_t)tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    uint64_t now_ms;
    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    now_ms = ((uint64_t)tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    return (uint32_t)(now_ms - start_ms);
}

