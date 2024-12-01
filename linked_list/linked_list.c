#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../types.h"
#include "linked_list.h"

void linked_list_init(LinkedList *linked_list) {
    linked_list->data = NULL;
    linked_list->size = 0;
    linked_list->prev = NULL;
    linked_list->next = NULL;
}

void linked_list_add_element(LinkedList *linked_list, const void *element, size_t element_size) {
    LinkedList *new_node = (LinkedList *)malloc(sizeof(LinkedList));
    if (!new_node) {
        printf("%smalloc failed%s\n", RED, RESET);
        exit(EXIT_FAILURE);
    }

    new_node->data = malloc(element_size);
    if (!new_node->data) {
        printf("%smalloc failed%s\n", RED, RESET);
        exit(EXIT_FAILURE);
    }

    memcpy(new_node->data, element, element_size);

    new_node->prev = NULL;
    new_node->next = NULL;

    if (linked_list->size == 0) {
        linked_list->next = new_node;
        new_node->prev = linked_list;
    } else {
        LinkedList *last = linked_list;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    }

    linked_list->size++;
}