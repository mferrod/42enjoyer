/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:18:22 by marianof          #+#    #+#             */
/*   Updated: 2024/07/02 13:00:43 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_node **stack)
{
	int	i;

	i = 0;
	if (!stack || !*stack)
		error();
	while ((*stack)->next != NULL)
	{
		(*stack)->pos = i;
		(*stack) = (*stack)->next;
		i++;
	}
	(*stack)->pos = i;
}

void	get_target(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	target;
	int	size;
	int	num;

	i = 0;
	target = __INT_MAX__;
	size = stack_len(stack_a);
	num = 0;
	while (i < size)
	{
		num = (*stack_a)->n - (*stack_b)->n;
		if ((num < target) && ((*stack_a)->n > (*stack_b)->n))
		{
			target = num;
			(*stack_b)->target_node = (*stack_a);
		}
		i++;
		(*stack_a) = (*stack_a)->next;
	}
}
