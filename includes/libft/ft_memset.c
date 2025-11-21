/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:02:56 by buehara           #+#    #+#             */
/*   Updated: 2025/08/05 17:54:43 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	ctrl;
	unsigned char	*str;

	ctrl = 0;
	str = s;
	while (ctrl < n)
	{
		str[ctrl] = c;
		ctrl++;
	}
	return (s);
}
