#ifndef MISC_H
#define MISC_H

#include <stddef.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } Bool;
typedef enum { C, S,I, F, D, STR, FUNCWP, FUNCWTP } Type;

typedef union {
    char            c;
    short           s;
    int             i;
    float           f;
    double          d;
    char            *str;
    void            (*funcWP)(void *);
    void            (*funcWTP)();
} Data;

typedef struct _Node {
    Type            type;
    void            *input;
    Data           *data;
    struct _Node    *next;
    struct _Node    *prev;
} Node;

Data *ndata    (void  *, Type);
Node *nnode    (Data *, void *, Type);

#endif // MISC_H
