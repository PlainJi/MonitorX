#pragma once

#include "curldef.h"
#include "app.h"
#include "ui.h"

//#define BILI_MID_STR        "389426697"   // 胡仑贝尔
#define URL_BILI_RELATION   "https://api.bilibili.com/x/relation/stat?vmid="                // 389426697
//#define URL_BILI_VIDEO_LIST "https://api.bilibili.com/x/space/arc/search?mid="            // 389426697&pn=1&ps=50
#define URL_BILI_VIDEO_LIST "https://api.bilibili.com/x/space/wbi/arc/search?mid="          // 389426697&pn=1&ps=50
//#define URL_BILI_VIDEO_INFO "https://api.bilibili.com/x/web-interface/archive/stat?aid="    // 590023490
#define URL_BILI_VIDEO_INFO "https://api.bilibili.com/x/web-interface/wbi/view/detail?aid="     
#define URL_BILI_CARD       "https://api.bilibili.com/x/web-interface/card?mid="            // 20259914
#define REAL_FACE_PATH      "A:./res/image/face.jpg"
#define UNKNOWN_FACE_PATH   "A:./res/image/face_unknown.png"

typedef struct _bili_relation_t {
    char mid[32];		// 
    int following; 		// 关注数
    int whisper;		// 
    int black;			// 
    int follower;		// 粉丝数
}bili_relation_t;

typedef struct _bili_video_list_t {
    int count;
    int ps;
    int pn;
    char author[32];
    int buf_len;
    char *video_list_buf;
}bili_video_list_t;

typedef struct _bili_video_info_t {
    int  aid;		// 590023490
    int  view;		// 播放数
    int  danmu;		// 弹幕数
    int  reply;		// 评论数
    int  favorite;	// 收藏数
    int  coin;		// 硬币数
    int  share;		// 分享数
    int  like;		// 点赞数
}bili_video_info_t;

int bili_curl_req(const char *url);
int bili_req_relation(const char *userid, bili_relation_t *info);
int bili_check_userid(const char *userid);
int bili_req_video_list(void);
int bili_req_video_detail(int cnt);
int bili_req_card(const char *userid, bili_t *info);
int bili_get_summary(void);
void bili_reset(void);
int bili_init(void);
int bili_uninit(void);
void bili_stop_update(void);
void bili_start_update(void);
void update_relation(void);
void update_detail(void);
void update_detail2(void);
void update_card(void);
void bili_thread(void);

