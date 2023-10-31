/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexmin_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:38:11 by marianof          #+#    #+#             */
/*   Updated: 2023/10/31 12:10:37 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_gethex(int num)
{
	char	*k;

	k = "0123456789abcdef";
	return ((int)k[num]);
}

static void	ft_puthexmin_f(unsigned long n, int *c)
{
	if (n >= 16)
	{
		ft_puthexmin_f((n / 16), c);
		ft_puthexmin_f((n % 16), c);
	}
	else if (ft_gethex(n) >= 0 && ft_gethex(n) <= 9)
		*c += ft_putchar_p(ft_gethex(n) + '0');
	else
		*c += ft_putchar_p(ft_gethex(n));
}

int	ft_puthexmin_p(unsigned long n)
{
	int	i;

	i = 0;
	ft_puthexmin_f(n, &i);
	return (i);
}
