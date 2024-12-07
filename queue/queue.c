#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../array/array.h"
#include "queue.h"

void queue_init(Queue *queue, size_t element_size, size_t capacity) {
    Array array;
    array_init(&array, element_size, capacity);

    queue->size = -1;
    queue->array = array;
}

void queue_free(Queue *queue) {
    array_free(&queue->array);
    queue->size = -1;
}