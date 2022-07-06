#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct deque
{
    int size;
    int *dequeArr;
}deque;

void    push_front(int dequeArr[], int data, int f_idx, int size)
{
    dequeArr[f_idx] = data;
}

void    push_back(int dequeArr[], int data, int b_idx, int size)
{
    dequeArr[b_idx] = data;
}

int    size(int arr[], int f_idx)
{
    int cnt = f_idx + 1;
    while (arr[cnt] != '\0')
    {
        cnt++;
    }
    return (cnt - f_idx - 1);
}

void    pop_front(int dequeArr[], int f_idx, int len)
{
    printf("%d\n", dequeArr[f_idx + 1]);
    dequeArr[f_idx + 1] = '\0';
}

void    pop_back(int dequeArr[], int b_idx, int len)
{
    printf("%d\n", dequeArr[b_idx - 1]);
    dequeArr[b_idx - 1] = '\0';
}

void    empty(int dequeArr[], int f_idx)
{
    if (size(dequeArr, f_idx) != 0)
    {
        printf("%d\n", 0);
    }
    else
    {
        printf("%d\n", 1);
    }
}

void    front(int dequeArr[], int f_idx)
{
    if (size(dequeArr, f_idx) != 0)
    {
        printf("%d\n", dequeArr[f_idx + 1]);
    }
    else
    {
        printf("%d\n", -1);
    }
}

void    back(int dequeArr[], int f_idx, int b_idx)
{
    if (size(dequeArr, f_idx) != 0)
    {
        printf("%d\n", dequeArr[b_idx - 1]);
    }
    else
    {
        printf("%d\n", -1);
    }
}

int main(void)
{
    deque d1;
    scanf("%d", &d1.size);

    int     i = 0;
    char    command[20];
    int     b_idx = d1.size;
    int     f_idx = d1.size - 1;

    d1.dequeArr = (int*) malloc(sizeof(int) * (2 * d1.size));

    while (i < d1.size)
    {
        scanf("%s", command);

        if (strcmp(command, "push_front") == 0)
        {
            int f_data;
            scanf("%d", &f_data);
            push_front(d1.dequeArr, f_data, f_idx, d1.size);
            f_idx--;
        }
        else if (strcmp(command, "push_back") == 0)
        {
            int b_data;
            scanf("%d", &b_data);
            push_back(d1.dequeArr, b_data, b_idx, d1.size);
            b_idx++;
        }
        else if (strcmp(command, "pop_front") == 0)
        {
            if ((b_idx == d1.size) && (size(d1.dequeArr, f_idx) == 1))
            {
                printf("%d\n", d1.dequeArr[b_idx - 1]);
                d1.dequeArr[b_idx - 1] = '\0';
                b_idx--;
            }
            else if (size(d1.dequeArr, f_idx) == 0)
            {
                printf("%d\n", -1);
            }
            else
            {
                pop_front(d1.dequeArr, f_idx, d1.size);
                f_idx++;
            }
        }
        else if (strcmp(command, "pop_back") == 0)
        {
            if ((f_idx == d1.size - 2) && (size(d1.dequeArr, f_idx) == 1))
            {
                printf("%d\n", d1.dequeArr[f_idx + 1]);
                d1.dequeArr[f_idx + 1] = '\0';
                f_idx++;
            }
            else if (size(d1.dequeArr, f_idx) == 0)
            {
                printf("%d\n", -1);
            }
            else
            {
                pop_back(d1.dequeArr, b_idx, d1.size);
                b_idx--;
            }
        }
        else if (strcmp(command, "size") == 0)
        {
            printf("%d\n", size(d1.dequeArr, f_idx));
        }
        else if (strcmp(command, "empty") == 0)
        {
            empty(d1.dequeArr, f_idx);
        }
        else if (strcmp(command, "front") == 0)
        {
            front(d1.dequeArr, f_idx);
        }
        else if (strcmp(command, "back") == 0)
        {
            back(d1.dequeArr, f_idx, b_idx);
        }
        i++;
    }
    free(d1.dequeArr);
    return (0);
}