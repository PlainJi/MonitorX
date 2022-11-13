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
#include "network.h"
#include "ui_controller.h"

#define SERVER_PORT 5555
#define CLIENT_PORT 5556 
#define MAXLINE 4096
#define GROUP "239.0.0.1"


void network_thread()
{
    struct sockaddr_in localaddr;
    int confd;
    ssize_t len;
    char buf[MAXLINE];
    struct ip_mreqn group;//设置组播

    //1.创建一个socket
    confd=socket(AF_INET,SOCK_DGRAM,0);
    //2.初始化服务器地址
    bzero(&localaddr,sizeof(localaddr));
    localaddr.sin_family=AF_INET;
    //
    inet_pton(AF_INET,"0.0.0.0",&localaddr.sin_addr.s_addr);
    localaddr.sin_port =htons(CLIENT_PORT);
    bind(confd,(struct sockaddr *)&localaddr,sizeof(localaddr));

    /*设置组地址*/
    inet_pton(AF_INET,GROUP,&group.imr_multiaddr);
    /*设置本地地址*/
    inet_pton(AF_INET,"0.0.0.0",&group.imr_address);
    group.imr_ifindex=if_nametoindex("wlan0");//将网卡名转换成序号 等价 ip ad
    /*设置客户端加入多播组*/
    setsockopt(confd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&group,sizeof(group));

    while(1){
        len=recvfrom(confd, buf, sizeof(buf), 0, NULL, 0);
        //write(STDIN_FILENO, buf, len);
	    update_ui(buf);
    }    
    close(confd);
}
