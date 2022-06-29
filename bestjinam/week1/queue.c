/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:35:49 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/06/29 22:23:43 by ggul_jam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_queue.h"
#include <stdlib.h>
#include <stdio.h>

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
