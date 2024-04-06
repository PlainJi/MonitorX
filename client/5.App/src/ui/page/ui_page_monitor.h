#pragma once

#include "lvgl/lvgl.h"

extern lv_obj_t * ui_monitor;
extern lv_obj_t * ui_monitor_connect_panel;
extern lv_obj_t * ui_monitor_disconnect_panel;

void ui_monitor_init(void);
void ui_monitor_disconnect(void);
void ui_monitor_connect(void);