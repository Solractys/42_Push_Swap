/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:00 by buehara           #+#    #+#             */
/*   Updated: 2025/11/04 21:00:58 by buehara          ###   ########.fr       */
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
	char	*last;

	if (m_list->len == m_list->max - 1)
		return ;
	if (m_list->len == 0)
		last = NULL;
	else
		last = m_list->moves[m_list->len - 1];
	if (last && mov && mov[0] == 's' && last[0] == 's')
		if (last[1] != 's' && last[1] != mov[1])
			m_list->moves[m_list->len - 1] = "ss";
	if (last && mov && mov[0] == 'r' && last[0] == 'r')
	{
		if (last[1] != 'r' && mov[1] != 'r' && last[1] != mov[1])
			m_list->moves[m_list->len - 1] = "rr";
		if (last[2] && last[2] != 'r' && mov[2] && mov[2] != 'r' 
				&& last[2] != mov[2])
			m_list->moves[m_list->len - 1] = "rrr";
	}
	if (!last || !ft_strncmp(last, m_list->moves[m_list->len - 1], 3))
	{
		m_list->moves[m_list->len] = mov;
		m_list->len++;
	}
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

	//max = llen * (ft_log(llen, 10) + 1);
	max = llen * 10;
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
	if (len > 6)
		size = len / 3 + 1;
	else
		size = len;
	return (size);
}

void	ft_push_alg(t_moves *list, t_carray *sta, t_carray *stb)
{
//	int	chunks;

//	chunks = ft_chunks(sta->len);
	if (sta->len == sta->max && ft_sorted(sta))
		return ;
	ft_moves(list, ft_push(sta, stb, 'a'));
	ft_moves(list, ft_rotate(stb, 'u')); 
	ft_print_list(sta, sta->len);
	ft_print_list(stb, stb->len);
	if (sta->stack[sta->start] < sta->stack[ft_next(sta, sta->start)])
	{
		ft_moves(list, ft_rotate(sta, 'u')); 
		ft_print_list(sta, sta->len);
	}
	if (sta->len < stb->len)
		ft_push(sta, stb, 'b');
	if (list->len == list->max - 1)
		return ;
	ft_push_alg(list, sta, stb);
	ft_push(sta, stb, 'b');
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
