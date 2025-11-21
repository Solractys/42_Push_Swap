/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:01:23 by buehara           #+#    #+#             */
/*   Updated: 2025/08/05 18:28:10 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ctrl;
	size_t	ctrl_src;
	size_t	index;
	size_t	index_src;

	ctrl = 0;
	ctrl_src = 0;
	index_src = ft_strlen(src);
	index = ft_strlen(dst);
	if (size > 0)
	{
		ctrl = index;
		if (ctrl + 1 > size)
			return (index_src + size);
		size -= (ctrl + 1);
		while (src[ctrl_src] != '\0' && size)
		{
			dst[ctrl++] = src[ctrl_src++];
			size--;
		}
		dst[ctrl] = '\0';
		return (index + index_src);
	}
	return (index_src);
}
