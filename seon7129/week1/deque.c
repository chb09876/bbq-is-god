#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue
{
    int front;
    int rear;
    int *data;
    int max;
    int cnt;
}queue;

void qExpand(queue *q);
void enqueue_front(queue *q, int data);
int dequeue_front(queue *q);
void enqueue_back(queue *q, int data);
int dequeue_back(queue *q);

void initQueue(queue *q, int size)
{
    q->data = (int *) malloc(size * sizeof(int));
    if (!q->data)
        return ;
    q->front = size - 1;
    q->rear = size - 1;
    q->max = size;
    q->cnt = 0;
}

int empty(queue *q)
{
    if (q->rear == q->front)
        return (1);
    return (0);
}

int full(queue *q)
{
    if ((q->rear + 1) % q->max == q->front)
        return (1);
    return (0);
}

int front(queue *q)
{
    int first_data;

    first_data = (q->front + 1) % q->max;
    if (!empty(q))
        return (q->data[first_data]);
    return (-1);
}

int back(queue *q)
{
    if (!empty(q))
        return (q->data[q->rear]);
    return (-1);
}

void qExpand(queue *q)
{
    int i;
    int count;
    int *buf;

    buf = (int *) malloc(q->max * sizeof(int));
    count = q->cnt;
    i = 0;
    while (i < count)
    {
        buf[i] = dequeue_front(q);
        i++;
    }
    q->max *= 2;
    q->data = (int *) realloc(q->data, q->max * sizeof(int));
    if (!q->data)
        return ;
    count = q->cnt;
    i = 0;
    while (i < count)
    {
        enqueue_front(q, buf[i]);
        i++;
    }
    free(buf);
}

void enqueue_front(queue *q, int data)
{
    if (!full(q))
    {
        q->data[q->front] = data;
        q->front = (q->front - 1 + q->max) % q->max;
        q->cnt++;
    }
    else
    {
        qExpand(q);
        enqueue_front(q, data);
    }
}

//기존 원형큐
int dequeue_front(queue *q)
{
    if (!empty(q))
    {
        q->front = (q->front + 1) % q->max;
        q->cnt--;
        return (q->data[q->front]);
    }
    return (-1);
}

//기존 원형큐
void enqueue_back(queue *q, int data)
{
    if (!full(q))
    {
        q->rear = (q->rear + 1) % q->max;
        q->data[q->rear] = data;
        q->cnt++;
    }
    else
    {
        qExpand(q);
        enqueue_back(q, data);
    }
}

int dequeue_back(queue *q)
{
    int value;

    if (!empty(q))
    {
        value = q->rear;
        q->rear = (q->rear - 1 + q->max) % q->max;
        q->cnt--;
        return (q->data[value]);
    }
    return (-1);
}

int	main(void)
{
    int n;
    int i;
    char order[11];
    queue q;

    initQueue(&q, 1024);
    i = 0;

    scanf("%d", &n);
    while (i < n)
    {
        scanf("%s", order);

        int num;
        if(strcmp(order, "push_front") == 0){
            scanf("%d", &num);
            enqueue_front(&q, num);
        }
        else if(strcmp(order, "push_back") == 0){
            scanf("%d", &num);
            enqueue_back(&q, num);
        }
        else if(strcmp(order, "pop_front") == 0){
            printf("%d\n", dequeue_front(&q));
        }
        else if(strcmp(order, "pop_back") == 0){
            printf("%d\n", dequeue_back(&q));
        }
        else if(strcmp(order, "size") == 0){
            printf("%d\n", q.cnt);
        }
        else if(strcmp(order, "empty") == 0){
            printf("%d\n", empty(&q));
        }
        else if(strcmp(order, "front") == 0){
            printf("%d\n", front(&q));
        }
        else if(strcmp(order, "back") == 0){
            printf("%d\n", back(&q));
        }
        else{
            printf("%s is wrong order.\n", order);
        }
        i++;
    }

    free(q.data);
    return (0);
}