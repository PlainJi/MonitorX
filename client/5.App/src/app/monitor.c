#include "monitor.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>

#include "json_parser.h"
#include "ui.h"

#define SERVER_PORT         5555
#define CLIENT_PORT         5556
#define MAXLINE             4096
#define GROUP               "239.0.0.1"

monitor_t monitor;

void update_time_from_local(void) {
	static char *week[] = {"Sun.", "Mon.", "Tus.", "Wed.", "Thu.", "Fri.", "Sat."};
	time_t t = time(NULL);
	struct tm *s_tm = localtime(&t);
	sprintf(monitor.date, "%d-%02d-%02d\n", s_tm->tm_year+1900, s_tm->tm_mon, s_tm->tm_mday);
	sprintf(monitor.time, "%02d:%02d\n", s_tm->tm_hour, s_tm->tm_min);
	sprintf(monitor.week, "%s\n", week[s_tm->tm_wday]);
}

void ui_update_monitor(void) {
	set_cpu_model(monitor.cpu_model);
	set_cpu_usage_pointer(monitor.cpu_load);
	set_cpu_usage_percent(monitor.cpu_load);
	set_cpu_mem_usage(monitor.ram_load);
	set_cpu_mem_usage_percent(monitor.ram_load);
	set_cpu_mem_capacity(monitor.ram_capacity);
	set_cpu_frequency(monitor.cpu_clock);
	set_cpu_temp_pointer(monitor.cpu_temp);

	set_gpu_model(monitor.gpu_model);
	set_gpu_usage_pointer(monitor.gpu_load);
	set_gpu_usage_percent(monitor.gpu_load);
	set_gpu_mem_usage(monitor.gram_load);
	set_gpu_mem_usage_percent(monitor.gram_load);
	set_gpu_mem_capacity(monitor.gram_capacity);
	set_gpu_frequency(monitor.gpu_clock);
	set_gpu_temp_pointer(monitor.gpu_temp);

	set_middle_net_upload(monitor.link_up_bytes);
	set_middle_net_download(monitor.link_dw_bytes);
 	set_middle_io_read(monitor.io_read_bytes);
	set_middle_io_write(monitor.io_write_bytes);

    update_time_from_local();
	set_middle_date(monitor.date);
	set_middle_time(monitor.time);
	set_middle_week(monitor.week);
}

void monitor_thread(void)
{
    sleep(3);       // wait for animation

    bool connected = true;
    bool connect_status = true;
    struct sockaddr_in localaddr;
    int confd;
    ssize_t len;
    char buf[MAXLINE];
    struct ip_mreqn group;

    //1.创建一个socket
    confd=socket(AF_INET,SOCK_DGRAM,0);
    //2.初始化服务器地址
    bzero(&localaddr,sizeof(localaddr));
    localaddr.sin_family=AF_INET;
    //
    inet_pton(AF_INET,"0.0.0.0",&localaddr.sin_addr.s_addr);
    localaddr.sin_port = htons(CLIENT_PORT);
    bind(confd,(struct sockaddr *)&localaddr,sizeof(localaddr));

    //3.设置组地址
    inet_pton(AF_INET,GROUP,&group.imr_multiaddr);
    //4.设置本地地址
    inet_pton(AF_INET,"0.0.0.0",&group.imr_address);
    group.imr_ifindex=if_nametoindex("wlan0");//将网卡名转换成序号 等价 ip ad
    //5.设置客户端加入多播组
    setsockopt(confd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&group,sizeof(group));
    //6.设置接收超时时间
    struct timeval tv;
	tv.tv_sec = 3;
	tv.tv_usec =  0;
	setsockopt(confd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

    while(1){
        memset(buf, 0, sizeof(buf));
        int ret = recvfrom(confd, buf, sizeof(buf), 0, NULL, 0);
        if (ret <= 0) {
            printf("[MONITOR] recv timeout\n");
            connected = false;
        } else {
            connected = true;
            //printf("[MONITOR] recv: %s\n", buf);
            if (!parse_monitor_info(buf, &monitor)) {
                pthread_mutex_lock(&lvgl_mutex);
                ui_update_monitor();
                pthread_mutex_unlock(&lvgl_mutex);
            }
        }

        if (connect_status != connected) {
            connect_status = connected;
            ui_monitor_load_page(connected);
        }
    }
    close(confd);
}
