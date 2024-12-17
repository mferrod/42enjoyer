/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:06:18 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/01/09 17:48:01 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = ft_strlen(dst);
	j = 0;
	size = ft_strlen(src) + dstsize;
	if (ft_strlen(dst) >= dstsize)
		return (size);
	if (dstsize > 0 && dst[i] == '\0')
	{
		while (src[j] != 0 && i + 1 < dstsize)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	size = ft_strlen(dst) + ft_strlen(&src[j]);
	return (size);
}
/* 
int	main(void)
{
	char dest[12] = "hola ";
	char dest2[12] = "hola ";
	char src[12] = "mundo";

	printf("%zu\n", ft_strlcat(dest, src, 7));
	printf("%zu\n", strlcat(dest2, src, 7));
	printf("%s\n", dest);
	printf("%s\n", dest2);
	return (0);
} */