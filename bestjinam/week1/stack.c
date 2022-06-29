/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:32:11 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/06/29 16:46:00 by ggul_jam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <unistd.h>
#include <stdlib.h>

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
