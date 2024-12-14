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

void deque_free(Deque *deque) {
    array_free(&deque->array);
    deque->size = -1;
}