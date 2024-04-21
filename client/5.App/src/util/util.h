#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERR
} LogLevel;

char *getasctime(time_t *t);
void log_message(LogLevel level, const char *file, int line, const char *fmt, ...);


#define LOG_INFO(fmt, ...) log_message(LOG_INFO, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...) log_message(LOG_WARN, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_ERR(fmt, ...)  log_message(LOG_ERR, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

