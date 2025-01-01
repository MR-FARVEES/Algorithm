#ifndef PROCESS_H
#define PROCESS_H

#include "misc.h"
#include "list.h"
#include <pthread.h>
#include <stdbool.h>

void createProcess(List *processList, char *, void *, Priority);
void listProcesses(List *processList);
void schedule_processes(List *processList, pthread_mutex_t *, pthread_cond_t *);

#endif // PROCESS_H
