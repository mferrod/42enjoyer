/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:24:30 by marianof          #+#    #+#             */
/*   Updated: 2023/10/23 13:18:43 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_switch(va_list element, const char *src, int i)
{
	int	r;

	r = 0;
	if (src[i + 1] == 'c')
		r = ft_putchar_p(va_arg(element, int));
	if (src[i + 1] == 's')
		r = ft_putstr_p(va_arg(element, char *));
	if (src[i + 1] == 'p')
		r = 0;
	if (src[i + 1] == 'd')
		ft_putnbrd_p(va_arg(element, int));
	if (src[i + 1] == 'i')
		ft_putnbr_p(va_arg(element, double));
	if (src[i + 1] == 'u')
		r = 0;
	if (src[i + 1] == 'x')
		r = 0;
	if (src[i + 1] == 'X')
		r = 0;
	return (r);
}

int	ft_printf(char const *src, ...)
{
	int		return_value;
	va_list	element;
	int		i;

	if (!src)
		return (-1);
	return_value = 0;
	i = 0;
	va_start(element, src);
	while (src[i])
	{
		if (src[i] == '%')
		{
			if (src[i + 1] == '%')
			{
				return_value += ft_putchar_p('%');
			}
			else
				return_value += print_switch(element, src, i);
			i--;
		}
		i++;
	}
	va_end(element);
	return (return_value);
}
