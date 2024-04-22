#if 0
#include "ui_controller.h"
#include "json_parser.h"
#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include "monitor.h"
#include "git.h"
#include "bili.h"
#include "tomato.h"
#include "config.h"

#define portMAX_DELAY				(0xffff)
#define pdTRUE						(1)



//////////////////////////////////////////////////////////////////////////////////////

void ui_tomato_set_time(int minutes) {
    lv_meter_set_indicator_value(ui_meter, ui_indic_pointer, minutes);
    lv_meter_set_indicator_end_value(ui_meter, ui_indic_pie, minutes);
}

void ui_tomato_init(void) {
	ui_tomato_set_time(0);
	lv_arc_set_value(ui_ArcTomato, 1);
}

void ui_update_tomato_time(int time_min) {
	tomato_time_min = time_min;
	left_time_min = time_min;
	start_sec = time(NULL);
	printf("ui_update_tomato_time: %d\n", time_min);
}


#endif