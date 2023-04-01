#include "json_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
// https://api.bilibili.com/x/relation/stat?vmid=389426697
const char *bili_relation = "{ 	\
  \"code\": 0,				\
  \"message\": \"0\",		\
  \"ttl\": 1,				\
  \"data\": {				\
    \"mid\": 389426697,		\
    \"following\": 112,		\
    \"whisper\": 0,			\
    \"black\": 0,			\
    \"follower\": 2			\
  }							\
}";

// https://api.bilibili.com/x/space/upstat?mid=389426697
const char *bili_space = "{	\
  \"code\": 0,			\
  \"message\": \"0\",	\
  \"ttl\": 1,			\
  \"data\": {			\
    \"archive\": {		\
      \"view\": 1		\
    },					\
    \"article\": {		\
      \"view\": 0		\
    },					\
    \"likes\": 3		\
  }						\
}";

// https://skyline.github.com/plainji/2022.json
const char *git_test = "{		\
  \"username\": \"plainji\",	\
  \"year\": \"2022\",			\
  \"min\": 1,					\
  \"max\": 6,					\
  \"median\": 2,				\
  \"p80\": 4,					\
  \"p90\": 6,					\
  \"p99\": 6,					\
  \"contributions\": [			\
    {							\
      \"week\": 0,				\
      \"days\": [				\
        {						\
          \"count\": 0			\
        }						\
      ]							\
    },							\
    {							\
      \"week\": 1,				\
      \"days\": [				\
        {						\
          \"count\": 1			\
        },						\
        {						\
          \"count\": 2			\
        },						\
        {						\
          \"count\": 3			\
        },						\
        {						\
          \"count\": 4			\
        },						\
        {						\
          \"count\": 5			\
        },						\
        {						\
          \"count\": 6			\
        },						\
        {						\
          \"count\": 7			\
        }						\
      ]							\
    }							\
  ]								\
}";
*/

int get_root(const char *str, cJSON **root) {
	*root = cJSON_Parse(str);
	if (*root == NULL)
	{
		const char *error_ptr = cJSON_GetErrorPtr();
		if (error_ptr != NULL)
		{
			fprintf(stderr, "cJSON_Parse Failed: %s\n", error_ptr);
			//printf("%c/%u %c/%u %c/%u\n", *(error_ptr-2), *(error_ptr-2), *(error_ptr-1), *(error_ptr-1), *(error_ptr-0), *(error_ptr-0));
			return 1;
		}
	}
	return 0;
}

int get_node(cJSON *father_node, char *key, cJSON **node) {
	*node = cJSON_GetObjectItemCaseSensitive(father_node, key);
	if (*node == NULL) {
		return 1;
	}
	return 0;
}

int get_double_from_node(cJSON *node, char *key, double *value) {
	if (!node) {
		printf("not parsed!\n");
		return 1;
	}
	const cJSON *name = cJSON_GetObjectItemCaseSensitive(node, key);
	if (!cJSON_IsNumber(name))
	{
		return 2;
	}
	*value = name->valuedouble;
	return 0;
}

int get_int_from_node(cJSON *node, char *key, int *value) {
	if (!node) {
		printf("not parsed!\n");
		return 1;
	}
	const cJSON *name = cJSON_GetObjectItemCaseSensitive(node, key);
	if (!cJSON_IsNumber(name))
	{
		return 2;
	}
	*value = name->valueint;
	return 0;
}

int get_string_from_node(cJSON *node, char *key, char *buf, int len) {
	if (!node) {
		printf("not parsed!\n");
		return 1;
	}
	const cJSON *name = cJSON_GetObjectItemCaseSensitive(node, key);
	if (!cJSON_IsString(name))
	{
		return 2;
	}

	strncpy(buf, name->valuestring, len-1);
	buf[len-1] = 0;
	return 0;
}

int parse_monitor_info(const char *str, monitor_t *ui_monitor) {
	int res = 0;
	cJSON *root = NULL;

	do {
		if (get_root(str, &root)) {
			res = 1;
			break;
		}

		memset(ui_monitor, 0, sizeof(monitor_t));
		get_double_from_node(root, "cpu_load", &ui_monitor->cpu_load);
		get_double_from_node(root, "ram_load", &ui_monitor->ram_load);
		get_double_from_node(root, "cpu_clock", &ui_monitor->cpu_clock);
		get_double_from_node(root, "cpu_temp", &ui_monitor->cpu_temp);

		get_double_from_node(root, "gpu_load", &ui_monitor->gpu_load);
		get_double_from_node(root, "gram_load", &ui_monitor->gram_load);
		get_double_from_node(root, "gpu_clock", &ui_monitor->gpu_clock);
		get_double_from_node(root, "gpu_temp", &ui_monitor->gpu_temp);

		get_int_from_node(root, "link_up", &ui_monitor->link_up_bytes);
		get_int_from_node(root, "link_dw", &ui_monitor->link_dw_bytes);
		get_int_from_node(root, "io_write", &ui_monitor->io_write_bytes);
		get_int_from_node(root, "io_read", &ui_monitor->io_read_bytes);
		
		get_string_from_node(root, "date", ui_monitor->date, sizeof(ui_monitor->date));
		get_string_from_node(root, "time", ui_monitor->time, sizeof(ui_monitor->time));
		get_string_from_node(root, "week", ui_monitor->week, sizeof(ui_monitor->week));
	}while(0);

	cJSON_Delete(root);
	return res;
}

