/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:00:36 by buehara           #+#    #+#             */
/*   Updated: 2025/11/17 15:38:46 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_atoi_util(int number, char **list, int *arg)
{
	if (number > 1000000000)
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
			ft_atoi_util(number, list, arg);
			number = number * 10 + (*nptr - '0');
			nptr++;
		}
		if (!(*nptr >= '0' && *nptr <= '9'))
			return (number * signal);
	}
	return (0);
}
