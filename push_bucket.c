/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bucket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:50:48 by buehara           #+#    #+#             */
/*   Updated: 2025/10/29 20:41:45 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	**ft_array_bucket(int size, int qty)
{
	int	**bucket;
	int	idx;

	idx = 0;
	bucket = malloc(qty * sizeof(int *));
	if (!bucket)
		return (NULL);
	while (idx < qty)
	{
		bucket[idx] = malloc(sizeof(int) * size);
		idx++;
	}
	return (bucket);
}

void	ft_bucket_sort(int **list, int len)
{
	int	**bucket;
	int	max;
	int	min;
	int	mid;
	int	qty;

	qty = len / 10;
	if (qty < 5)
		qty = 5;
	else if (qty > 1000)
		qty = 1000;
	max = ft_find_xtreme(*list, len, ft_bigger);
	min = ft_find_xtreme(*list, len, ft_smaller);
	mid = (max - min) / qty + 1;
	bucket = ft_array_bucket(mid, qty);
}
