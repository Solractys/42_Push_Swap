/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:00 by buehara           #+#    #+#             */
/*   Updated: 2025/11/18 18:06:37 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_carray *stack)
{
	int	temp;
	int	ctrl;
	int start;

	if (stack->len == 0)
		return (TRUE);
	ctrl = 0;
	start = stack->start;
	temp = stack->stack[start];
	while (ctrl < stack->len - 1)
	{
		ctrl++;
		start = (ctrl + stack->start) % stack->max;
		if (temp > stack->stack[start])
			return (FALSE);
		temp = stack->stack[start];
	}
	return (TRUE);
}

void	ft_moves(t_moves *m_list, char *mov)
{
//	int	last;
//	int			bit_move;

	if (m_list->len == m_list->max - 1 || mov == NULL)
		return ;
/*	if (m_list->len == 0)
		last = 0;
	else
		last = move_check(m_list->moves[m_list->len - 1]);
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
		m_list->moves[m_list->len++] = mov;*/
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

	if (llen < 4)
		max = llen + 1;
	else
		max = llen * (1.12 * ft_log(llen, 2)) + 1;
	list = malloc(sizeof(t_moves));
	list->len = 0;
	list->max = max;
	list->moves = ft_calloc(sizeof(char *), max);
	return (list);
}

int	ft_chunks(int len)
{
	int size;
	int	stacks;

	size = 0;
	stacks = 3;
	if (len > stacks)
		size = (len / stacks) + 1;
	else
		size = len;
	return (size);
}

int	ft_push_alg(t_moves *list, t_carray *sta, t_carray *stb)
{
	int		idx;
	int		check;
	char	*mov;
	t_mfunc	ft;

	if (sta->len == sta->max && ft_sorted(sta) && stb->len == 0)
		return (TRUE);
	if (list->len == list->max - 1 || move_limit(list, sta))
		return (FALSE);
	idx = -1;
	if (sta->max < 5)
		idx++;
	check = 0;
	while (idx < TOTALMOVES - 1 && (!ft_sorted(sta) || stb->len != 0))
	{
		idx++;
		if (!move_dub(idx, list, sta, stb))
			continue ;
		ft = func_list(idx);
		mov = ft(sta,stb);
		if (mov == NULL)
			continue ;
		ft_moves(list, mov);
		check = ft_push_alg(list, sta, stb);
		if (check)
			return (TRUE);
		if (check == FALSE)
			move_return(list, sta, stb);
	}
	return (FALSE);
}	

void	ft_push_rad(t_carray *sta, t_carray *stb, char to_a, char to_b)
{
//	int	len;
//	int	ctrl;
	int	idx;
	int	counter;
	int	elastic;

	counter = 0;
	elastic = 0;
//	ctrl = 4;
	idx = 0;
//	len = sta->max;
	while (idx < sta->max && sta->len != 0)
	{
		if ((sta->stack[sta->start] & BITMASK) == TOPA )
		{
			if ((sta->stack[ft_next(sta, sta->start)] & BITMASK) != TOPA)
				ft_printf("%s\n", ft_swap(sta, to_a));
			else if ((sta->stack[ft_next(sta, sta->start)] & BITMASK) == TOPA)
//				while ((sta->stack[sta->start] & BITMASK) == TOPA)
			{
				ft_printf("%s\n", ft_rotate(sta, to_a));
				counter++;
//					if (counter > 2)
				idx++;
			}
//			idx++;		
		}
		if ((sta->stack[sta->start] & BITMASK) == BOTA)
		{
			if (counter > 0)
			{
				ft_printf("%s\n", ft_push_global(stb, sta, to_b));
				while (counter > 0)
				{
					ft_printf("%s\n", ft_rev_rotate(sta, to_a));
					elastic++;
					counter--;
				}
				ft_printf("%s\n", ft_push_global(sta, stb, to_a));
			}
			ft_printf("%s\n", ft_rotate(sta, to_a));
			idx++;
			while (elastic > 0)
			{
				ft_printf("%s\n", ft_rotate(sta, to_a));
				counter++;
				elastic--;
			}
		}
		if ((sta->stack[sta->start] & BITMASK) == BOTB)
		{
			ft_printf("%s\n", ft_push_global(sta, stb, to_b));
			if (stb->len > 1)
				ft_printf("%s\n", ft_rotate(stb, to_b));
			idx++;
		}
		if ((sta->stack[sta->start] & BITMASK) == TOPB)
		{
			ft_printf("%s\n", ft_push_global(sta, stb, to_b));
			idx++;
		}
/*		if (counter > 0 && (sta->stack[sta->start] & BITMASK) == TOPA)
			while (counter > 0)
			{
				ft_printf("%s\n", ft_rev_rotate(sta, to_a));
				counter--;
			}*/
	}
	while (stb->len > 0)
	{
		if ((stb->stack[stb->start] & BITMASK) == BOTB)
		{
			ft_printf("%s\n", ft_rev_rotate(stb, to_b));
			ft_printf("%s\n", ft_push_global(stb, sta, to_a));
		}
		else
			ft_printf("%s\n", ft_push_global(stb, sta, to_a));
	}	
}

void	bit_shift(t_carray *sta)
{
	int	idx;

	idx = 0;
	while (idx < sta->max)
	{
		sta->stack[idx] >>= 2;
		idx++;
	}
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
//	ft_push_alg(list, stack, st_b);
	while (!ft_sorted(stack))
	{
		ft_push_rad(stack, st_b, 'a', 'b');
		bit_shift(stack);
	}
//	ft_print_move(list);
	ft_print_list(stack, stack->len);
	ft_print_list(st_b, st_b->len);
	ft_push_free(st_b->stack, st_b);
	free(list->moves);
	free(list);
}
