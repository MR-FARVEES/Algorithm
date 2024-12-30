#include "../inc/list.h"

List *initList() {
    List *l = (List *)malloc(sizeof(List));
    l->size = 0;
    l->node = NULL;
    return l;
}

void append(List **list, void *data, void *params, Type type) {
    Data *ld = ndata(data, type);
    Node *ln = nnode(ld, params, type);
    (*list)->size++;
    if ((*list)->node == NULL) {
        (*list)->node = ln;
        return;
    }
    Node *current = (*list)->node;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = ln;
    ln->prev = current;
}

void del(List **list, int index) {
    if ((*list)->node == NULL) {
        return;
    }
    if ((*list)->size - 1 < index || index < 0) {
        printf("ERROR: List index out of bounds!\n");
        exit(1);
        return;
    }
    int count = 0;
    int found = 0;
    Node *current = (*list)->node;
    Node *tmp;
    while (current->next != NULL) {
        if (count == index) {
            tmp = current;
            if (current->next != NULL) {
                current = current->next;
            }
            found = 1;
            break;
        }
        current = current->next;
        count++;
    }
    if (!found) {
        if (count == index) {
            tmp = current;
            if (current->next != NULL) {
                current = current->next;
            }
        }
    }

    current = current->next;
    free(tmp);
    (*list)->size--;
}

void PrintList(List *list) {
    if (list->node == NULL) {
        return;
    }
    Node *current = list->node;
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
