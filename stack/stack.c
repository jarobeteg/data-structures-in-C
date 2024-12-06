#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../types.h"
#include "../array/array.h"
#include "stack.h"

void stack_init(Stack *stack, size_t element_size, size_t capacity) {
    Array array;
    array_init(&array, element_size, capacity);

    int value = 10;
    array_add_element(&array, &value);
    value = 20;
    array_add_element(&array, &value);

    stack->top = -1;
    stack->array = array;
}

void stack_free(Stack *stack) {
    array_free(&stack->array);\
    stack->top = -1;
}