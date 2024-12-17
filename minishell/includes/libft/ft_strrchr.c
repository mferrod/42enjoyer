/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:46:45 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/01/21 21:57:02 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = ft_strlen(s);
	ptr = (char *)s;
	if ((unsigned char)c == 0)
		return (&ptr[i]);
	i--;
	while (i >= 0)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i--;
	}
	return (NULL);
}

/* 
int	main(void)
{
	printf("%s\n", ft_strrchr("teste", 'x'));
	printf("%s\n", strrchr("teste", 'x'));
	return (0);
} */