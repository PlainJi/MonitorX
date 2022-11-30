#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json_parser.h"
#include "../lib/cJSON/cJSON.h"

static cJSON *root = NULL;

int parse_json(char* str){

	cJSON_Delete(root);

	root = cJSON_Parse(str);
	if (root == NULL)
	{
		const char *error_ptr = cJSON_GetErrorPtr();
		if (error_ptr != NULL)
		{
			fprintf(stderr, "Error before: %s\n", error_ptr);
			return 0;
		}
	}
	return 1;
}

double get_value(char *key) {
	if (!root) {
		printf("not parsed!\n");
		return -1.0;
	}
	const cJSON *name = cJSON_GetObjectItemCaseSensitive(root, key);
	if (cJSON_IsNumber(name))
	{
		//printf("%s: %lf\n", key, name->valuedouble);
	}
	return name->valuedouble;
}

char* get_string(char *key) {
	if (!root) {
		printf("not parsed!\n");
		return NULL;
	}
	const cJSON *name = cJSON_GetObjectItemCaseSensitive(root, key);
	if (cJSON_IsString(name))
	{
		//printf("%s: %lf\n", key, name->valuedouble);
	}
	return name->valuestring;
}

/*
 * char *test_string = "{\"cpu_load\": 16.0, \"cpu_temp\": 52.0, \"cpu_clock\": 4009.0, \"ram_load\": 57.0}";
 *
void main(void) {
	parse_json(test_string);
	get_value("cpu_load");
	get_value("cpu_temp");
}
*/
