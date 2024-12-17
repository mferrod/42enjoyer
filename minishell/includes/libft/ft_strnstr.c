/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:57:27 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/01/10 12:47:16 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)(haystack));
	while (i < len && haystack[i])
	{
		while (haystack[i + j] == needle[j] && i + j < len
			&& haystack[i + j] && needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)(&haystack[i]));
		j = 0;
		i++;
	}
	return (NULL);
}
/* 
int	main(void)
{
	char str[50] = "cadena de caracteres";
	char find[10] = "de ";

	printf("%s\n", ft_strnstr(str, find, 1));
	printf("%s\n", strnstr(str, find, 1));

	return (0);
} */