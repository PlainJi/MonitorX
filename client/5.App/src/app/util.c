#include "util.h"

char *getasctime(time_t *t) {
    static char *buf = NULL;
    buf = asctime(localtime(t));
    buf[24] = 0;
    return buf;
}