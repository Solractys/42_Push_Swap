/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:56:35 by buehara           #+#    #+#             */
/*   Updated: 2025/11/02 21:05:55 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_carray	*ft_new_stack(void *content, int len, int max)
{
	t_carray	*new;

	new = malloc(sizeof(t_carray));
	if (!new)
		return (NULL);
	new->start = 0;
	new->end = len - 1;
	new->len = len;
	new->max = max;
	new->stack = content;
	return (new);
}

void	ft_att_tcarray(t_carray *stack, int start, int end, int len)
{
	stack->len += (len);
	stack->start = (stack->start + (stack->max - 1) + (start)) % stack->max;
	stack->end = (stack->end + (stack->max - 1) + (end)) % stack->max;
}

int	ft_next(t_carray *stack)
{
	int	next;

	next = (stack->start + (stack->max - 1) + (POS_DOWN)) % stack->max;
	return (next);
}

int	ft_before(t_carray *stack)
{
	int before;

	before = (stack->start + (stack->max - 1) + (POS_UP)) % stack->max;
	return (before);
}

