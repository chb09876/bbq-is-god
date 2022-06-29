#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_queue
{
	int	*data;
	int	size;
	int	last;
}	t_queue;

void	init(t_queue *que, int size)
{
	que->last = -1;
	que->data = malloc(sizeof(int) * size);
	que->size = size;
}

void	push(t_queue *que, int value)
{
	if (que->last == que->size - 1)
	{
		que->size *= 2;
		que->data = realloc(que->data, que->size);
	}
	que->last++;
	que->data[que->last] = value;
}

void	relocate(t_queue *que)
{
	int	idx;

	idx = 0;
	while (idx < que->last)
	{
		que->data[idx] = que->data[idx + 1];
		idx ++;
	}
}

void	pop(t_queue *que)
{
	if (que->last == -1)
		printf("-1\n");
	else
	{
		printf("%d\n", que->data[0]);
		relocate(que);
		que->last--;
	}
}

void	size(t_queue *que)
{
	printf("%d\n", que->last + 1);
}

int	empty(t_queue *que)
{
	return (que->last == -1);
}

void	print_empty(t_queue *que)
{
	if (empty(que))
		printf("1\n");
	else
		printf("0\n");
}

void	front(t_queue *que)
{
	if (empty(que))
		printf("-1\n");
	else
		printf("%d\n", que->data[0]);
}

void	back(t_queue *que)
{
	if (empty(que))
		printf("-1\n");
	else
		printf("%d\n", que->data[que->last]);
}

int	main(void)
{
	int		n;
	char	op[1000];
	int		input;
	t_queue	que;

	init(&que, 10000);
	scanf("%d", &n);
	fgetc(stdin);
	while (n > 0)
	{
		scanf("%s", op);
		fgetc(stdin);
		if (!strcmp(op, "push"))
		{
			scanf("%d", &input);
			push(&que, input);
		}
		else if (!strcmp(op, "pop"))
			pop(&que);
		else if (!strcmp(op, "size"))
			size(&que);
		else if (!strcmp(op, "empty"))
			print_empty(&que);
		else if (!strcmp(op, "front"))
			front(&que);
		else if (!strcmp(op, "back"))
			back(&que);
		n --;
	}
	return (0);
}
