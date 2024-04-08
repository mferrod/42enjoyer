/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:50:17 by marianof          #+#    #+#             */
/*   Updated: 2023/10/04 11:07:58 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*save;
	char	*str;

	i = 0;
	str = (char *)s;
	save = (char *)malloc(sizeof(char) * ((size_t)ft_strlen(s) + 1));
	if (!save)
		return (NULL);
	while (s[i])
	{
		save[i] = (*f)(i, str[i]);
		i++;
	}
	save[i] = '\0';
	return (save);
}
