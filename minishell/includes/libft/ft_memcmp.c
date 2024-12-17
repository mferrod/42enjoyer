/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:28:00 by ijerruz-          #+#    #+#             */
/*   Updated: 2023/11/30 14:19:20 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return ((int)((unsigned char *)s1)[i]
		- (int)((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/* 
int	main(void)
{
	char str1[5] = "holea";
	char str2[5] = "hol";
	printf("%d\n", ft_memcmp(&str1, &str2, 4));
	printf("%d\n", memcmp(&str1, &str2, 4));
} */