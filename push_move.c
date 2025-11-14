/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:15:19 by buehara           #+#    #+#             */
/*   Updated: 2025/11/13 20:36:07 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mfunc	func_list(int index)
{
	t_mfunc	map[TOTALMOVES];

	map[PB] = &push_b;
	map[RRA] = &rev_rotate_a;
	map[RA] = &rotate_a;
	map[SA] = &swap_a;
	map[SB] = &swap_b;
	map[RB] = &rotate_b;
	map[RRB] = &rev_rotate_b;
	map[PA] = &push_a;

	return (map[index]);
};

int	move_check(char *mov)
{
	int	bit_move;

	if (!mov)
		return (FALSE);
	bit_move = 0;
	if (mov[0] == 'r')
		bit_move |= RZERO;
	else if (mov[0] == 's')
		bit_move |= SZERO;
	else if (mov[0] == 'p')
		bit_move |= PZERO;
	if (mov[1] == 'r' && mov[2])
		bit_move |= RSEC;
	if ((mov[1] == 'r' && !mov[2]) || mov[2] == 'r' || mov[1] == 's')
		bit_move |= DOUBLE;
	if (mov[1] == 'a' || mov[2] == 'a')
		bit_move |= AMASK;
	if (mov[1] == 'b' || mov[2] == 'b')
		bit_move |= BMASK;
	return (bit_move);
}
/*
int	move_dub(char *mov, t_moves *list, t_carray *sta, t_carray *stb)
{
	int	flag;
	int	last;

	if (list->len == 0)
		return (TRUE);
	flag = move_check(mov);
	last = move_check(list->moves[list->len - 1]);
	if ((flag == PBCK && sta->len == 0) || (flag == PACK && stb->len == 0))
		return (FALSE);
	if (flag == SACK && last == SACK)
		return (FALSE);
	if (flag == SBCK && last == SBCK)
		return (FALSE);
	if ((flag == RBCK && last == RRBCK) || (last == RBCK && flag == RBCK))
		return (FALSE);
	if ((flag == RACK && last == RRACK) || (last == RACK && flag == RRACK))
		return (FALSE);
	if ((flag == PBCK && last == PACK) || (flag == PACK && last == PBCK))
		return (FALSE);
	return (TRUE);
}*/

int	move_dub(int mov, t_moves *list, t_carray *sta, t_carray *stb)
{
	int	flag;
	int	last;

	if (list->len == 0)
		return (TRUE);
	flag = mov;
	last = move_check(list->moves[list->len - 1]);
	if ((flag == PB && sta->len == 0) || (flag == PA && stb->len == 0))
		return (FALSE);
	if (flag == SA && last == SACK)
		return (FALSE);
	if (flag == SB && last == SBCK)
		return (FALSE);
	if ((flag == RB && last == RRBCK) || (last == RBCK && flag == RB))
		return (FALSE);
	if ((flag == RA && last == RRACK) || (last == RACK && flag == RRA))
		return (FALSE);
	if ((flag == PB && last == PACK) || (flag == PA && last == PBCK))
		return (FALSE);
	return (TRUE);
}

int	move_limit(t_moves *list, t_carray *sta)
{
	int	flag;
	int ctrl;
	int	idx;
	int	keep;

	if (list->len == 0)
		return (FALSE);
	idx = list->len - 1;
	ctrl = 0;
	flag = move_check(list->moves[idx]);
	keep = flag;
	while (flag == keep)
	{
		idx--;
		ctrl++;
		if (idx < 0)
			return (FALSE);
		flag = move_check(list->moves[idx]);
		if (ctrl > sta->max / 3 || ctrl > sta->len / 3)
			return (TRUE);
	}
	return (FALSE);
}

void	move_return(t_moves *list, t_carray *sta, t_carray *stb)
{
	int	flag;

	if (list->len == 0)
		return ;
	flag = move_check(list->moves[list->len - 1]);
	if (flag == SACK || flag == SSCK)
		swap_a(sta, stb);
	if (flag == SBCK || flag == SSCK)
		swap_b(sta, stb);
	if (flag == PACK)
		push_b(sta, stb);
	if (flag == PBCK)
		push_a(sta, stb);
	if (flag == RACK || flag == RRCK)
		rev_rotate_a(sta, stb);
	if (flag == RBCK || flag == RRCK)
		rev_rotate_b(sta, stb);
	if (flag == RRACK || flag == RRRCK)
		rotate_a(sta, stb);
	if (flag == RRBCK || flag == RRRCK)
		rotate_b(sta, stb);
	list->len--;
}

