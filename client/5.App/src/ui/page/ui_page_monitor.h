#pragma once

#include "lvgl/lvgl.h"

#define CPU_USAGE_POINTER_START		(-180)
#define CPU_USAGE_POINTER_END		(1615)
#define GPU_USAGE_POINTER_START		(-180)
#define GPU_USAGE_POINTER_END		(1615)
#define CPU_TEMP_POINTER_START		(300)
#define CPU_TEMP_POINTER_END		(1480)
#define GPU_TEMP_POINTER_START		(300)
#define GPU_TEMP_POINTER_END		(1480)

#define CPU_USAGE_GET_ANGLE_BY_PERCENT(percent)   (percent/100.0f*(CPU_USAGE_POINTER_END-CPU_USAGE_POINTER_START)+CPU_USAGE_POINTER_START)
#define GPU_USAGE_GET_ANGLE_BY_PERCENT(percent)   (percent/100.0f*(GPU_USAGE_POINTER_END-GPU_USAGE_POINTER_START)+GPU_USAGE_POINTER_START)
#define CPU_TEMP_GET_ANGLE_BY_PERCENT(percent)    (percent/100.0f*(CPU_TEMP_POINTER_END-CPU_TEMP_POINTER_START)+CPU_TEMP_POINTER_START)
#define GPU_TEMP_GET_ANGLE_BY_PERCENT(percent)    (percent/100.0f*(GPU_TEMP_POINTER_END-GPU_TEMP_POINTER_START)+GPU_TEMP_POINTER_START)

void set_cpu_model(char *str);
void set_cpu_usage_pointer(float value);
void set_cpu_usage_percent(float value);
void set_cpu_mem_usage(float value);
void set_cpu_mem_usage_percent(float value);
void set_cpu_mem_capacity(char *capacity);
void set_cpu_frequency(float value);
void set_cpu_temp_pointer(float value);

void set_gpu_model(char *str);
void set_gpu_usage_pointer(float value);
void set_gpu_usage_percent(float value);
void set_gpu_mem_usage(float value);
void set_gpu_mem_usage_percent(float value);
void set_gpu_mem_capacity(char *capacity);
void set_gpu_frequency(float value);
void set_gpu_temp_pointer(float value);

void set_middle_net_upload(int bytes);
void set_middle_net_download(int bytes);
void set_middle_io_read(int bytes);
void set_middle_io_write(int bytes);

void set_middle_date(char *str);
void set_middle_time(char *str);
void set_middle_week(char *str);

void ui_minitor_init_page_connected(void);
void ui_minitor_init_page_disconnected(void);
void ui_monitor_load_anim(void);
void ui_monitor_load_page(bool connected);