/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:19:16 by marianof          #+#    #+#             */
/*   Updated: 2023/10/17 10:02:38 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*c1;
	unsigned char		*c2;

	i = 0;
	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((unsigned char)c1[i] > (unsigned char)c2[i])
			return (c1[i] - c2[i]);
		if ((unsigned char)c1[i] < (unsigned char)c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}
