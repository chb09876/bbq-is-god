#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int *StackArr;
}Stack;

void    push(int stack[], int data, int idx)
{
    stack[idx] = data;
}

int    size(int arr[])
{
    int cnt = 0;
    while (arr[cnt] != '\0')
    {
        cnt++;
    }
    return (cnt);
}

void    pop(int stack[], int idx)
{
    if (size(stack) != 0)
    {
        printf("%d\n", stack[idx - 1]);
        stack[idx - 1] = '\0';
    }
}

void    empty(int stack[])
{
    if (size(stack) != 0)
    {
        printf("%d\n", 0);
    }
    else
    {
        printf("%d\n", 1);
    }
}

void    top(int stack[], int idx)
{
    if (size(stack) != 0)
    {
        printf("%d\n", stack[idx - 1]);
    }
    else
    {
        printf("%d\n", -1);
    }
}

int main(void)
{
    int     i = 0;
    int     idx = 0;
    char    command[10];

    Stack s1;
    scanf("%d", &s1.size);

    s1.StackArr = (int*) malloc(sizeof(int) * s1.size);

    while (i < s1.size)
    {
        scanf("%s", command);

        if (strcmp(command, "push") == 0)
        {
            int data;
            scanf("%d", &data);
            push(s1.StackArr, data, idx);
            ++idx;
        }
        else if (strcmp(command, "pop") == 0)
        {
            if (idx == 0)
            {
                i++;
                printf("%d\n", -1);
                continue;
            }
            else
            {
                pop(s1.StackArr, idx);
                idx--;
            }
        }
        else if (strcmp(command, "size") == 0)
        {
            printf("%d\n", size(s1.StackArr));
        }
        else if (strcmp(command, "empty") == 0)
        {
            empty(s1.StackArr);
        }
        else if (strcmp(command, "top") == 0)
        {
            top(s1.StackArr, idx);
        }
        i++;
    }
    free(s1.StackArr);
    return (0);
}