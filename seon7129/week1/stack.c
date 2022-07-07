#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    int *data;
    int max;
}stack;

void initStack(stack *S, int size)
{
    S->data = (int *) malloc(size * sizeof(int));
    if (!S->data)
        return ;
    S->top = -1;
    S->max = size;
}

int full(stack *S)
{
    if (S->top == S->max - 1)
        return (1);
    return (0);
}

int empty(stack *S)
{
    if (S->top == -1)
        return (1);
    return (0);
}

int Top(stack *S)
{
    if (!empty(S))
        return (S->data[S->top]);
    return (-1);
}

void push(stack *S, int data)
{
    if (!full(S))
    {
        S->top++;
        S->data[S->top] = data;
    }
    else
    {
        S->max *= 2;
        S->data = (int *) realloc(S->data, S->max * sizeof(int));
        if (!S->data)
            return ;
        push(S, data);
    }
}

int pop(stack *S)
{
    int value;

    if (!empty(S))
    {
        value = S->data[S->top];
        S->top--;
        return (value);
    }
    return (-1);
}

int	ft_strcmp(char *s1, char *s2)
{
    while (*s1 == *s2 && *s1 && *s2)
    {
        s1 ++;
        s2 ++;
    }
    return ((unsigned char) *s1 - (unsigned char) *s2);
}

int	main(void)
{
    int n;
    int i;
    char order[10];
    int num;
    stack *s;

    s = (stack *) malloc(sizeof(stack));
    initStack(s, 1024);
    i = 0;

    scanf("%d", &n);
    while (i < n)
    {
        scanf("%s", order);

        if(ft_strcmp(order, "push") == 0){
            scanf("%d", &num);
            push(s, num);
        }
        else if(ft_strcmp(order, "pop") == 0){
            printf("%d\n", pop(s));
        }
        else if(ft_strcmp(order, "size") == 0){
            printf("%d\n", s->top + 1);
        }
        else if(ft_strcmp(order, "empty") == 0){
            printf("%d\n", empty(s));
        }
        else if(ft_strcmp(order, "top") == 0){
            printf("%d\n", Top(s));
        }
        else{
            printf("%s is wrong order.\n", order);
        }
        i++;
    }

    free(s->data);
    free(s);
    return (0);
}