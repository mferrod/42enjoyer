/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:45:53 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/04/22 16:47:21 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && c != str[i])
		i++;
	return (c == str[i]);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	beg;
	int	end;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	beg = 0;
	end = 0;
	while (s1[end])
		end++;
	while (s1[beg] && contains(set, s1[beg]))
		beg++;
	if (beg == end)
		return (ft_strdup(""));
	while (contains(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, beg, end - beg));
}
