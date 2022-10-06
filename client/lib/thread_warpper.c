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
#include "thread_warpper.h"

static int getPriorityScope(int *minPriority, int *maxPriority)
{
	if (minPriority != NULL)
	{
		(*minPriority) = sched_get_priority_min(SCHED_RR);
		if (*minPriority == -1)
		{
			return -1;
		}
	}
	if (maxPriority != NULL)
	{
		(*maxPriority) = sched_get_priority_max(SCHED_RR);
		if (*maxPriority == -1)
		{
			return -1;
		}
	}

	return 0;
}

int task_creat(pthread_t *ptid, int priority, int stacksize, void *(*funcptr)(void*), void *arg)
{
	if (funcptr == NULL){
		return -1;
	}
	
	int rval;
	struct sched_param params;
	int maxPriority, minPriority;
	pthread_t tid, *pTempTid;
	pthread_attr_t attr;
	int actStackSize = stacksize;
	
	do{
		if (0 != (rval=pthread_attr_init(&attr))){
			return rval;
		}
		
		if (0 != (rval=pthread_attr_setschedpolicy(&attr, SCHED_RR))){
			break;
		}
		if (0 != (rval=pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED))){
			break;
		}
		// set priority
		if (0 != (rval=pthread_attr_getschedparam(&attr, &params))){
			break;
		}
		if (0 != (rval=getPriorityScope(&minPriority, &maxPriority))){
			break;
		}
		if (priority < minPriority){
			priority = minPriority;
		}
		else if (priority > maxPriority){
			priority = maxPriority;
		}
		params.sched_priority = priority;
		if (0 != (rval=pthread_attr_setschedparam(&attr, &params))){
			break;
		}
		// set stack size
		if (actStackSize < STACK_SIZE_MIN){
			actStackSize = STACK_SIZE_MIN;
		}
		if (0 != (rval=pthread_attr_setstacksize(&attr, actStackSize))){
			break;
		}
		
		if (ptid != NULL){
			pTempTid = ptid;
		}else{
			pTempTid = &tid;
		}
		rval = pthread_create(pTempTid, &attr, (FUNC)funcptr, arg);
	}while(0);
	
	pthread_attr_destroy(&attr);
	
	return rval;
}
