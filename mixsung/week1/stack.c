#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *array;
    int array_size;
    int top;
} Stack;

void init (Stack *stack)
{
    stack->top = -1;
    stack->array_size = 1;
    stack->array = (int *)malloc(stack->array_size * sizeof(int));
}

int full(Stack *stack)
{
    if (stack->top == stack->array_size - 1)
        return 1;
    else
        return 0;
}

int empty(Stack *stack)
{
    if (stack->top == -1)
        return 1;
    else
        return 0;
}

void push(Stack *stack, unsigned int data)
{
    if (full(stack))
    {
        stack->array_size = stack->array_size * 2;
        stack->array = (int *)realloc(stack->array, stack->array_size * sizeof(int));
    }
    stack->array[stack->top++] = data;
}

int pop (Stack *stack)
{

}

int size (Stack *stack)
{

}

int top (Stack *stack)
{

}

int main()
{
    Stack stack;
    init(&stack);
    return 0;
}

