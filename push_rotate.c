/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:03:45 by buehara           #+#    #+#             */
/*   Updated: 2025/11/05 21:03:01 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_base(t_carray *stk, char direction)
{
	if (direction == 'u')
	{
		ft_att_tcarray(stk, 1, 2, LEN_ADD);
		if (stk->len <= stk->max)
			ft_swap_base(stk, stk->start, stk, stk->end);
		ft_att_tcarray(stk, 2, 1, LEN_MINUS);
	}
	else
	{
		ft_att_tcarray(stk, POS_UP, POS_KEEP, LEN_ADD);
		if (stk->len <= stk->max)
			ft_swap_base(stk, stk->start, stk, stk->end);
		ft_att_tcarray(stk, POS_KEEP, POS_UP, LEN_MINUS);
	}
}

char	*ft_rotate(t_carray *stack, char c)
{
	char	*rotate;

	if (stack->len < 2)
		return (NULL);
	if (c == 'a')
		rotate = "ra";
	else
		rotate = "rb";
	ft_rotate_base(stack, 'u');
	return (rotate);
}

char	*rotate_a(t_carray *sta, t_carray *stb)
{
	(void)stb;
	return (ft_rotate(sta, 'a'));
}

char	*rotate_b(t_carray *sta, t_carray *stb)
{
	(void)sta;
	return (ft_rotate(stb, 'b'));
}

