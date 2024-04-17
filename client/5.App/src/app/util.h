#pragma once

#include <time.h>

typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERR
} LogLevel;

char *getasctime(time_t *t);
void log_message(LogLevel level, const char *fmt, ...);


#define LOG_INFO(fmt, ...) log_message(LOG_INFO, fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...) log_message(LOG_WARN, fmt, ##__VA_ARGS__)
#define LOG_ERR(fmt, ...)  log_message(LOG_ERR, fmt, ##__VA_ARGS__)

