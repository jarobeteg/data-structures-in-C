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
void push(Stack *stack);
void *pop(Stack *stack);
void *peek(Stack *stack);
bool is_empty(Stack *stack);
void stack_free(Stack *stack);

#endif