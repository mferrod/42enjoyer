/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:15:45 by marianof          #+#    #+#             */
/*   Updated: 2023/10/20 11:05:57 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_p(int n)
{
	int	i;

	i = 1;
	if (n <= -2147483648)
		ft_putstr_p("-2147483648");
	else if (n >= 2147483647)
		ft_putstr_p("2147483647");
	else
	{
		if (n < 0)
		{
			ft_putchar_p('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_p((n / 10));
			ft_putnbr_p((n % 10));
		}
		else
			ft_putchar_p(n + '0');
	}
	return (i);
}
