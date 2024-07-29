/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:19:23 by marianof          #+#    #+#             */
/*   Updated: 2024/07/29 18:13:14 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	long	*arrnum;
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	arrnum = parser(argc - 1, argv);
	a = stack_gen(arrnum, argc - 1);
	free(arrnum);
	if (!check_if_sorted(&a))
	{
		if (stack_len(&a) == 1)
		{
			free_stacks(&a, &b);
			return (0);
		}
		if (stack_len(&a) == 2)
			sa(&a);
		else if (stack_len(&a) == 3)
			sort_3_stack(&a);
		else if (stack_len(&a) > 3)
			sort_big_stack(&a, &b);
	}
	free_stacks(&a, &b);
	return (0);
}

long	check_string(char *c)
{
	long	num;
	int		i;

	num <= 0;
	i = 0;
	if (!c[0])
		error();
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

void	check_if_duplicated(long *numbers, int len)
{
	int	founds;
	int	i;
	int	j;

	founds = 0;
	i = 0;
	j = 0;
	while (i < len)
	{
		while (j < len)
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
}

long	*parser(int total_numb, char **data)
{
	long	*arrnum;
	long	*aux;
	int		i;
	int		j;

	i = 1;
	j = 0;
	arrnum = malloc((total_numb) * sizeof(long *));
	if (!arrnum)
		error();
	if (total_numb < 1)
		error();
	while (data[i])
	{
		arrnum[j] = check_string(data[i]);
		i++;
		j++;
	}
	check_if_duplicated(arrnum, total_numb);
	return (arrnum);
}
