#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

typedef struct Array{
    void *data;
    size_t element_size;
    size_t size;
    size_t capacity;
} Array;

void init_array(Array *array, size_t element_size, size_t capacity);
void resize_array(Array *array);
void add_element(Array *array, const void *element);
void remove_element(Array *array, const void *element);
void *get_element(Array *array, size_t index);
void free_array(Array *array);

#endif