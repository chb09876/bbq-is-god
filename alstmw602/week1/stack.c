#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	struct	stack	*next;
	int		data;
}stack;

stack *init_stack(void)
{
	stack *s;

	s = malloc(sizeof(stack));
	s->next = NULL;
	s->data = 0;
	return (s);
}

void push(stack *s, int value)
{
	stack	*n = malloc(sizeof(stack));
	stack	*tmp = s;

	n->data = value;
	n->next = NULL;
	if (s->next == NULL)
	{
		s->next = n;
	}
	else
	{
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp ->next = n;
	}
	s->data = s->data + 1;
}

int pop(stack *s)
{
	if (s->next == NULL)
		return -1;

	stack *tmp = s;
	int	out;
	while(tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	out = tmp->next->data;
	s->data = s->data - 1;
	tmp->next = NULL;
	free(tmp->next);
	return (out);
}

int size(stack *s)
{
	return (s->data);
}

int empty(stack *s)
{
	if(s->data == 0)
		return 1;
	return 0;
}

int top(stack *s)
{
	if(s->data == 0)
		return -1;

	struct	stack	*tmp;
	tmp = s;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp->data);
}
