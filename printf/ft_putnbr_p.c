/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:15:45 by marianof          #+#    #+#             */
/*   Updated: 2023/11/03 13:29:21 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_f(int n, int *c)
{
	if (n <= -2147483648)
		*c += ft_putstr_p("-2147483648");
	else if (n >= 2147483647)
		*c += ft_putstr_p("2147483647");
	else
	{
		if (n < 0)
		{
			*c += ft_putchar_p('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_f((n / 10), c);
			ft_putnbr_f((n % 10), c);
		}
		else
			*c += ft_putchar_p(n + '0');
	}
}

int	ft_putnbr_p(int n)
{
	int	i;

	i = 0;
	ft_putnbr_f(n, &i);
	return (i);
}
