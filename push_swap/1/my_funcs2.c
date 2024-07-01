/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:36:26 by marianof          #+#    #+#             */
/*   Updated: 2024/07/01 18:16:49 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index_to_stack(t_node *stack_a, int length)
{
	t_node	*my_stack;
	t_node	*top;
	int		value;

	while (--length > 0)
	{
		my_stack = stack_a;
		value = INT_MIN;
		top = NULL;
		while (my_stack)
		{
			if (my_stack->n == value && my_stack->index == 0)
				my_stack->index = 1;
			if (my_stack->n > value && my_stack->index == 0)
			{
				value = my_stack->n;
				top = my_stack;
				my_stack = stack_a;
			}
			else
				my_stack = my_stack->next;
		}
		if (top != NULL)
			top->index = length;
	}
}

void	sort_big_stack(t_node **stack_a, t_node **stack_b)
{
	save_and_push_3(stack_a, stack_b);
	sort_3_stack(stack_a);
}

void	save_and_push_3(t_node **stack_a, t_node **stack_b)
{
	int	s_len;
	int	i;

	s_len = stack_len(stack_a) - 3;
	i = 0;
	while (i < s_len)
	{
		push_b(stack_a, stack_b);
		i++;
	}
	if (stack_len(stack_a) < 3 && stack_len(stack_b) > 3)
		push_a(stack_a, stack_b);
}
