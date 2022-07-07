#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct deque
{
	struct	deque	*next;
	int				data;
}deque;

deque	*init_deque(void)
{
	deque	*q = malloc(sizeof(deque));
	q->next = NULL;
	q->data = 0;
	return (q);
}

void push_front(deque *q, int value)
{
	deque	*n = malloc(sizeof(deque));

	n->next = q->next;
	n->data = value;
	q->next = n;
	q->data = q->data + 1;
}

int pop_front(deque *q)
{
	if (q->next == NULL)
		return -1;

	deque	*tmp = q->next;
	int		out;

	q->next = q->next->next;
	q->data = q->data - 1;
	out = tmp->data;
	free(tmp);
	return (out);
}

void push_back(deque *q, int value)
{
	deque	*n = malloc(sizeof(deque));
	deque	*tmp = q;

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

int pop_back(deque *q)
{
	if (q->next == NULL)
		return -1;

	deque *tmp = q;
	int	out;
	while(tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	out = tmp->next->data;
	q->data = q->data - 1;
	tmp->next = NULL;
	free(tmp->next);
	return (out);
}

int size(deque *q)
{
	return (q->data);
}

int empty(deque *q)
{
	if(q->data == 0)
		return 1;
	return 0;
}

int front(deque *q)
{
	if(q->data== 0)
		return -1;
	return(q->next->data);
}

int back(deque *q)
{
	if(q->data == 0)
		return -1;

	struct	deque	*tmp;
	tmp = q;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp->data);
}

int main()
{
	int N;
    deque *q = init_deque();
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        char command[11];
        scanf("%s", command);
        if (!strcmp(command, "push_front"))
        {
            int value;
            scanf("%d", &value);
            push_front(q, value);
        }
        else if (!strcmp(command, "push_back"))
        {
            int value;
            scanf("%d", &value);
            push_back(q, value);
        }
        else if (!strcmp(command, "pop_front"))
        {
            if (empty(q))
                printf("%d\n", -1);
            else
                printf("%d\n", pop_front(q));
        }
        else if (!strcmp(command, "pop_back"))
        {
                printf("%d\n", pop_back(q));
        }
        else if (!strcmp(command, "size"))
        {
            printf("%d\n", size(q));
        }
        else if (!strcmp(command, "empty"))
        {
            printf("%d\n", empty(q));
        }
        else if (!strcmp(command, "front"))
        {
                printf("%d\n", front(q));
        }
        else if (!strcmp(command, "back"))
        {
                printf("%d\n", back(q));
        }
    }
}
