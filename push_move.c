/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:15:19 by buehara           #+#    #+#             */
/*   Updated: 2025/11/07 19:12:23 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mfunc	func_list(int index)
{
	static t_mfunc	map[TOTALMOVES];

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
	else if (mov[1] == 'b' || mov[2] == 'b')
		bit_move |= BMASK;
	return (bit_move);
}

