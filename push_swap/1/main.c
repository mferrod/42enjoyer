/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:19:23 by marianof          #+#    #+#             */
/*   Updated: 2024/06/27 18:52:50 by marianof         ###   ########.fr       */
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
	if (!check_if_sorted(&a))
	{
		if (stack_len(&a) == 2)
			sa(&a);
		else if (stack_len(&a) == 3)
			sort_3_stack(&a);
		else
			printf("alGorimo shaval");
	}
	free_stacks(&a, &b);
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
	i = 0;
	j = 0;
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

long	*parser(int total_numb, char **data)
{
	long	*arrnum;
	int		i;
	int		j;

	i = 1;
	j = 0;
	arrnum = malloc((total_numb) * sizeof(long *));
	if (total_numb < 2)
		error();
	while (data[i])
	{
		arrnum[j] = check_string(data[i]);
		i++;
		j++;
	}
	arrnum = check_if_duplicated(arrnum);
	if (!arrnum)
		error_and_free(arrnum);
	return (arrnum);
}
