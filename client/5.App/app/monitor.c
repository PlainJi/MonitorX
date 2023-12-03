#include "monitor.h"
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <net/if.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include "json_parser.h"
#include "ui_controller.h"

#define SERVER_PORT         5555
#define CLIENT_PORT         5556
#define MAXLINE             4096
#define GROUP               "239.0.0.1"

monitor_t ui_monitor;
extern pthread_mutex_t lvgl_mutex;

void monitor_thread(void)
{
    pthread_mutex_lock(&lvgl_mutex);
    ui_monitor_init();
    pthread_mutex_unlock(&lvgl_mutex);
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
            if (!parse_monitor_info(buf, &ui_monitor)) {
                pthread_mutex_lock(&lvgl_mutex);
                ui_update_monitor(&ui_monitor);
                pthread_mutex_unlock(&lvgl_mutex);
            }
        }

        if (connect_status != connected) {
            connect_status = connected;
            pthread_mutex_lock(&lvgl_mutex);
            if (connected) ui_monitor_reconnected();
            else ui_monitor_disconnected();
            pthread_mutex_unlock(&lvgl_mutex);
        }
    }
    close(confd);
}
