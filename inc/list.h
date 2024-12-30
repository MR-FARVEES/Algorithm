#ifndef LIST_H
#define LIST_H

#include "misc.h"

typedef struct {
    Node *node;
    int size;
} List;

List *initList();
void append   (List **, void *, void *, Type);
void del      (List **, int);
void PrintList(List *);

#endif // LIST_H
