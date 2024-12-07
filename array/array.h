#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

typedef struct Array{
    void *data;
    size_t element_size;
    size_t size;
    size_t capacity;
} Array;

void array_init(Array *array, size_t element_size, size_t capacity);
void array_resize(Array *array);
void array_add_element_at_end(Array *array, const void *element);
void array_add_element_at_beginning(Array *array, const void *element);
void array_remove_element(Array *array, const void *element);
void *array_get_element(Array *array, size_t index);
void array_free(Array *array);

#endif