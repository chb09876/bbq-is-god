#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _queue
{
    int front;
    int rear;
    int *data;
    int max;
    int size;
}Queue;

void InitQueue(Queue * pq, int size)
{
    pq->data = (int *) malloc(size * sizeof(int));
    if (!pq->data)
        return ;
    pq->front = size - 1;
    pq->rear = size - 1;
    pq->max = size;
    pq->size = 0;
}

int Empty(Queue * pq)
{
    if(pq->front == pq->rear) return TRUE;
    return FALSE;
}

int Full(Queue *pq)
{
    if((pq->rear + 1) % pq->max == pq->front) return TRUE;
    return FALSE;
}

int Front(Queue *pq)
{
    if(Empty(pq) == TRUE) return -1;
    return pq->data[(pq->front + 1) % pq->max];
}

int Back(Queue *pq)
{
    if(Empty(pq) == TRUE) return -1;
    return pq->data[pq->rear];
}

void Push(Queue *pq, int data)
{
    int i;
    int count;
    int *tmp;

    if(Full(pq) == TRUE)
    {
        tmp = (int *) malloc(pq->max * sizeof(int));
        count = pq->size;
        i = 0;
        while (i < count)
        {
            tmp[i] = Pop(pq);
            i++;
        }
        pq->max *= 2;
        pq->data = (int *) realloc(pq->data, pq->max * sizeof(int));
        if (!pq->data)
                return ;
        count = pq->size;
        i = 0;
        while (i < count)
        {
            Push(pq, tmp[i]);
            i++;
        }
        free(tmp);
        Push(pq, data);
    }
    else
    {
        pq->rear = (pq->rear + 1) % pq->max;
        pq->data[pq->rear] = data;
        pq->size++;
    }
}

int Pop(Queue *pq)
{
    if(Empty(pq) == TRUE)
        return -1;
    pq->front = (pq->front + 1) % pq->max;
    pq->size--;
    return pq->data[pq->front];
}

int main(void)
{
    int     n;
    char    oper[6];
    int     i;
    int     data;
    Queue pq;

    scanf("%d", &n);
    InitQueue(&pq, 1000);

    i = 0;
    while(i < n)
    {
        scanf("%s", oper);

        if(strcmp(oper, "push") == 0)
        {
            scanf("%d", &data);
            Push(&pq, data);
        }
        else if(strcmp(oper, "pop") == 0)
        {
            printf("%d\n", Pop(&pq));
        }
        else if(strcmp(oper, "size") == 0)
        {
            printf("%d\n", pq.size);
        }
        else if(strcmp(oper, "empty") == 0)
        {
            printf("%d\n", Empty(&pq));
        }
        else if(strcmp(oper, "front") == 0)
        {
            printf("%d\n", Front(&pq));
        }
        else if(strcmp(oper, "back") == 0)
        {
            printf("%d\n", Back(&pq));
        }
        i++;
    }

    free(pq.data);
    return (0);
}

