#include <stdio.h>
#include <unistd.h>

typedef struct node
{
	struct	node	*next;
	int		data;

}node;

node *init(void)
{
	node	*head;
	
	head = malloc(sizeof(node));
	head->next = NULL;
	return (head);
}

void create(node *h, int value)
{
	node	*n = malloc(sizeof(node));
	node	*tmp = h;

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
		tmp->next = n;
	}
}

void read(node *h, int value)
{
	node	*tmp = h;
	
	while (tmp->next != NULL)
	{
		if (tmp->data == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void updata(node *h, int target, int value)
{
	node	*tmp = h;

	while (tmp->next != NULL)
	{
		if (tmp->data == target)
		{
			tmp->data = value;
			return ;
		}
		tmp = tmp->next;
	}
}

void delete(node *h, int target)
{
	node	*tmp = h;
	node	*prev;

	if(h->next->data = target)
	{
		tmp = h->next;
		h->next = h->next->next;
		free(tmp);
		return ;
	}
	while (tmp->next != NULL)
	{
		if (tmp->data == target)
			break;
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = prev->next->next;
	free(tmp);
}

