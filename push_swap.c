/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:00 by buehara           #+#    #+#             */
/*   Updated: 2025/11/02 21:13:30 by buehara          ###   ########.fr       */
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
	char	*last_move;

	if (m_list->len == 0)
		last_move = NULL;
	else
		last_move = m_list->moves[m_list->len - 1];
	if (last_move && mov[0] == 's' && last_move[0] == 's')
		if (last_move[1] != 's' && last_move[1] != mov[1])
			m_list->moves[m_list->len - 1] = "ss";
	if (last_move && mov[0] == 'r' && last_move[0] == 'r')
	{
		if (last_move[1] != 'r' && mov[1] != 'r' && last_move[1] != mov[1])
			m_list->moves[m_list->len - 1] = "rr";
		if (last_move[2] && last_move[2] != 'r' && mov[2]
			&& mov[2] != 'r' && last_move[2] != mov[2])
			m_list->moves[m_list->len - 1] = "rrr";
	}
	if (!last_move || !ft_strncmp(last_move, m_list->moves[m_list->len - 1], 3))
		m_list->moves[m_list->len++] = mov;
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
		result = len / log_base;
		log++;
	}
	log++;
	return (log);
}

t_moves	*ft_move_add(int llen)
{
	t_moves	*list;
	int		max;

	max = llen * ft_log(llen, 10) + 1;
	list = malloc(sizeof(t_moves));
	list->len = 0;
	list->max = max;
	list->moves = ft_calloc(sizeof(char *), max);
	return (list);
}

int	ft_cluster(int len)
{
	int size;

	size = 0;
	if (len > 3)
		size = len / 3;
	size++;
	return (size);
}

void	ft_push_alg(t_moves *list, t_carray *sta, t_carray *stb)
{
	int	cluster;
	int	max;
	int min;

	cluster = ft_cluster(sta->len);
	max = ft_find_xtreme(sta->stack, sta->len, ft_bigger);
	min = ft_find_xtreme(sta->stack, sta->len, ft_smaller);
	if (sta->len == sta->max && ft_sorted(sta))
		return ;
	if (list->len - 1 == list->max)
		return ;
	while (sta->len > cluster)
	{
		if (sta->stack[sta->start] > ft_next(sta))
			ft_moves(list, ft_push(sta, stb, 'a')); 
	}
	ft_print_array(stb, "Stack B");
}	

void	ft_push_swap(t_carray *stack)
{
	t_moves	*list;
	t_carray *st_b;
	int	*num;

	num = ft_calloc(sizeof(int), stack->len);
	list = ft_move_add(stack->len);
	st_b = ft_new_stack(num, 0, stack->len);
	ft_push_alg(list, stack, st_b);
	ft_print_move(list);
	ft_push_free(st_b->stack, st_b);
	free(list->moves);
	free(list);
}
