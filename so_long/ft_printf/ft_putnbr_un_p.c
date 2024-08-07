/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:06:34 by marianof          #+#    #+#             */
/*   Updated: 2023/11/03 13:34:34 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_un_f(unsigned int n, int *c)
{
	if (n >= 10)
	{
		ft_putnbr_un_f((n / 10), c);
		ft_putnbr_un_f((n % 10), c);
	}
	else
		*c += ft_putchar_p(n + '0');
}

int	ft_putnbr_un_p(unsigned int n)
{
	int	i;

	i = 0;
	ft_putnbr_un_f(n, &i);
	return (i);
}
