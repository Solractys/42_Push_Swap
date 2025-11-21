/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:23:04 by buehara           #+#    #+#             */
/*   Updated: 2025/08/05 16:17:11 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned int	ctrl;

	ptr = (unsigned char *)s;
	ctrl = 0;
	while (ctrl < n)
	{
		ptr[ctrl] = '\0';
		ctrl++;
	}
}
