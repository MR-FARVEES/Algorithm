#ifndef MISC_H
#define MISC_H

#include <stddef.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } Bool;
typedef enum { C, S,I, F, D, STR, FUNCWP, FUNCWTP } Type;
typedef enum { HIGH, MEDIUM, LOW } Priority;
typedef enum { READY, HALT, EXIT } ProcessState;

typedef struct {
    short   ms;
    short   s;
    short   m;
    short   h;
    short   day;
    short   week;
    short   month;
    short   year;
} TIME;

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
    Data            *data;
    struct _Node    *next;
    struct _Node    *prev;
} Node;

typedef struct {
    int             id;
    Priority        priority;
    ProcessState    state;
    char            *info;
} Process;

Data    *ndata     (void *, Type);
Node    *nnode     (Data *, void *, Type);
Process *newTask   (int, Priority, ProcessState, char *);

#endif // MISC_H
