#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
	struct	queue	*next;
	int				data;
}queue;

queue	*init_queue(void)
{
	queue	*q;

	q = malloc(sizeof(queue));
	q->next = NULL;
	q->data = 0;
	return (q);
}

void push(queue *q, int value)
{
	queue	*n = malloc(sizeof(queue));
	queue	*tmp = q;

	n->data = value;
	n->next = NULL;
	if (q->next == NULL)
	{
		q->next = n;
	}
	else
	{
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp ->next = n;
	}
	q->data = q->data + 1;
}

int pop(queue *q)
{
	if (q->next == NULL)
		return -1;

	int		out;
	queue	*tmp = q->next;

	out = tmp->data;
	q->next = q->next->next;
	q->data = q->data - 1;
	free(tmp);
	return (out);
}

int size(queue *q)
{
	return (q->data);
}

int empty(queue *q)
{
	if(q->data == 0)
		return 1;
	return 0;
}

int front(queue *q)
{
	if(q->data ==0)
		return -1;
	return(q->next->data);
}

int back(queue *q)
{
	if(q->data == 0)
		return -1;

	struct	queue	*tmp;
	tmp = q;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp->data);
}
