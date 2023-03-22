#pragma once

#include "curldef.h"

typedef struct _ui_bili_t {
    char userid[32];
    int following;
    int follower;
    int whisper;
    int black;
    int likes;
    int archive_views;
    int article_views;
}ui_bili_t;

typedef struct _VIDEO_INFO {
	char aid[10];	// 590023490
	char bid[13];	// BV1pq4y1D7Da
	int  view;		// 播放数
	int  danmu;		// 弹幕数
	int  reply;		// 评论数
	int  favorite;	// 收藏数
	int  coin;		// 硬币数
	int  share;		// 分享数
	int  like;		// 点赞数
}VIDEO_INFO, *pVIDEO_INFO;

void bili_thread(void);

