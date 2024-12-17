/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:02:32 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/03/25 20:55:11 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	int		*ret;

	i = 0;
	ret = malloc(count * size);
	if (!ret)
		return (0);
	while (i < (count * size))
	{
		((char *)ret)[i] = 0;
		i++;
	}
	return (ret);
}
