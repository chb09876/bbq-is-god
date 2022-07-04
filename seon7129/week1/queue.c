#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front;
    int rear;
    int *data;
    int max;
    int cnt;
}queue;

void initQueue(queue *q, int size);
int empty(queue *q);
int full(queue *q);
int peek(queue *q);
void qExpand(queue *q);
void enqueue(queue *q, int data);
int dequeue(queue *q);

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

int peek(queue *q)
{
    int first_data;

    first_data = (q->front + 1) % q->max;
    if (!empty(q))
        return (q->data[first_data]);
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
        buf[i] = dequeue(q);
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
        enqueue(q, buf[i]);
        i++;
    }
    free(buf);
}

void enqueue(queue *q, int data)
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
        enqueue(q, data);
    }
}

int dequeue(queue *q)
{
    if (!empty(q))
    {
        q->front = (q->front + 1) % q->max;
        q->cnt--;
        return (q->data[q->front]);
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
    queue q;

    initQueue(&q, 1024);
    i = 0;

    scanf("%d", &n);
    while (i < n)
    {
        scanf("%s", order);

        if(ft_strcmp(order, "push") == 0){
            scanf("%d", &num);
            enqueue(&q, num);
        }
        else if(ft_strcmp(order, "pop") == 0){
            printf("%d\n", dequeue(&q));
        }
        else if(ft_strcmp(order, "size") == 0){
            printf("%d\n", q.cnt);
        }
        else if(ft_strcmp(order, "empty") == 0){
            printf("%d\n", empty(&q));
        }
        else if(ft_strcmp(order, "front") == 0){
            printf("%d\n", peek(&q));
        }
        else if(ft_strcmp(order, "back") == 0){

            if (!empty(&q))
                printf("%d\n", q.data[q.rear]);
            else
                printf("-1\n");
        }
        else{
            printf("%s is wrong order.\n", order);
        }
        i++;
    }

    free(q.data);
    return (0);
}