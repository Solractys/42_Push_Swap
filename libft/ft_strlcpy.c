/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:51:13 by buehara           #+#    #+#             */
/*   Updated: 2025/08/05 20:34:10 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;
	int		ctrl;

	count = 0;
	ctrl = 0;
	while (src[ctrl] != '\0')
		ctrl++;
	if (size > 0)
	{
		while ((src[count] != '\0') && (count < size - sizeof(char)))
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	return (ctrl);
}
