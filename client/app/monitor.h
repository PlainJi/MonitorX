#pragma once

typedef struct _monitor_t {
    double cpu_load;
    double ram_load;
    double cpu_clock;
    double cpu_temp;

    double gpu_load;
    double gram_load;
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

