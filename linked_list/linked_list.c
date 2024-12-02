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
    if (linked_list->data == NULL) {
        linked_list->data = malloc(element_size);
        if (!linked_list->data) {
            printf("%smalloc failed%s\n", RED, RESET);
            exit(EXIT_FAILURE);
        }

        memcpy(linked_list->data, element, element_size);
        return;
    }

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

void linked_list_remove_element(LinkedList *linked_list, const void *element, size_t element_size) {
    LinkedList *current = linked_list;
    while (current != NULL) {
        if (memcmp(current->data, element, element_size) == 0) {
            
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            //todo edge case when the first element gets removed

            free(current->data);
            free(current);

            linked_list->size--;
            return;
        }
        current = current->next;
    }
    printf("%selement not found in linked list%s\n", RED, RESET);
}

void *linked_list_get_element(LinkedList *linked_list, size_t index) {
    if (index >= linked_list->size) {
        printf("%sout of bounds%s\n", RED, RESET);
        exit(EXIT_FAILURE);
    }

    LinkedList *current = linked_list;
    size_t current_index = 0;
    while (current_index < index) {
        current = current->next;
        current_index++;
    }

    return current->data;
}

void *linked_list_get_first(LinkedList *linked_list) {
    return linked_list->data;
}

void *linked_list_get_last(LinkedList *linked_list) {
    LinkedList *last = linked_list;
    while (last->next != NULL) {
        last = last->next;
    }

    return last->data;
}

void linked_list_free(LinkedList *linked_list) {
    LinkedList *current = linked_list->next;
    while (current) {
        LinkedList *next_node = current->next;
        free(current->data);
        free(current);
        current = next_node;
    }

    if (linked_list->data) {
        free(linked_list->data);
        linked_list->data = NULL;
    }
    linked_list->size = 0;
    linked_list->next = NULL;
}