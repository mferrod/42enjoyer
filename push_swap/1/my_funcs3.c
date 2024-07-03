/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariano <mariano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:18:22 by marianof          #+#    #+#             */
/*   Updated: 2024/07/03 17:39:13 by mariano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_node **stack)
{
	int		i;
	t_node	*aux;

	if (!stack || !*stack)
		error();
	i = 0;
	aux = *stack;
	while ((aux)->next != NULL)
	{
		(aux)->pos = i;
		(aux) = (aux)->next;
		i++;
	}
	(aux)->pos = i;
}

void	get_target(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		target;
	int		size;
	int		num;
	t_node	*aux;

	i = 0;
	aux = *stack_a;
	target = __INT_MAX__;
	size = stack_len(stack_a);
	num = 0;
	while (i <= size)
	{
		num = aux->n - (*stack_b)->n;
		if ((num < target) && ((aux)->n > (*stack_b)->n))
		{
			target = num;
			(*stack_b)->target_node = (aux);
		}
		i++;
		(aux) = (aux)->next;
	}
}

int	top_calc(t_node **stack)
{
	int	num;
	int	i;

	num = stack_len(stack) - (*stack)->pos;
	i = 0;
	if (num + 1 > (*stack)->pos)
		i = (*stack)->pos;
	else
		i = num * -1;
	return (i);
}

void	calc_total_cost(t_node **stack)
{
	int	num_target;
	int	num_stack;

	num_target = (*stack)->cost_target;
	num_stack = (*stack)->cost;
	if (num_target < 0)
		num_target = -num_target;
	if (num_stack < 0)
		num_stack = -num_stack;
	(*stack)->total_cost = num_target + num_stack;
}
