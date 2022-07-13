/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17827.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:01:17 by jinam             #+#    #+#             */
/*   Updated: 2022/07/13 14:48:57 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_list	*head;
	int		n;
	int		m;
	int		v;
	int		i;
	int		val;
	int		mod_m;


	n = scanf("%d", &n);
	m = scanf("%d", &m);
	v = scanf("%d", &v);
	i = 0;
	while (i < n)
	{
		scanf("%d", &val);
		ft_lstadd_back(&head, ft_lstnew(&val));
		i ++;
	}
	while ()
}
