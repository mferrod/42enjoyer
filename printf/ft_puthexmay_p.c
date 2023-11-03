/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexmay_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:04:20 by marianof          #+#    #+#             */
/*   Updated: 2023/11/03 13:34:41 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_gethex(int num)
{
	char	*k;

	k = "0123456789ABCDEF";
	return ((int)k[num]);
}

static void	ft_puthexmay_f(unsigned int n, int *c)
{
	if (n >= 16)
	{
		ft_puthexmay_f((n / 16), c);
		ft_puthexmay_f((n % 16), c);
	}
	else if (ft_gethex(n) >= 0 && ft_gethex(n) <= 9)
		*c += ft_putchar_p(ft_gethex(n) + '0');
	else
		*c += ft_putchar_p(ft_gethex(n));
}

int	ft_puthexmay_p(unsigned int n)
{
	int	i;

	i = 0;
	ft_puthexmay_f(n, &i);
	return (i);
}
