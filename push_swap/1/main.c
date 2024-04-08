/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:19:23 by marianof          #+#    #+#             */
/*   Updated: 2024/04/08 19:09:51 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	long	*arrnum;

	arrnum = malloc(sizeof(long *) * (argc));
	i = 1;
	if (argc < 2)
		error();
	while (argv[i])
	{
		arrnum[i] = check_string(argv[i]);
		i++;
	}
	arrnum = check_if_duplicated(arrnum);
	if (!arrnum)
		error_and_free(arrnum);
	stack_gen(arrnum, argc - 1);
	return (0);
}

long	check_string(char *c)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	while (c[i] != '\0')
	{
		if (check_char(c[i], i) == 0)
			error();
		i++;
	}
	num = ft_atol(c);
	return (num);
}

int	check_char(char c, int i)
{
	if (c == 45 && i == 0)
		return (1);
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

long	*check_if_duplicated(long *numbers)
{
	int	founds;
	int	i;
	int	j;

	founds = 0;
	i = 1;
	j = 1;
	while (numbers[i] != '\0')
	{
		while (numbers[j] != '\0')
		{
			if (numbers[i] == numbers[j])
				founds++;
			if (numbers[i] == numbers[j] && founds > 1)
				error_and_free(numbers);
			j++;
		}
		i++;
		founds = 0;
		j = 0;
	}
	return (numbers);
}
