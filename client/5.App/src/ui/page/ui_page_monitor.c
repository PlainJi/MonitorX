#include "ui_page_monitor.h"

#include <stdio.h>
#include <string.h>
#include "../ui.h"

DEFINE_IMG(bg);
DEFINE_IMG(small_pointer);
DEFINE_IMG(big_pointer);
DEFINE_IMG(mem_usage1);
DEFINE_IMG(mem_usage2);

lv_obj_t * ui_monitor_connect_panel;
lv_obj_t * ui_monitor_disconnect_panel;
lv_obj_t * ui_disconnect_arc;
lv_obj_t * ui_disconnect_text;
lv_anim_t * ui_disconnect_anim;

lv_obj_t * ui_monitor_cpu_panel;
lv_obj_t * ui_cpu_model;
lv_obj_t * ui_cpu_usage_pointer;
lv_obj_t * ui_cpu_usage_percent;
lv_obj_t * ui_cpu_frequency;
lv_obj_t * ui_cpu_mem_capacity;
lv_obj_t * ui_cpu_mem_usage_arc;
lv_obj_t * ui_cpu_mem_usage_percent;
lv_obj_t * ui_cpu_temp_pointer;

lv_obj_t * ui_monitor_gpu_panel;
lv_obj_t * ui_gpu_model;
lv_obj_t * ui_gpu_usage_pointer;
lv_obj_t * ui_gpu_usage_percent;
lv_obj_t * ui_gpu_frequency;
lv_obj_t * ui_gpu_mem_capacity;
lv_obj_t * ui_gpu_mem_usage_arc;
lv_obj_t * ui_gpu_mem_usage_percent;
lv_obj_t * ui_gpu_temp_pointer;

lv_obj_t * ui_monitor_middle_panel;
lv_obj_t * ui_middle_time;
lv_obj_t * ui_middle_week;
lv_obj_t * ui_middle_date;
lv_obj_t * ui_middle_upload;
lv_obj_t * ui_middle_download;
lv_obj_t * ui_middle_read;
lv_obj_t * ui_middle_write;



// void ui_event_Monitor(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);

//     if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
//         _ui_screen_change(ui_Git, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
//     }
//     if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
//         _ui_screen_change(ui_Tomato, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
//     }
// }

void ui_monitor_panel_disconnected(void) {
	// Panel Disconnected
    ui_create_panel(NULL, &ui_monitor_disconnect_panel, 0, 0, 800, 480, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_monitor_disconnect_panel, LV_PART_MAIN, lv_color_black(), LV_OPA_COVER, IMG(bg), LV_OPA_20);
    ui_disconnect_text = lv_label_create(ui_monitor_disconnect_panel);
    ui_obj_set_style_basic(ui_disconnect_text, 0, 100, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER);
    ui_obj_set_style_text(ui_disconnect_text, LV_PART_MAIN, &ui_font_ascii_20, LV_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 2, 0);
    lv_label_set_text(ui_disconnect_text, "Disconnect");
    ui_disconnect_arc = lv_arc_create(ui_monitor_disconnect_panel);
    ui_obj_set_style_basic(ui_disconnect_arc, 0, 0, 100, 100, LV_ALIGN_CENTER);
    lv_arc_set_rotation(ui_disconnect_arc, 270);
    lv_arc_set_bg_angles(ui_disconnect_arc, 0, 360);
    lv_obj_remove_style(ui_disconnect_arc, NULL, LV_PART_KNOB);

	ui_animation(ui_disconnect_arc, 0, 100, 1000, -1, 0, 500, LV_ANIM_REPEAT_INFINITE, _lv_arc_set_value);
}

