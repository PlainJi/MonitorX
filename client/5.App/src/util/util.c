#include "util.h"

char *getasctime(time_t *t) {
    static char *buf = NULL;
    buf = asctime(localtime(t));
    buf[24] = 0;
    return buf;
}

void log_message(LogLevel level, const char *file, int line, const char *fmt, ...) {
    // 获取当前时间
    time_t t = time(NULL);

    // 获取文件名
    const char *file_name = file;
    for (const char *p = file; *p; p++) {
        if (*p == '/' || *p == '\\') {
            file_name = p + 1;
        }
    }

    // 根据日志级别设置前缀
    const char *prefix = NULL;
    switch (level) {
        case LOG_INFO:
            prefix = "INFO";
            break;
        case LOG_WARN:
            prefix = "WARN";
            break;
        case LOG_ERR:
            prefix = "ERR";
            break;
    }

    // 输出日志
    printf("[%s] [%s] [%s:%d] ", getasctime(&t), prefix, file_name, line);
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}