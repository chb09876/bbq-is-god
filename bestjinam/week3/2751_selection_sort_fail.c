/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2751.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:28:28 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/07/18 23:03:52 by ggul_jam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

static void	_selection_sort(int min, int *data, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	idx;

	i = 0;
	while (i < size)
	{
		min = 2147483647;
		j = i - 1;
		while (++j < size)
		{
			if (data[j] < min)
			{
				min = data[j];
				idx = j;
			}
		}
		tmp = data[i];
		data[i++] = data[idx];
		data[idx] = tmp;
	}
	i = 0;
	while (i < size)
		printf("%d\n", data[i++]);
}

int	main(void)
{
	int	n;
	int	i;
	int	*data;
	int	min;
	int	tmp;

	scanf("%d", &n);
	data = malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
		scanf("%d", &data[i++]);
	_selection_sort(min, data, n);
}
