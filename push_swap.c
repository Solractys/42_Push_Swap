/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:00 by buehara           #+#    #+#             */
/*   Updated: 2025/11/07 18:01:00 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_carray *stack)
{
	int	temp;
	int	ctrl;

	ctrl = 0;
	temp = stack->stack[ctrl];
	ctrl++;
	while (ctrl < stack->len)
	{
		if (temp > stack->stack[ctrl])
			return (FALSE);
		temp = stack->stack[ctrl];
		ctrl++;
	}
	return (TRUE);
}

void	ft_moves(t_moves *m_list, char *mov)
{
	static int	last;
	int			bit_move;

	if (m_list->len == m_list->max - 1)
		return ;
	if (m_list->len == 0)
		last = 0;
	bit_move = move_check(mov);
	if (last && (bit_move ^ last) == 3)
	{
		if ((bit_move ^ RZERO) < bit_move)
		{
			if ((bit_move ^ RSEC) < bit_move)
				m_list->moves[m_list->len - 1] = "rrr";
			else
				m_list->moves[m_list->len - 1] = "rr";
		}	
		if ((bit_move ^ SZERO) < bit_move)
			m_list->moves[m_list->len - 1] = "ss";
	}
	if (!last || last == move_check(m_list->moves[m_list->len - 1]))
		m_list->moves[m_list->len++] = mov;
	last = move_check(m_list->moves[m_list->len - 1]);
}

int	ft_log(int len, int base)
{
	int log_base;
	int result;
	int log;

	log = 0;
	log_base = base;
	result = len;
	if (len < 10)
	{
		log = 2;
		return (log);
	}
	while (result > log_base)
	{
		result = result / log_base;
		log++;
	}
	log++;
	return (log);
}

t_moves	*ft_move_add(int llen)
{
	t_moves	*list;
	int		max;

	max = llen * (1.15 * ft_log(llen, 2)) + 1;
	list = malloc(sizeof(t_moves));
	list->len = 0;
	list->max = max;
	list->moves = ft_calloc(sizeof(char *), max);
	return (list);
}

int	ft_chunks(int len)
{
	int size;

	size = 0;
	if (len > 3)
		size = (len / 3) + 1;
	else
		size = len;
	return (size);
}

void	ft_push_alg(t_moves *list, t_carray *sta, t_carray *stb)
{
	int	chunks;
	int	idx;
	t_mfunc	ft;

	chunks = ft_chunks(sta->len);
	if (chunks > 3)
		ft_push_alg(list, sta, stb);
	if (sta->len == sta->max && ft_sorted(sta))
		return ;
	idx = 0;
	while (!ft_sorted(sta))
	{
		ft = func_list(idx);
		ft_moves(list, ft(sta, stb));
	}
	ft_print_list(sta, sta->len);	
	ft_print_list(stb, stb->len);
	ft_print_move(list);	
}	

void	ft_push_swap(t_carray *stack)
{
	t_moves	*list;
	t_carray *st_b;
	int	*num;

	num = ft_calloc(sizeof(int), stack->len);
	list = ft_move_add(stack->len);
	ft_printf("\nLIST MOVE SIZE = %d\n", list->max);
	st_b = ft_new_stack(num, 0, stack->len);
	ft_push_alg(list, stack, st_b);
	ft_print_move(list);
	ft_push_free(st_b->stack, st_b);
	free(list->moves);
	free(list);
}
