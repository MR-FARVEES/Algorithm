#include "../inc/misc.h"

Data *ndata(void *data, Type type) {
    Data *qd = (Data *)malloc(sizeof(Data));
    if (type == C) {
        qd->c = (char *)data;
    } else if (type == S) {
        qd->s = (short *)data;
    } else if (type == I) {
        qd->i = (int *)data;
    } else if (type == F) {
        qd->f = *(float *)data;
    } else if (type == D) {
        qd->d = *(double *)data;
    } else if (type == STR) {
        qd->str = (char *)data;
    } else if (type == FUNCWP) {
        qd->funcWP = data;
    } else if (type == FUNCWTP) {
        qd->funcWTP = data;
    }
    return qd;
}

Node *nnode(Data *data, void *params, Type type) {
    Node *qn = (Node *)malloc(sizeof(Node));
    qn->data = data;
    qn->input = params;
    qn->next = NULL;
    qn->prev = NULL;
    qn->type = type;
    return qn;
}

Process *newTask(int id, Priority priority, ProcessState state, char *info) {
    Process *p = (Process *)malloc(sizeof(Process));
    p->id = id;
    p->priority = priority;
    p->state = state;
    p->info = info;
    p->tot_active = (TIME *)malloc(sizeof(TIME));
    return p;
}
