#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../array/array.h"
#include "stack.h"

void stack_init(Stack *stack, size_t element_size, size_t capacity) {
    Array array;
    array_init(&array, element_size, capacity);

    stack->top = -1;
    stack->array = array;
}

void stack_push(Stack *stack, const void *element) {
    array_add_element(&stack->array, element);
    stack->top++;
}

void *stack_pop(Stack *stack) {
    const void *element = array_get_element(&stack->array, stack->top);
    array_remove_element(&stack->array, element);
    stack->top--;
    return (char *)element;    
}

void *stack_peek(Stack *stack) {
    const void *element = array_get_element(&stack->array, stack->top);
    return (char *)element;
}

bool is_stack_empty(Stack *stack) {
    return stack->top == -1;
}

void stack_free(Stack *stack) {
    array_free(&stack->array);
    stack->top = -1;
}