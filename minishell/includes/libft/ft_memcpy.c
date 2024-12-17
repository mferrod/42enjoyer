/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:56:32 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/03/25 22:58:22 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0 && !dst && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/* 
int	main(void)
{
	char src[20] = "unodostres";
	char dst[20] = "asdfasdf";
	char dst2[20] = "asdfasdf";
	printf("%s\n", ft_memcpy(dst, src, 4));
	printf("%s\n", memcpy(dst2, src, 4));
} */