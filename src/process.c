#include "../inc/process.h"

void createProcess(List *processList, char *info, void *function, Priority priority) {
    Process *process = newTask(processList->size, priority, HALT, info);
    append(&processList, function, process, FUNCWP);
}

void listProcesses(List *processList) {
    PrintList(processList);
}

void schedule_processes(List *processList, pthread_mutex_t *mutex, pthread_cond_t *cond) {

}
