/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:55:07 by marianof          #+#    #+#             */
/*   Updated: 2024/07/01 18:08:20 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int			i;
	long		returned;
	long		rest;

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
	if (INT_MAX < returned || INT_MIN > returned)
		error();
	return (returned * rest);
}

int	stack_len(t_node **node)
{
	int		i;
	t_node	*node2;

	i = 0;
	node2 = (*node);
	if (!node)
		error();
	while (node2 != NULL)
	{
		i++;
		node2 = node2->next;
	}
	return (i);
}

void	print_stack(t_node *list)
{
	while (list)
	{
		printf("%d\n", list->n);
		list = list->next;
	}
}

void	free_stack(t_node **stack)
{
	t_node	*stacktemp;

	if (!stack || !*stack)
		error();
	while ((*stack)->next != NULL)
	{
		stacktemp = (*stack)->next;
		free(*stack);
		*stack = stacktemp;
	}
	free(*stack);
	*stack = NULL;
	stacktemp = NULL;
}

void	free_stacks(t_node **stack_a, t_node **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}
