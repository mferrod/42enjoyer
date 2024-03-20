/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:19:23 by marianof          #+#    #+#             */
/*   Updated: 2024/03/20 20:01:11 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(char *argv[], int argc)
{
	int	i;
	int	arrnum[argc - 1];

	i = 1;
	if (argc < 2)
		return (-1);
	while (argv[i])
	{
		printf ("%i\n", check_string(argv[i]));
		arrnum[i] = ft_atoi(argv[i]);
		i++;
	}
	return (0);
}

int	check_string(char *c)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (c[i] != '\0')
	{
		if (check_char(c[i], i) == 0)
			return (-1);
		i++;
	}
	num = ft_atoi(c);
	if (num < INT_MIN || num > INT_MAX)
		return (-1);
	return (num);
}

int	check_char(char c, int i)
{
	if (c == 45 && i == 0)
		return (1);
	if (c > 48 && c < 57)
		return (1);
	else
		return (0);
}
