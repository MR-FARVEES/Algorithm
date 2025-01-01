#ifndef QUEUE_H
#define QUEUE_H

#include "misc.h"

typedef struct {
    Node           *front;
    Node           *rear;
    int             count;
    int             max;
    Bool            isFull;
} Queue __attribute__((packed));

Queue *initQueue(int    );
Bool isFull     (Queue *);
Bool isEmpty    (Queue *);
void Enqueue    (Queue *, void *, void *, Type);
Node Dequeue    (Queue *);
void Empty      (Queue *);
void PrintQueue (Queue *);

#endif // QUEUE_H
