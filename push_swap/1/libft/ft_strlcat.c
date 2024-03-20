/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:57:07 by marianof          #+#    #+#             */
/*   Updated: 2023/09/27 13:33:50 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;
	size_t	returned;
	char	*s;

	i = 0;
	s = (char *)src;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(s);
	if (lendst >= dstsize)
		returned = dstsize + lensrc;
	else
		returned = lendst + lensrc;
	while (s[i] && (lendst + 1) < dstsize)
	{
		dst[lendst] = s[i];
		lendst++;
		i++;
	}
	dst[lendst] = '\0';
	return (returned);
}
