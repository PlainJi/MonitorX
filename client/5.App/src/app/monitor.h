#pragma once

typedef struct _monitor_t {
    char cpu_model[16];
    double cpu_load;
    double ram_load;
    char ram_capacity[8];
    double cpu_clock;
    double cpu_temp;

    char gpu_model[16];
    double gpu_load;
    double gram_load;
    char gram_capacity[8];
    double gpu_clock;
    double gpu_temp;

    int link_up_bytes;
    int link_dw_bytes;
    int io_write_bytes;
    int io_read_bytes;
	
	char date[16];
    char time[16];
    char week[8];
}monitor_t;

void ui_monitor_init(void);
void monitor_thread(void);

