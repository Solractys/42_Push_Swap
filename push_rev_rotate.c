/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:50:34 by buehara           #+#    #+#             */
/*   Updated: 2025/11/05 21:04:14 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_rev_rotate(t_carray *stack, char c)
{
	char	*rrotate;

	if (stack->len < 2)
		return (NULL);
	if (c == 'a')
		rrotate = "rra";
	else
		rrotate = "rrb";
	ft_rotate_base(stack, 'd');
	return (rrotate);
}

char	*rev_rotate_a(t_carray *sta, t_carray *stb)
{
	(void)stb;
	return (ft_rev_rotate(sta, 'a'));
}

char	*rev_rotate_b(t_carray *sta, t_carray *stb)
{
	(void)sta;
	return (ft_rev_rotate(stb, 'b'));
}
