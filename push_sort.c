/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:50:44 by buehara           #+#    #+#             */
/*   Updated: 2025/11/20 19:53:14 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_in_sort(int *list, int len)
{
	int	in;
	int	out;
	int	temp;

	if (len > 1)
	{
		out = 1;
		while (out < len)
		{
			in = out;
			temp = list[out];
			while (in > 0 && temp < list[in - 1])
			{
				list[in] = list[in - 1];
				in--;
			}
			list[in] = temp;
			out++;
		}
	}
}
