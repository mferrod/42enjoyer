/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 08:58:18 by marianof          #+#    #+#             */
/*   Updated: 2023/09/18 11:52:24 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dst, size_t n)
{
	size_t					i;
	unsigned char			*ptr;

	if (n > 0)
	{
		ptr = (unsigned char *)dst;
		i = 0;
		while (i < n)
		{
			ptr[i] = '\0';
			i++;
		}
	}
}
