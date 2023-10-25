/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:06:34 by marianof          #+#    #+#             */
/*   Updated: 2023/10/25 15:30:19 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_p(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_p(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static void	ft_putnbr_un_f(unsigned int n, unsigned int *c)
{
	if (n >= 2147483647)
		*c += (unsigned int)ft_putstr_p("2147483647");
	else
	{
		if (n >= 10)
		{
			ft_putnbr_un_f((n / 10), c);
			ft_putnbr_un_f((n % 10), c);
		}
		else
		{
			ft_putchar_p(n + '0');
			*c += 1;
		}
	}
}

unsigned int	ft_putnbr_un_p(unsigned int n)
{
	unsigned int	i;

	i = 0;
	ft_putnbr_un_f(n, &i);
	return (i);
}

int	main(void)
{
	printf("%i", ft_putnbr_un_p(8283));
}
