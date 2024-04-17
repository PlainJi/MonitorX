#ifndef POSIX_H
#define POSIX_H

#include <limits.h>
#include <sched.h>
#include <stdarg.h>
#include <signal.h>
#include <pthread.h>
#include <mqueue.h>
#include <semaphore.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <sys/types.h>

#define NO_WAIT			(0)
#define WAIT_FOREVER	(-1)
#define STACK_SIZE_MIN	(16*1024)

#define PRIO_LEVEL_ONE			90
#define PRIO_LEVEL_TWO			80
#define PRIO_LEVEL_THREE		70
#define PRIO_LEVEL_FOUR			60
#define PRIO_LEVEL_FIVE			50

typedef void* (*FUNC)(void*);

int task_creat(const char *name, int priority, int stacksize, void *(*funcptr)(void*), void *arg);

#endif