int parse_git_info(const char *str, git_t *ui_git) {
	cJSON *root = NULL;
	cJSON *contributions = NULL;
	cJSON *week = NULL;
	cJSON *days = NULL;
	cJSON *day = NULL;
	char temp_year[8];
	int week_num = 0;
	int days_count = 0;
	int count = 0;
	int temp_cnt = 0;
	int res = 0;

	do {
		if (get_root(str, &root)) {
			res = 1;
			break;
		}

		memset(ui_git, 0, sizeof(git_t));
		get_string_from_node(root, "username", ui_git->username, sizeof(ui_git->username));
		get_int_from_node(root, "year", &ui_git->year);
		get_string_from_node(root, "year", temp_year, sizeof(temp_year));
		ui_git->year = atoi(temp_year);
		get_int_from_node(root, "min", (int*)&ui_git->min);
		get_int_from_node(root, "max", (int*)&ui_git->max);
		get_int_from_node(root, "median", (int*)&ui_git->median);
		get_int_from_node(root, "p80", (int*)&ui_git->p80);
		get_int_from_node(root, "p90", (int*)&ui_git->p90);
		get_int_from_node(root, "p99", (int*)&ui_git->p99);

		if (get_node(root, "contributions", &contributions)) {res = 2; break;}
		cJSON_ArrayForEach(week, contributions) {
			if (get_int_from_node(week, "week", &week_num)) {res = 3; break;}
			if (week_num < 0 || week_num > 52) {res = 4; break;}
			if (get_node(week, "days", &days)) {res = 5; break;}
			if (!cJSON_IsArray(days)) {res = 6; break;}
			days_count = cJSON_GetArraySize(days);
			if (days_count > 7) {res = 7; break;}
			temp_cnt = 7 - days_count;
			cJSON_ArrayForEach(day, days) {
				if (get_int_from_node(day, "count", &count)) {res = 8; break;}
				ui_git->contribution[week_num][temp_cnt] = count;
				temp_cnt += 1;
			}
		}
	}while(0);

	cJSON_Delete(root);
	return res;
}

int parse_bili_relation(const char *str, bili_relation_t *ui_bili) {
	cJSON *root = NULL;
	cJSON *code = NULL;
	cJSON *data = NULL;
	int res = 0;
	int status = 0;

	do {
		if (get_root(str, &root)) {
			res = 1;
			break;
		}
		if (get_int_from_node(root, "code", &status)) {res=2; break;}
		if (status != 0) {res=3; break;}
		if (get_node(root, "data", &data)) {res=4; break;}

		get_int_from_node(data, "following", &ui_bili->following);
		get_int_from_node(data, "follower", &ui_bili->follower);
		get_int_from_node(data, "whisper", &ui_bili->whisper);
		get_int_from_node(data, "black", &ui_bili->black);
	}while(0);
	
	cJSON_Delete(root);
	return res;
}

