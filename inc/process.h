#ifndef PROCESS_H
#define PROCESS_H

#include "misc.h"
#include <pthread.h>

pthread_t       input_thread;
pthread_mutex_t lock;
pthread_cond_t  cond;

#endif // PROCESS_H
