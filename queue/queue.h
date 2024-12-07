#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>
#include "../array/array.h"

typedef struct Queue {
    int size;
    Array array;
} Queue;

void queue_init(Queue *queue, size_t element_size, size_t capacity);
void queue_enqueue(Queue *queue, const void *element);
void queue_dequeue(Queue *queue);
void *queue_front(Queue *queue);
void *queue_rear(Queue *queue);
bool is_queue_empty(Queue *queue);
void queue_free(Queue *queue);

#endif