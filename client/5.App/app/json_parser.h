#ifndef __JSON_PARSER_H
#define __JSON_PARSER_H

#include "cJSON.h"
#include "monitor.h"
#include "git.h"
#include "bili.h"

struct _monitor_t;
struct _git_t;
struct _bili_relation_t;
struct _bili_video_list_t;
struct _bili_video_info_t;

int get_root(const char *str, cJSON **root);
int get_node(cJSON *father_node, char *key, cJSON **node);
int get_double_from_node(cJSON *node, char *key, double *value);
int get_int_from_node(cJSON *node, char *key, int *value);
int get_string_from_node(cJSON *node, char *key, char *buf, int len);

int parse_monitor_info(const char *str, struct _monitor_t *ui_monitor);

int parse_git_info(const char *str, struct _git_t *ui_git);

int parse_bili_relation(const char *str, struct _bili_relation_t *ui_bili);
int parse_bili_video_list(const char *str, struct _bili_video_list_t *list_buf);
int parse_bili_video_detail(const char *str, struct _bili_video_info_t *info);
void json_parser_test(void);

#endif
