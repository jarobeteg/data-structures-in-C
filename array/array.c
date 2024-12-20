#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../types.h"
#include "array.h"

void array_init(Array *array, size_t element_size, size_t capacity) {
    if (capacity <= 0) {
        printf("%sinit capacity has to be >= 0%s\n", RED, RESET);
        exit(EXIT_FAILURE);
    }

    array->data = malloc(capacity * element_size);
    if (!array->data) {
        printf("%smalloc failed%s\n", RED, RESET);
        exit(EXIT_FAILURE);
    }
    array->element_size = element_size;
    array->size = 0;
    array->capacity = capacity;
}

void array_resize(Array *array) {
    size_t new_capacity = array->capacity * 2;
    void *new_data = realloc(array->data, new_capacity * array->element_size);
    if (!new_data) {
        printf("%srealloc failed%s\n", RED, RESET);
        exit(EXIT_FAILURE);
    }
    array->data = new_data;
    array->capacity = new_capacity;
}

void array_add_element_at_end(Array *array, const void *element) {
    if (array->size == array->capacity) {
        array_resize(array);
    }
    void *target = (char *)array->data + (array->size * array->element_size);
    memcpy(target, element, array->element_size);
    array->size++;
}

void array_add_element_at_beginning(Array *array, const void *element) {
    if (array->size == array->capacity) {
        array_resize(array);
    }

    for (size_t i = array->size; i > 0; i--) {
        void *current = (char *)array->data + i * array->element_size;
        void *previous = (char *)array->data + (i - 1) * array->element_size;
        memcpy(current, previous, array->element_size);
    }

    memcpy(array->data, element, array->element_size);
    array->size++;
}

void array_remove_element(Array *array, const void *element) {
    size_t i = 0;
    int found = 0;
    for (i = 0; i < array->size; i++) {
        if (memcmp((char *)array->data + i * array->element_size, element, array->element_size) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%selement not found in array%s\n", RED, RESET);
        return;
    }

    for (size_t j = i; j < array->size - 1; j++) {
        memcpy((char *)array->data + j * array->element_size,
        (char *)array->data + (j + 1) * array->element_size,
        array->element_size);
    }

    array->size--;
}

void *array_get_element(Array *array, size_t index) {
    if (index >= array->size) {
        printf("%sout of bounds%s\n", RED, RESET);
        exit(EXIT_FAILURE);
    }
    return (char *)array->data + (index * array->element_size);
}

void array_free(Array *array) {
    free(array->data);
    array->data = NULL;
    array->element_size = 0;
    array->size = 0;
    array->capacity = 0;
}