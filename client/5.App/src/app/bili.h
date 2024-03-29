#pragma once

#include "curldef.h"

//#define BILI_MID_STR        "389426697"   // 胡仑贝尔
#define URL_BILI_RELATION   "https://api.bilibili.com/x/relation/stat?vmid="                // 389426697
//#define URL_BILI_VIDEO_LIST "https://api.bilibili.com/x/space/arc/search?mid="            // 389426697&pn=1&ps=50
#define URL_BILI_VIDEO_LIST "https://api.bilibili.com/x/space/wbi/arc/search?mid="          // 389426697&pn=1&ps=50
//#define URL_BILI_VIDEO_INFO "https://api.bilibili.com/x/web-interface/archive/stat?aid="    // 590023490
#define URL_BILI_VIDEO_INFO "https://api.bilibili.com/x/web-interface/wbi/view/detail?aid="     
#define URL_BILI_CARD       "https://api.bilibili.com/x/web-interface/card?mid="            // 20259914

typedef struct _bili_t {
    char userid[16];	// 用户ID   1
    char username[32];	// 用户名   1
    int following;		// 总关注   1
    int follower;		// 粉丝数   1
    int video;			// 总视频   1
    int article;		// 总文章   1
    int view;			// 总播放
    int danmu;			// 总弹幕
    int reply;			// 总评论
    int like;			// 总点赞   1
    int coin;			// 总硬币
    int favorite;		// 总收藏
    int share;			// 总分享
    char face_url[128]; // 用户头像     // https://i2.hdslb.com/bfs/face/cb9ef82714507e6bda707dac216da94c97d70037.jpg
    char face[32];      // 用户头像     // A:image/no_face.png
    char sign[128];     // 口号
    char title[128];    // 
}bili_t;

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

int bili_curl_req(char *url);
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

