/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10814_counting_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:43:03 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/07/27 17:45:22 by ggul_jam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	char			*name;
	struct s_node	*next;
	struct s_node	*last;

}	t_node;

void	_create_node(t_node **head, char *name)
{
	if (!*head)
	{
		*head = malloc(sizeof(t_node));
		(*head)->name = strdup(name);
		(*head)->next = (void *) 0;
		(*head)->last = *head;
	}
	else
	{
		(*head)->last->next = malloc(sizeof(t_node));
		(*head)->last->next->name = strdup(name);
		(*head)->last->next->next = (void *) 0;
		(*head)->last = (*head)->last->next;
	}


}

int	main(void)
{
	int		n;
	int		a;
	char	name[1000000];

	t_node	*list[201] = {0, };

	scanf("%d", &n);
	while (n)
	{
		scanf("%d", &a);
		scanf("%s", name);
		_create_node(&list[a] , name);
		n --;
	}

	for (int i = 1; i <= 200; i ++)
	{
		while (list[i])
		{
			printf("%d %s\n", i, list[i]->name);
			list[i] = list[i]->next;
		}
	}
}
