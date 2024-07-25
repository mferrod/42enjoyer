/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:38:09 by marianof          #+#    #+#             */
/*   Updated: 2024/07/25 18:56:32 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_mov(t_node **stack_a, t_node **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rrr_mov(t_node **stack_a, t_node **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	ra_mov(t_node **stack_a, int *cost_of_a)
{
	while ((*cost_of_a) > 0)
	{
		ra(stack_a);
		(*cost_of_a)--;
	}
}

void	rb_mov(t_node **stack_b, int *cost_of_b)
{
	while ((*cost_of_b) > 0)
	{
		rb(stack_b);
		(*cost_of_b)--;
	}
}

void	rra_mov(t_node **stack_a, int *cost_of_a)
{
	while ((*cost_of_a) < 0)
	{
		rrb(stack_a);
		(*cost_of_a)++;
	}
}
