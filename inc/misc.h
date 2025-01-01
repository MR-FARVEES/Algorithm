#ifndef MISC_H
#define MISC_H

#include <stddef.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } Bool;
typedef enum { C, S,I, F, D, STR, FUNCWP, FUNCWTP } Type;
typedef enum { HIGH, MEDIUM, LOW } Priority;
typedef enum { READY, HALT, EXIT } ProcessState;

typedef struct {
    char   ms;
    char   s;
    char   m;
    char   h;
} TIME __attribute__((packed));

typedef union {
    char            c;
    short           s;
    int             i;
    float           f;
    double          d;
    char            *str;
    void            (*funcWP)(void *);
    void            (*funcWTP)();
} Data __attribute__((packed));

typedef struct _Node {
    Type            type;
    void            *input;
    Data            *data;
    struct _Node    *next;
    struct _Node    *prev;
} Node __attribute__((packed));

typedef struct {
    int             id;
    Priority        priority;
    ProcessState    state;
    char            *info;
    TIME            *tot_active;
} Process __attribute__((packed));

Data    *ndata     (void *, Type);
Node    *nnode     (Data *, void *, Type);
Process *newTask   (int, Priority, ProcessState, char *);

#endif // MISC_H