void ui_monitor_panel_connected(void) {
	// Panel Connected
    ui_create_panel(NULL, &ui_monitor_connect_panel, 0, 0, 800, 480, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_monitor_connect_panel, LV_PART_MAIN, lv_color_black(), LV_OPA_80, IMG(bg), LV_OPA_COVER);

    ///////////////////--CPU--/////////////////////////

    ui_create_panel(ui_monitor_connect_panel, &ui_monitor_cpu_panel, -196, 0, 388, 344, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_monitor_cpu_panel, LV_PART_MAIN, lv_color_black(), LV_OPA_0, NULL, LV_OPA_0);
    ui_create_label(ui_monitor_cpu_panel, &ui_cpu_model, -40, -145, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_24, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 2, 0, "CPU");
    ui_create_label(ui_monitor_cpu_panel, &ui_cpu_usage_percent, -40, 21, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_38, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");
    ui_create_label(ui_monitor_cpu_panel, &ui_cpu_frequency, -40, 45, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");
    ui_create_label(ui_monitor_cpu_panel, &ui_cpu_mem_usage_percent, -40, 109, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_28, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");
    ui_create_label(ui_monitor_cpu_panel, &ui_cpu_mem_capacity, -40, 145, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");

    ui_create_image_pointer(ui_monitor_cpu_panel, &ui_cpu_usage_pointer, \
                            -114, 17, LV_SIZE_CONTENT, LV_SIZE_CONTENT, IMG(big_pointer), 144, 2, -180);
    ui_create_image_pointer(ui_monitor_cpu_panel, &ui_cpu_temp_pointer, \
                            89, -88, LV_SIZE_CONTENT, LV_SIZE_CONTENT, IMG(small_pointer), 72, 3, 300);
    ui_create_image_arc(ui_monitor_cpu_panel, &ui_cpu_mem_usage_arc, -40, 20, 295, 295, \
                        54, 126, LV_ARC_MODE_REVERSE, IMG(mem_usage1), IMG(mem_usage2));
#if DEBUG
    ui_animation(ui_cpu_usage_pointer, -180, 1650, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_image_set_rotation);
    ui_animation(ui_cpu_temp_pointer, 300, 1650, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_image_set_rotation);
    ui_animation(ui_cpu_mem_usage_arc, 0, 100, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_arc_set_value);
#endif
    ///////////////////--GPU--/////////////////////////

    ui_create_panel(ui_monitor_connect_panel, &ui_monitor_gpu_panel, 196, 0, 388, 344, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_monitor_gpu_panel, LV_PART_MAIN, lv_color_black(), LV_OPA_0, NULL, LV_OPA_0);
    ui_create_label(ui_monitor_gpu_panel, &ui_gpu_model, 40, -145, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_24, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 2, 0, "GPU");
    ui_create_label(ui_monitor_gpu_panel, &ui_gpu_usage_percent, 40, 21, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_38, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");
    ui_create_label(ui_monitor_gpu_panel, &ui_gpu_frequency, 40, 45, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");
    ui_create_label(ui_monitor_gpu_panel, &ui_gpu_mem_usage_percent, 40, 109, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_28, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");
    ui_create_label(ui_monitor_gpu_panel, &ui_gpu_mem_capacity, 40, 145, LV_SIZE_CONTENT, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 0, 0, "--");

    ui_create_image_pointer(ui_monitor_gpu_panel, &ui_gpu_usage_pointer, \
                            -26, 18, LV_SIZE_CONTENT, LV_SIZE_CONTENT, IMG(big_pointer), 144, 2, -180);
    ui_create_image_pointer(ui_monitor_gpu_panel, &ui_gpu_temp_pointer, \
                            -156, -88, LV_SIZE_CONTENT, LV_SIZE_CONTENT, IMG(small_pointer), 72, 3, 300);
    ui_create_image_arc(ui_monitor_gpu_panel, &ui_gpu_mem_usage_arc, 40, 20, 295, 295, \
                        54, 126, LV_ARC_MODE_REVERSE, IMG(mem_usage1), IMG(mem_usage2));
#if DEBUG
    ui_animation(ui_gpu_usage_pointer, -180, 1650, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_image_set_rotation);
    ui_animation(ui_gpu_temp_pointer, 300, 1650, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_image_set_rotation);
    ui_animation(ui_gpu_mem_usage_arc, 0, 100, 5000, 5000, 200, 1000, LV_ANIM_REPEAT_INFINITE, _lv_arc_set_value);
#endif

    ///////////////////--NET--/////////////////////////

    ui_create_panel(ui_monitor_connect_panel, &ui_monitor_middle_panel, 0, 45, 250, 480, LV_ALIGN_CENTER);
    ui_obj_set_style_bg(ui_monitor_middle_panel, LV_PART_MAIN, lv_color_black(), LV_OPA_0, NULL, LV_OPA_0);
    ui_create_label(ui_monitor_middle_panel, &ui_middle_time, 0, -28, 150, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_40, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 1, 0, "");
    ui_create_label(ui_monitor_middle_panel, &ui_middle_week, 0, 12, 150, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_32, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 1, 0, "");
    ui_create_label(ui_monitor_middle_panel, &ui_middle_date, 0, 46, 200, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_24, LV_TEXT_ALIGN_CENTER, lv_color_white(), LV_OPA_COVER, 1, 0, "");
    ui_create_label(ui_monitor_middle_panel, &ui_middle_upload, -30, 76, 90, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_RIGHT, lv_color_white(), LV_OPA_COVER, 0, 0, "0KB");
    ui_create_label(ui_monitor_middle_panel, &ui_middle_download, 78, 76, 90, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_RIGHT, lv_color_white(), LV_OPA_COVER, 0, 0, "0KB");
    ui_create_label(ui_monitor_middle_panel, &ui_middle_read, -30, 104, 90, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_RIGHT, lv_color_white(), LV_OPA_COVER, 0, 0, "0KB");
    ui_create_label(ui_monitor_middle_panel, &ui_middle_write, 78, 104, 90, LV_SIZE_CONTENT, LV_ALIGN_CENTER, \
                    &ui_font_ascii_20, LV_TEXT_ALIGN_RIGHT, lv_color_white(), LV_OPA_COVER, 0, 0, "0KB");
}


// --------------------------------------------------------------------------


void set_cpu_model(char *model) {
	static bool init_flag = false;
	
	if (!init_flag) {
		lv_label_set_text(ui_cpu_model, model);
		init_flag = true;
	}
}

void set_cpu_usage_pointer(float usage) {
	static int last_angle = CPU_USAGE_POINTER_START;
	int angle = CPU_USAGE_GET_ANGLE_BY_PERCENT(usage);

	if (angle != last_angle) {
        ui_animation_for_pointer(ui_cpu_usage_pointer, angle, 950);
		last_angle = angle;
	}
}

void set_cpu_usage_percent(float usage) {
	static int last_usage = 0;
	int cur_usage = (int)usage;

	if (cur_usage != last_usage) {
        lv_label_set_text_fmt(ui_cpu_usage_percent, "%d%%", cur_usage);
		last_usage = cur_usage;
	}
}

void set_cpu_frequency(float mhz) {
	float temp = 0;
	static int last_mhz = 0;
	int cur_mhz = (int)mhz;

	if (cur_mhz != last_mhz) {
		if (mhz > 999.0f) {
			temp = mhz / 1000.0f;
            lv_label_set_text_fmt(ui_cpu_frequency, "%3.1fG", (double)temp);
		} else {
            lv_label_set_text_fmt(ui_cpu_frequency, "%dM", (int)mhz);
		}
		last_mhz = cur_mhz;
	}
}

void set_cpu_temp_pointer(float usage) {
	static int last_angle = CPU_TEMP_POINTER_START;
	int angle = CPU_TEMP_GET_ANGLE_BY_PERCENT(usage);

	if (angle != last_angle) {
        ui_animation_for_pointer(ui_cpu_temp_pointer, angle, 950);
		last_angle = angle;
	}
}

void set_cpu_mem_usage(float usage) {
	static int last_usage = 0;
	int cur_usage = (int)usage;

	if (cur_usage != last_usage) {
		ui_animation_for_arc(ui_cpu_mem_usage_arc, cur_usage, 950);
		last_usage = cur_usage;
	}
}

void set_cpu_mem_usage_percent(float usage) {
	static int last_usage = 0;
	int cur_usage = (int)usage;

	if (cur_usage != last_usage) {
        lv_label_set_text_fmt(ui_cpu_mem_usage_percent, "%d%%", cur_usage);
		last_usage = cur_usage;
	}
}

void set_cpu_mem_capacity(char *capacity) {
	static bool init_flag = false;

	if (!init_flag) {
		lv_label_set_text(ui_cpu_mem_capacity, capacity);
		init_flag = true;
	}
}

/////////////////////////////////////

void set_gpu_model(char *model) {
	static bool init_flag = false;

	if (!init_flag) {
		lv_label_set_text(ui_gpu_model, model);
		init_flag = true;
	}
}

void set_gpu_usage_percent(float usage) {
	static int last_usage = 0;
	int cur_usage = (int)usage;

	if (cur_usage != last_usage) {
        lv_label_set_text_fmt(ui_gpu_usage_percent, "%d%%", cur_usage);
		last_usage = cur_usage;
	}
}

void set_gpu_frequency(float mhz) {
	static int last_mhz = 0;
	int cur_mhz = (int)mhz;
	float temp = 0;

	if (cur_mhz != last_mhz) {
		if (mhz > 999.0f) {
			temp = mhz / 1000.0f;
            lv_label_set_text_fmt(ui_gpu_frequency, "%3.1fG", (double)temp);
		} else {
            lv_label_set_text_fmt(ui_gpu_frequency, "%dM", (int)mhz);
		}
		last_mhz = cur_mhz;
	}
}

void set_gpu_usage_pointer(float usage) {
	static int last_angle = GPU_USAGE_POINTER_START;
	int angle = GPU_USAGE_GET_ANGLE_BY_PERCENT(usage);

	if (angle != last_angle) {
        ui_animation_for_pointer(ui_gpu_usage_pointer, angle, 950);
		last_angle = angle;
	}
}

void set_gpu_temp_pointer(float usage) {
	static int last_angle = GPU_TEMP_POINTER_START;
	int angle = GPU_TEMP_GET_ANGLE_BY_PERCENT(usage);

	if (angle != last_angle) {
        ui_animation_for_pointer(ui_gpu_temp_pointer, angle, 950);
		last_angle = angle;
	}
}

void set_gpu_mem_usage(float usage) {
	static int last_usage = 0;
	int cur_usage = (int)usage;

	if (cur_usage != last_usage) {
        ui_animation_for_arc(ui_gpu_mem_usage_arc, cur_usage, 950);
		last_usage = cur_usage;
	}
}

void set_gpu_mem_usage_percent(float usage) {
	static int last_usage = 0;
	int cur_usage = (int)usage;

	if (cur_usage != last_usage) {
        lv_label_set_text_fmt(ui_gpu_mem_usage_percent, "%d%%", cur_usage);
		last_usage = cur_usage;
	}
}

void set_gpu_mem_capacity(char *capacity) {
	static bool init_flag = false;

	if (!init_flag) {
		lv_label_set_text(ui_gpu_mem_capacity, capacity);
		init_flag = true;
	}
}

/////////////////////////////////////

void auto_unit(int bytes, char *dest_buf) {
	float temp = 0.0f;
	if (bytes > 999 * 1024) {
		temp = (float)bytes / 1024.0f / 1024.0f;
		sprintf(dest_buf, "%3dMB", (int)temp);
	} else {
		temp = (float)bytes / 1024.0f;
		sprintf(dest_buf, "%3dKB", (int)temp);
	}
}

void set_middle_net_upload(int bytes) {
    char buf[16];
	static int last_bytes = 0;

	if (bytes != last_bytes) {
		auto_unit(bytes, buf);
		lv_label_set_text(ui_middle_upload, buf);
		last_bytes = bytes;
	}
}

void set_middle_net_download(int bytes) {
    char buf[16];
	static int last_bytes = 0;

	if (bytes != last_bytes) {
		auto_unit(bytes, buf);
		lv_label_set_text(ui_middle_download, buf);
		last_bytes = bytes;
	}
}

void set_middle_io_read(int bytes) {
    char buf[16];
	static int last_bytes = 0;

	if (bytes != last_bytes) {
		auto_unit(bytes, buf);
		lv_label_set_text(ui_middle_read, buf);
		last_bytes = bytes;
	}
}

void set_middle_io_write(int bytes) {
    char buf[16];
	static int last_bytes = 0;

	if (bytes != last_bytes) {
		auto_unit(bytes, buf);
		lv_label_set_text(ui_middle_write, buf);
		last_bytes = bytes;
	}
}

/////////////////////////////////////

void set_middle_time(char *str) {
	static char time[16] = {0};

	if (strncmp(time, str, sizeof(time))) {
		lv_label_set_text(ui_middle_time, str);
		strncpy(time, str, sizeof(time));
	}
}

void set_middle_week(char *str) {
	static char week[8] = {0};

	if (strncmp(week, str, sizeof(week))) {
		lv_label_set_text(ui_middle_week, str);
		strncpy(week, str, sizeof(week));
	}
}

void set_middle_date(char *str) {
	static char date[16] = {0};

	if (strncmp(date, str, sizeof(date))) {
		lv_label_set_text(ui_middle_date, str);
		strncpy(date, str, sizeof(date));
	}
}


// ---------------------------------------------------------------------------------


void ui_monitor_load_anim(void) {
	ui_animation(ui_cpu_usage_pointer, CPU_USAGE_POINTER_START, CPU_USAGE_POINTER_END, 1000, 1000, 0, 0, 0, _lv_image_set_rotation);
	ui_animation(ui_gpu_usage_pointer, GPU_USAGE_POINTER_START, GPU_USAGE_POINTER_END, 1000, 1000, 0, 0, 0, _lv_image_set_rotation);
	ui_animation(ui_cpu_temp_pointer, CPU_TEMP_POINTER_START, CPU_TEMP_POINTER_END, 1000, 1000, 0, 0, 0, _lv_image_set_rotation);
	ui_animation(ui_gpu_temp_pointer, GPU_TEMP_POINTER_START, GPU_TEMP_POINTER_END, 1000, 1000, 0, 0, 0, _lv_image_set_rotation);
	ui_animation(ui_cpu_mem_usage_arc, 0, 100, 1000, 1000, 0, 0, 0, _lv_arc_set_value);
	ui_animation(ui_gpu_mem_usage_arc, 0, 100, 1000, 1000, 0, 0, 0, _lv_arc_set_value);
}

void ui_minitor_init_page_connected(void) {
	ui_monitor_panel_connected();
	// if (ui_monitor_disconnect_panel) {
	// 	lv_obj_delete(ui_monitor_disconnect_panel);
	// }
}

void ui_minitor_init_page_disconnected(void) {
	ui_monitor_panel_disconnected();
	// if (ui_monitor_connect_panel) {
	// 	lv_obj_delete(ui_monitor_connect_panel);
	// }
}

void ui_monitor_load_page(bool connected) {
	if (connected) {
		ui_minitor_init_page_connected();
		lv_screen_load_anim(ui_monitor_connect_panel, LV_SCR_LOAD_ANIM_FADE_IN, 500, 0, false);
	} else {
		ui_minitor_init_page_disconnected();
		lv_screen_load_anim(ui_monitor_disconnect_panel, LV_SCR_LOAD_ANIM_FADE_IN, 500, 0, false);
	}
}

//lv_obj_add_event_cb(ui_Monitor, ui_event_Monitor, LV_EVENT_ALL, NULL);
