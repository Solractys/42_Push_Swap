/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:06:56 by buehara           #+#    #+#             */
/*   Updated: 2025/11/12 17:13:24 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_carray *stack_a, t_carray *stack_b)
{
		ft_att_tcarray(stack_b, POS_UP, POS_KEEP, LEN_ADD);
		ft_swap_base(stack_a, stack_a->start, stack_b, stack_b->start);
		ft_att_tcarray(stack_a, POS_DOWN, POS_KEEP, LEN_MINUS);
}
/*
char	*ft_push(t_carray *stack_a, t_carray *stack_b, char direction)
{
	char	*push;

	if (direction == 'b')
	{
		if (stack_a->len < 1)
			return (NULL);
		push = "pb";
		ft_att_tcarray(stack_b, POS_UP, POS_KEEP, LEN_ADD);
		ft_swap_base(stack_a, stack_a->start, stack_b, stack_b->start);
		ft_att_tcarray(stack_a, POS_DOWN, POS_KEEP, LEN_MINUS);
	}
	if (direction == 'a')
	{
		if (stack_b->len < 1)
			return (NULL);
		push = "pa";
		ft_att_tcarray(stack_a, POS_UP, POS_KEEP, LEN_ADD);
		ft_swap_base(stack_b, stack_b->start, stack_a, stack_a->start);
		ft_att_tcarray(stack_b, POS_DOWN, POS_KEEP, LEN_MINUS);
	}
	return (push);
}*/

char	*push_a(t_carray *sta, t_carray *stb)
{
	if (stb->len < 1)
		return (NULL);
	ft_push(stb, sta);
	return ("pa");
}

char	*push_b(t_carray *sta, t_carray *stb)
{
	if (sta->len < 1)
		return (NULL);
	ft_push(sta, stb);
	return ("pb");
}
