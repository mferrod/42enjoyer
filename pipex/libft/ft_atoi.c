/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:26:35 by marianof          #+#    #+#             */
/*   Updated: 2023/09/29 11:10:07 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	returned;
	int	rest;

	i = 0;
	returned = 0;
	rest = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			rest = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		returned = (returned * 10) + (str[i] - '0');
		i++;
	}
	return (returned * rest);
}
