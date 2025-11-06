/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:07:14 by buehara           #+#    #+#             */
/*   Updated: 2025/11/05 20:59:38 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_base(t_carray *stk_a, int idx_a, t_carray *stk_b, int idx_b)
{
	int	temp;

	temp = stk_a->stack[idx_a];
	stk_a->stack[idx_a] = stk_b->stack[idx_b];
	stk_b->stack[idx_b] = temp;
}

char	*ft_swap(t_carray *stack, char c)
{
	char	*swap;

	if (stack->len < 2)
		return (NULL);
	if (c == 'a')
		swap = "sa";
	else
		swap = "sb";
	ft_swap_base(stack, stack->start, stack, ft_next(stack, stack->start));
	return (swap);
}

char	*swap_a(t_carray *sta, t_carray *stb)
{
	(void)stb;
	return (ft_swap(sta, 'a'));
}

char	*swap_b(t_carray *sta, t_carray *stb)
{
	(void)sta;
	return (ft_swap(stb, 'b'));
}
