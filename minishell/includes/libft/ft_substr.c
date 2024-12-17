/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:05:30 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/04/23 12:39:13 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (0);
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - (start);
	if (ft_strlen(s) == 0 || len == 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ft_memcpy(ret, &s[start], len);
	ret[len] = 0;
	return (ret);
}
