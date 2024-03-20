/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:09:43 by marianof          #+#    #+#             */
/*   Updated: 2023/09/28 12:56:55 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*reserv;

	i = 0;
	len = ft_strlen(s1);
	reserv = (char *)malloc(sizeof(char) * (len + 1));
	if (reserv == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		reserv[i] = s1[i];
		i++;
	}
	reserv[i] = '\0';
	return (reserv);
}
