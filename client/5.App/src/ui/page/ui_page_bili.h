#pragma once

#include "../ui.h"

extern lv_obj_t * ui_bili;

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
    char face_path[32]; // 用户头像     // A:image/no_face.png
    char sign[128];     // 口号
    char title[128];    // 
}bili_t;

typedef int (*bili_check_userid_cb_)(const char *);
typedef void (*bili_set_userid_cb_)(const char*);
typedef void (*bili_stop_update_cb_)(void);
typedef void (*bili_start_update_cb_)(void);

typedef struct _bili_callback {
    bili_check_userid_cb_ bili_check_userid_cb;
    bili_set_userid_cb_ bili_set_userid_cb;
    bili_stop_update_cb_ bili_stop_update_cb;
    bili_start_update_cb_ bili_start_update_cb;
}bili_callback_t;

extern bili_callback_t bili_cb;

/**********************
 * local func
 *********************/
int ui_bili_check_userid(const char *userid);

/**********************
 * global func
 *********************/
void ui_bili_init_page(void);
void ui_bili_set_basic(const char *userid);
void ui_bili_update_basic(void);
void ui_bili_set_info(bili_t *info);
void ui_bili_update_info(void);
void ui_bili_reset_info(void);
void ui_bili_update_status(char percent);