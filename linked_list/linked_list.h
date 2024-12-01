#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct LinkedList {
    void *data;
    size_t size;
    struct LinkedList *prev;
    struct LinkedList *next;
} LinkedList;

void linked_list_init(LinkedList *linked_list);
void linked_list_add_element(LinkedList *linked_list, const void *element, size_t element_size);
void linked_list_remove_element(LinkedList *linked_list, const void *element);
void *linked_list_get_elemenet(LinkedList *linked_list, size_t index);
void *linked_list_get_first(LinkedList *linked_list);
void *linked_list_get_last(LinkedList *linked_list);
void linked_list_free(LinkedList *linked_list);

#endif