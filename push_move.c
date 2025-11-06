/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:15:19 by buehara           #+#    #+#             */
/*   Updated: 2025/11/05 20:20:07 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_check(char *mov)
{
	int	bit_move;

	if (!mov)
		return ;
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
