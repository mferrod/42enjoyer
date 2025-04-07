/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:24:57 by marianof          #+#    #+#             */
/*   Updated: 2023/09/25 10:47:05 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			*ptrdst;
	char			*ptrsrc;

	i = 0;
	ptrdst = (char *)dst;
	ptrsrc = (char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (ptrdst > ptrsrc)
		while (len-- > 0)
			ptrdst[len] = ptrsrc[len];
	else
	{
		while (i < len)
		{
			ptrdst[i] = ptrsrc[i];
			i++;
		}
	}
	return (dst);
}
