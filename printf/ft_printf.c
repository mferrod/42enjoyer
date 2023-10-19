/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:24:30 by marianof          #+#    #+#             */
/*   Updated: 2023/10/19 16:05:19 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_switch(va_list element, const char *src)
{
	int	i;

	i = 0;
	while(src[i])
	{
		if (src[i] == '%')
		{
			if (src[i + 1] == 'c')
				
		}	
	}
}

int	ft_printf(char const *src, ...)
{
	va_list		element;
	int		return_value;

	if (!src)
		return (-1);
	return_value = 0;
	va_start(element, src);
	return_value = print_switch(element);
	va_end(element);
	return (return_value);
}

