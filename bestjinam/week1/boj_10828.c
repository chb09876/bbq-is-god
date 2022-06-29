#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_stack
{
	int	top;
	int	*data;
	int	max;
}	t_stack;

void	initialize(t_stack *stack, int size)
{
	stack->data = malloc(sizeof(int) * size);
	if (!stack->data)
		return ;
	stack->top = -1;
	stack->max = size;
}

int	is_full(t_stack *stack)
{
	return (stack->top == stack->max - 1);
}

int	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

void	push(t_stack *stack, int value)
{
	if (is_full(stack))
	{
		stack->max *= 2;
		stack->data = realloc(stack->data, stack->max);
		if (!stack->data)
			return ;
	}
	stack->top ++;
	stack->data[stack->top] = value;
}

int	pop(t_stack *stack)
{
	if (stack->top == -1)
		return (-1);
	else
		return (stack->data[stack->top--]);
}

int	peek(t_stack *stack)
{
	if(is_empty(stack))
		return (-1);
	return (stack->data[stack->top]);
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
	t_stack	stack;
	int		cnt;
	char	op[10000];
	int		input;
	int		idx;

	scanf("%d", &cnt);
	fgetc(stdin);
	initialize(&stack, 1000);
	idx = 0;
	while (idx < cnt)
	{
		scanf("%s", op);
		if (!ft_strcmp(op, "push"))
		{
			scanf("%d", &input);
			fgetc(stdin);
			push(&stack, input);
		}
		else if (!strcmp(op, "pop"))
			printf("%d\n", pop(&stack));
		else if (!strcmp(op, "size"))
			printf("%d\n", stack.top + 1);
		else if (!strcmp(op, "empty"))
			printf("%d\n", is_empty(&stack));
		else if (!strcmp(op, "top"))
			printf("%d\n", peek(&stack));
		idx ++;
	}
	return (0);
}
