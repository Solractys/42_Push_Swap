/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_parsing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:55:40 by buehara           #+#    #+#             */
/*   Updated: 2025/11/17 15:23:30 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_free(int *arg, t_carray *stack)
{
	if (arg)
		free(arg);
	if (stack)
		free(stack);
}

void	ft_error(void *arg, t_carray *stack, int check)
{
	ft_push_free(arg, stack);
	if (check)
		write(2, "Error\n", 6);
	exit(TRUE);
}

int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (TRUE);
	return (FALSE);
}

void	ft_str_free(char **list)
{
	int	i;

	if (!list)
		return ;
	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}
