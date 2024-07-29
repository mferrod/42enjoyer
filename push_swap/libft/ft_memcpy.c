/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:30:14 by marianof          #+#    #+#             */
/*   Updated: 2023/09/25 10:45:42 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrdst;
	char			*vsrc;

	i = 0;
	ptrdst = (unsigned char *)dst;
	vsrc = (char *)src;
	if (dst == 0 && src == 0)
		return (0);
	while (i < n)
	{
		ptrdst[i] = vsrc[i];
		i++;
	}
	return (dst);
}
