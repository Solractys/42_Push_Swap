/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:27:12 by buehara           #+#    #+#             */
/*   Updated: 2025/11/02 17:44:50 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_sort(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int ft_bigger(int a, int b)
{
	if (a > b)
		return (TRUE);
	return (FALSE);
}

int	ft_smaller(int a, int b)
{
	if (a < b)
		return (TRUE);
	return (FALSE);
}

int	ft_find_xtreme(int *list, int len, int (*f) (int, int))
{
	int result;
	int	idx;

	idx = 0;
	result = list[0];
	while (idx < len)
	{
		if (f(list[idx], result))
			result = list[idx];
		idx++;
	}
	return (result);
}

int	ft_find_digits(int *list, int len)
{
	int	max;
	int	count;

	max = ft_find_xtreme(list, len, ft_bigger);
	count = 0;
	while (max > 9)
	{
		max /= 10;
		count++;
	}
	count++;
	return (count);
}
