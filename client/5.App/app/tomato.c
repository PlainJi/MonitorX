#include "tomato.h"
#include "unistd.h"
#include <time.h>
#include <pthread.h>
#include "ui_controller.h"

int tomato_time_min = 0;        // the time tomato clock is set
int left_time_min = 0;          // 
time_t start_sec = 0;

extern pthread_mutex_t lvgl_mutex;

void tomato_thread(void) {

    while (1) {
        if (left_time_min) {
            time_t current_sec = time(NULL);
            int temp = tomato_time_min - (current_sec-start_sec)/60;
            if (left_time_min != temp) {
                left_time_min = temp;
                pthread_mutex_lock(&lvgl_mutex);
                ui_tomato_set_time(left_time_min);
                pthread_mutex_unlock(&lvgl_mutex);
            }
        }

        sleep(1);
    }
    
}