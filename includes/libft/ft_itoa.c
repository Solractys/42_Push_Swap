/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:59:31 by buehara           #+#    #+#             */
/*   Updated: 2025/08/05 17:45:31 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits_count(int n)
{
	int		count;
	int		signal;
	long	copy;

	count = 0;
	copy = n;
	if (copy > 0)
		signal = 1;
	else if (copy < 0)
	{
		signal = -1;
		count++;
	}
	else
		return (1);
	copy = copy * signal;
	while (copy >= 10)
	{
		copy = copy / 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*digit;
	int		count;
	long	copy;

	copy = n;
	count = ft_digits_count(copy);
	if (n == 0)
		return (ft_strdup("0"));
	digit = malloc(count + 1 * sizeof(char));
	if (!digit)
		return (NULL);
	if (copy < 0)
		copy *= -1;
	digit[count] = '\0';
	while (count-- > 0)
	{
		digit[count] = copy % 10 + '0';
		copy = copy / 10;
	}
	if (n < 0)
		digit[0] = '-';
	return (digit);
}
