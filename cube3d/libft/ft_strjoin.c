/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:18:20 by marianof          #+#    #+#             */
/*   Updated: 2023/10/02 13:10:58 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	fullenght;
	char	*s3;

	fullenght = (size_t)ft_strlen(s1) + (size_t)ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (fullenght + 1));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, s2, (ft_strlen(s3) + ft_strlen(s2)) + 1);
	return (s3);
}
