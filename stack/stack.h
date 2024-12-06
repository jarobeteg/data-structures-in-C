#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>
#include "../array/array.h"

typedef struct Stack {
    int top;
    Array array;
} Stack;

void stack_init(Stack *stack, size_t element_size, size_t capacity);
void stack_push(Stack *stack, const void *element);
void *stack_pop(Stack *stack);
void *stack_peek(Stack *stack);
bool is_stack_empty(Stack *stack);
void stack_free(Stack *stack);

#endif