#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int *queueArr;
}Queue;

void    push(int queueArr[], int data, int f_idx)
{
    queueArr[f_idx] = data;
}

int    size(int arr[], int f_idx)
{
    int cnt = f_idx;
    while (arr[cnt] != '\0')
    {
        cnt++;
    }
    return (cnt - f_idx);
}

void    pop(int queueArr[], int f_idx)
{
    if (size(queueArr, f_idx) != 0)
    {
        printf("%d\n", queueArr[f_idx]);
        queueArr[f_idx] = '\0';
    }
}

void    empty(int queueArr[], int f_idx)
{
    if (size(queueArr, f_idx) != 0)
    {
        printf("%d\n", 0);
    }
    else
    {
        printf("%d\n", 1);
    }
}

void    front(int queueArr[], int f_idx)
{
    if (size(queueArr, f_idx) != 0)
    {
        printf("%d\n", queueArr[f_idx]);
    }
    else
    {
        printf("%d\n", -1);
    }
}

void    back(int queueArr[], int b_idx, int f_idx)
{
    if (size(queueArr, f_idx) != 0)
    {
        printf("%d\n", queueArr[b_idx - 1]);
    }
    else
    {
        printf("%d\n", -1);
    }
}

int main(void)
{
    int     i = 0;
    int     f_idx = 0;
    int     b_idx = 0;
    char    command[10];

    Queue q1;
    scanf("%d", &q1.size);

    q1.queueArr = (int*) malloc(sizeof(int) * q1.size);

    while (i < q1.size)
    {
        scanf("%s", command);

        if (strcmp(command, "push") == 0)
        {
            int data;
            scanf("%d", &data);
            push(q1.queueArr, data, b_idx);
            b_idx++;
        }
        else if (strcmp(command, "pop") == 0)
        {
            if (b_idx == f_idx)
            {
                printf("%d\n", -1);
            }
            else
            {
                pop(q1.queueArr, f_idx);
                f_idx++;
            }
        }
        else if (strcmp(command, "size") == 0)
        {
            printf("%d\n", size(q1.queueArr, f_idx));
        }
        else if (strcmp(command, "empty") == 0)
        {
            empty(q1.queueArr, f_idx);
        }
        else if (strcmp(command, "front") == 0)
        {
            front(q1.queueArr, f_idx);
        }
        else if (strcmp(command, "back") == 0)
        {
            back(q1.queueArr, b_idx, f_idx);
        }
        i++;
    }
    free(q1.queueArr);
    return (0);
}