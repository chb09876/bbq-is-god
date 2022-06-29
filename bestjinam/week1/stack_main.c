/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:53:08 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/06/29 18:46:34 by ggul_jam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include "ft_stack.h"

void	initialize(t_stack *stack, int size);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		is_empty(t_stack *stak);

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
	char	op[15];
	int		input;
	int		idx;

	scanf("%d", &cnt);
	fgetc(stdin);
	initialize(&stack, 100);
	idx = 0;
	while (idx < cnt)
	{
		scanf("%s", op);
		fgetc(stdin);
		if (!ft_strcmp(op, "push"))
		{
			scanf("%d", &input);
			fgetc(stdin);
			push(&stack, input);
		}
		else if (!ft_strcmp(op, "pop"))
			printf("%d\n", pop(&stack));
		else if (!ft_strcmp(op, "size"))
			printf("%d\n", stack.top + 1);
		else if (!ft_strcmp(op, "empty"))
			printf("%d\n", is_empty(&stack));
		else if (!ft_strcmp(op, "top"))
		{
			if (stack.top == -1)
				printf("%d\n", -1);
			else
				printf("%d\n", stack.data[stack.top]);
		}
		idx ++;
	}
	free(stack.data);
	return (0);
}
