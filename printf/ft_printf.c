/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:24:30 by marianof          #+#    #+#             */
/*   Updated: 2023/10/27 14:23:49 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_switch(va_list element, const char *src, int i)
{
	int	r;

	r = 0;
	if (src[i] == 'c')
		r += ft_putchar_p(va_arg(element, int));
	if (src[i] == 's')
		r += ft_putstr_p(va_arg(element, char *));
	if (src[i] == 'p')
		r += ft_putp_p(va_arg(element, unsigned long));
	if (src[i] == 'd')
		r += ft_putnbr_p(va_arg(element, int));
	if (src[i] == 'i')
		r += ft_putnbr_p(va_arg(element, int));
	if (src[i] == 'u')
		r += ft_putnbr_un_p(va_arg(element, unsigned int));
	if (src[i] == 'x')
		r += ft_puthexmin_p(va_arg(element, unsigned long));
	if (src[i] == 'X')
		r += ft_puthexmay_p(va_arg(element, unsigned long));
	if (src[i] == '%')
		r += ft_putchar_p('%');
	return (r);
}

int	ft_printf(char const *src, ...)
{
	int		return_value;
	va_list	element;
	int		i;

	if (write(1, "", 0) == -1)
		return (-1);
	return_value = 0;
	i = 0;
	va_start(element, src);
	while (src[i])
	{
		if (src[i] == '%')
		{
			i++;
			return_value += print_switch(element, src, i);
		}
		else
			return_value += ft_putchar_p(src[i]);
		i++;
	}
	va_end(element);
	return (return_value);
}
