#include "../inc/queue.h"

Queue *initQueue(int max) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->isFull = FALSE;
    q->max = max;
    q->count = 0;
    return q;
}

Bool isFull(Queue *q) {
    return q->max == q->count;
}

Bool isEmpty(Queue *q) {
    return q->count == 0;
}

void Enqueue(Queue *q, void *data, void *params, Type type) {
    if (isFull(q)) {
        printf("Queue full!\n");
        return;
    }
    q->count++;
    Data *qd = ndata(data, type);
    Node *qn = nnode(qd, params, type);
    if (q->front == NULL && q->rear == NULL) {
        q->front = qn;
        q->rear = q->front;
        q->rear->prev = q->front;
        return;
    }
    Node *temp = q->front;
    q->front = qn;
    qn->next = temp;
    temp->prev = qn;
}

Node Dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue empty!\n");
        return;
    }
    q->count--;
    Node *tmp = q->rear;
    Node copy = *tmp;
    q->rear = q->rear->prev;
    free(tmp);
    return copy;
}

void Empty(Queue *q) {
    while (!isEmpty(q)) {
        Dequeue(q);
    }
    q->front = NULL;
    q->rear = NULL;
}

void PrintQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue empty!\n");
        return;
    }
    Node *current = q->front;
    while (current->next != NULL) {
        if (current->type == C) {
            printf("%c ", current->data->c);
        } else if (current->type == FUNCWP) {
            current->data->funcWP(current->input);
        } else if (current->type == FUNCWTP) {
            current->data->funcWTP();
        }
        current = current->next;
    }
    if (current->type == C) {
        printf("%c ", current->data->c);
    } else if (current->type == FUNCWP) {
        current->data->funcWP(current->input);
    } else if (current->type == FUNCWTP) {
        current->data->funcWTP();
    }
}
