/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrd_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:19:08 by marianof          #+#    #+#             */
/*   Updated: 2023/10/23 13:22:54 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrd_p(int n)
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
