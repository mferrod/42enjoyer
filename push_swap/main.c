/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:19:23 by marianof          #+#    #+#             */
/*   Updated: 2024/02/08 13:26:33 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc < 2)
		return (-1);
	while (argv[i])
	{
		if (i == 0)
			i++;
		printf ("%i\n", check(argv[i]));
		i++;
	}
	return (0);
}

int	check(char *c)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (c[i] != '\0')
	{
		if (!(c[i] >= 48 && c[i] <= 57))
			return (-1);
		i++;
	}
	num = ft_atoi(c);
	if (num <= 0)
		return (-1);
	return (num);
}
