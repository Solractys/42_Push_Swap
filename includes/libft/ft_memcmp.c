/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:26:09 by buehara           #+#    #+#             */
/*   Updated: 2025/08/05 17:48:49 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					ctrl;
	unsigned const char		*str1;
	unsigned const char		*str2;

	if (n <= 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	ctrl = 0;
	while (ctrl <= n - 1)
	{
		if (str1[ctrl] != str2[ctrl])
			return ((int)str1[ctrl] - (int)str2[ctrl]);
		ctrl++;
	}
	return (0);
}
