#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../array/array.h"
#include "deque.h"

void deque_init(Deque *deque, size_t element_size, size_t capacity) {
    Array array;
    array_init(&array, element_size, capacity);

    deque->size = -1;
    deque->array = array;
}

void deque_push_front(Deque *deque, const void *element) {
    array_add_element_at_beginning(&deque->array, element);
    deque->size++;
}

void deque_push_rear(Deque *deque, const void *element) {
    array_add_element_at_end(&deque->array, element);
    deque->size++;
}

void deque_pop_front(Deque *deque) {
    const void *element = array_get_element(&deque->array, 0);
    array_remove_element(&deque->array, element);
    deque->size--;
}

void deque_pop_rear(Deque *deque) {
    const void *element = array_get_element(&deque->array, deque->size);
    array_remove_element(&deque->array, element);
    deque->size--;
}

void *deque_front(Deque *deque) {
    const void *element = array_get_element(&deque->array, 0);
    return (char *)element;
}

void *deque_rear(Deque *deque) {
    const void *element = array_get_element(&deque->array, deque->size);
    return (char *)element;
}

bool is_deque_empty(Deque *deque) {
    return deque->size == -1;
}

void deque_free(Deque *deque) {
    array_free(&deque->array);
    deque->size = -1;
}