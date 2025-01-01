#include <stdio.h>
#include <stdlib.h>
#include "inc/queue.h"
#include "inc/list.h"
#include "inc/process.h"

void testFunc(void *arg) {
    Process *pro = (Process *)arg;

}

int main() {
    List *processes = initList();
    createProcess(processes, "Process 1", testFunc, HIGH);
    PrintList(processes);

    return EXIT_SUCCESS;
}
