/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:00:36 by buehara           #+#    #+#             */
/*   Updated: 2025/11/19 18:27:21 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_atoi_util(long int number, char **list, int *arg)
{
	if (number > MAX_INT || number < MIN_INT)
	{
		ft_str_free(list);
		ft_error(arg, NULL, 1);
	}
}

int	ft_atoi_push(const char *nptr, char **list, int *arg)
{
	int			signal;
	long int	number;

	number = 0;
	signal = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal = -1;
		nptr++;
	}
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
		{
			number = number * 10 + (*nptr - '0');
			ft_atoi_util(number * signal, list, arg);
			nptr++;
		}
		if (!(*nptr >= '0' && *nptr <= '9'))
			return (number * signal);
	}
	return (0);
}
