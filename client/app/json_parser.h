#ifndef __JSON_PARSER_H
#define __JSON_PARSER_H

#include "cJSON.h"
#include "monitor.h"
#include "git.h"
#include "bili.h"

struct _ui_monitor_t;
struct _ui_bili_t;
struct _ui_git_t;

int get_root(const char *str, cJSON **root);
int get_node(cJSON *father_node, char *key, cJSON **node);
int get_double_from_node(cJSON *node, char *key, double *value);
int get_int_from_node(cJSON *node, char *key, int *value);
int get_string_from_node(cJSON *node, char *key, char *buf, int len);

int parse_monitor_info(const char *str, struct _ui_monitor_t *ui_monitor);
int parse_git_info(const char *str, struct _ui_git_t *ui_git);
int parse_bili_relation(const char *str, struct _ui_bili_t *ui_bili);
int parse_bili_space(const char *str, struct _ui_bili_t *ui_bili);
void json_parser_test(void);

#endif