int parse_bili_video_list(const char *str, bili_video_list_t *list_buf) {
	cJSON *root = NULL;
		// code
		cJSON *data = NULL;
			cJSON *page = NULL;
				// pn
				// ps
				// count
			cJSON *list = NULL;
				cJSON *vList = NULL;
					cJSON *item = NULL;
						// author
						// aid
	int res = 0;
	int status = 0;
	int aid = 0;
	int cnt = 0;

	do {
		if (get_root(str, &root)) { res = 1; break; }
			if (get_int_from_node(root, "code", &status)) { res=2; break; }
			//printf("status: %d\n", status);
			if (status != 0) { res=3; break; }

			if (get_node(root, "data", &data)) { res=4; break; }
				if (get_node(data, "page", &page)) { res=5; break; }
					if (get_int_from_node(page, "pn", &list_buf->pn)) { res=6; break; }
					if (get_int_from_node(page, "ps", &list_buf->ps)) { res=7; break; }
					if (get_int_from_node(page, "count", &list_buf->count)) { res=8; break; }
					if (list_buf->video_list_buf == NULL || list_buf->count*sizeof(aid) != list_buf->buf_len) {
						list_buf->video_list_buf = realloc(list_buf->video_list_buf, list_buf->count * sizeof(aid));
						if (list_buf->video_list_buf == NULL) { res=9; break; }
						list_buf->buf_len = list_buf->count * sizeof(aid);
					}
					//printf("pn=%d, ps=%d, cnt=%d\n", list_buf->pn, list_buf->ps, list_buf->count);
				if (get_node(data, "list", &list)) { res=10; break; }
					if (get_node(list, "vlist", &vList)) { res=11; break; }
						cJSON_ArrayForEach(item, vList) {
							if (get_int_from_node(item, "aid", &aid)) { res=12; break; }
							//printf("aid = %d\n", aid);
							int offset = ((list_buf->pn-1) * list_buf->ps + cnt) * sizeof(aid); cnt++;
							memcpy(list_buf->video_list_buf+offset, &aid, sizeof(aid));
							if (!list_buf->author[0]) {
								if (get_string_from_node(item, "author", list_buf->author, sizeof(list_buf->author))) { res=13; break; }
								//printf("author: %s\n", list_buf->author);
							}
						}
	}while(0);

	cJSON_Delete(root);
	return res;
}

int parse_bili_video_detail(const char *str, bili_video_info_t *info) {
	cJSON *root = NULL;
	cJSON *data = NULL;
	int res = 0;
	int status = 0;

	do {
		if (get_root(str, &root)) {res = 1;break;}
		if (get_int_from_node(root, "code", &status)) {res=2;break;}
		if (status != 0) {res=3; break;}
		
		if (get_node(root, "data", &data)) {res=4; break;}
			if (get_int_from_node(data, "aid", &info->aid)) {res=5;break;}
			if (get_int_from_node(data, "view", &info->view)) {res=6;break;}
			if (get_int_from_node(data, "danmaku", &info->danmu)) {res=7;break;}
			if (get_int_from_node(data, "reply", &info->reply)) {res=8;break;}
			if (get_int_from_node(data, "favorite", &info->favorite)) {res=9;break;}
			if (get_int_from_node(data, "coin", &info->coin)) {res=10;break;}
			if (get_int_from_node(data, "share", &info->share)) {res=11;break;}
			if (get_int_from_node(data, "like", &info->like)) {res=12;break;}
	}while(0);
	
	cJSON_Delete(root);
	return res;
}

/*
int parse_bili_space(const char *str, ui_bili_t *ui_bili) {
	cJSON *root = NULL;
	cJSON *code = NULL;
	cJSON *data = NULL;
	cJSON *archive = NULL;
	cJSON *article = NULL;
	int status = 0;
	int res = 0;

	do {
		if (get_root(str, &root)) {
			res = 1; 
			break;
		}
		if (get_int_from_node(root, "code", &status)) {res=2; break;}
		if (status != 0) {res=3; break;}
		if (get_node(root, "data", &data)) {res=4; break;}
		if (get_node(data, "archive", &archive)) {res=5; break;}
		if (get_node(data, "article", &article)) {res=6; break;}

		get_int_from_node(archive, "view", &ui_bili->archive_views);
		get_int_from_node(article, "view", &ui_bili->article_views);
		get_int_from_node(data, "likes", &ui_bili->likes);
	}while(0);
	
	cJSON_Delete(root);
	return res;
}
*/

/*
void json_parser_test(void) {
	monitor_t ui_monitor;
	git_t ui_git;
	ui_bili_t ui_bili;
	memset(&ui_monitor, 0, sizeof(monitor_t));
	memset(&ui_git, 0, sizeof(git_t));
	memset(&ui_bili, 0, sizeof(ui_bili_t));

	parse_git_info(git_test, &ui_git);
	parse_bili_relation(bili_relation, &ui_bili);
	parse_bili_space(bili_space, &ui_bili);

	printf("username=%s year=%d\n", ui_git.username, ui_git.year);
	for(int i=0; i<2; i++) {
		for(int j=0;j<7; j++) {
			printf("%d ", ui_git.contribution[i][j]);
		}
		printf("\n");
	}
	
	printf("following=%d likes=%d\n", ui_bili.following, ui_bili.likes);
}
*/

/*
 * char *test_string = "{\"cpu_load\": 16.0, \"cpu_temp\": 52.0, \"cpu_clock\": 4009.0, \"ram_load\": 57.0}";
 *
void main(void) {
	parse_json(test_string);
	get_value("cpu_load");
	get_value("cpu_temp");
}
*/
