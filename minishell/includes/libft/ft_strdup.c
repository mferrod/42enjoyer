/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:18:46 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/04/22 15:22:03 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_memcpy(ret, s1, len);
	ret[len] = '\0';
	return (ret);
}
