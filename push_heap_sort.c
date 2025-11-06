/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_heap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:20:18 by buehara           #+#    #+#             */
/*   Updated: 2025/11/04 12:35:15 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_down_the_tree(int *list, int index, int len)
{
	int	j;

	while ((2 * index + 1) < len)
	{
		j = 2 * index + 1;
		if ((j + 1) < len && list[j+1] > list[j])
			j++;
		if (list[index] >= list[j])
			break ;
		ft_swap_sort(&list[index], &list[j]);
		index = j;
	}
}

void	ft_heapfy(int *list, int len)
{
	int	index;

	index = len / 2;
	while (index >= 0)
	{
		ft_down_the_tree(list, index, len);
		index--;
	}
}

void	ft_heap_sort(int *list, int len)
{
	ft_heapfy(list, len);

	while (len > 0)
	{
		len--;
		ft_swap_sort(&list[len], &list[0]);
		ft_down_the_tree(list, 0, len);
	}
}
