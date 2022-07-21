/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2751_insertion_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:06:49 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/07/18 23:36:32 by ggul_jam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

static void	_insertion_sort(int *data, int size)
{
	int	i;
	int	j;
	int	insert;

	i = 0;
	while (++i < size)
	{
		j = i - 1;
		insert = data[i];
		while (j >= 0 && data[j] > insert)
		{
			data[j + 1] = data[j];
			j --;
		}
		data[j + 1] = insert;
	}

}

int	main(void)
{
	int	n;
	int	i;
	int	*data;

	scanf("%d", &n);
	data = malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
		scanf("%d", &data[i++]);
	_insertion_sort(data, n);
	i = 0;
	while (i < n)
		printf("%d\n", data[i++]);
}
