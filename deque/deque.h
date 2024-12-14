#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>
#include <stdbool.h>
#include "../array/array.h"

typedef struct Deque {
    int size;
    Array array;
} Deque;

void deque_init(Deque *deque, size_t element_size, size_t capacity);
void deque_push_front(Deque *deque, const void *element);
void deque_push_rear(Deque *deque, const void *element);
void deque_pop_front(Deque *deque);
void deque_pop_rear(Deque *deque);
void *deque_front(Deque *deque);
void *deque_rear(Deque *deque);
bool is_deque_empty(Deque *deque);
void deque_free(Deque *deque);

#endif