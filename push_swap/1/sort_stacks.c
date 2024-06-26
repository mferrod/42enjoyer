/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:15:44 by marianof          #+#    #+#             */
/*   Updated: 2024/06/24 15:53:14 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_node **node)
{
	while ((*node)->next != NULL)
	{
		if ((*node)->n > (*node)->next->n)
			return (0);
		*node = (*node)->next;
	}
	return (1);
}

long	stack_avg(t_node **node)
{
	long	avg;
	t_node	*node2;

	avg = 0;
	node2 = (*node);
	while (node2->next != NULL)
	{
		avg += node2->n;
		node2 = node2->next;
	}
	avg += node2->n;
	avg = avg / (long)stack_len((node));
	return (avg);
}

void	act_with_avg(t_node **node_a, t_node **node_b, long avg)
{
	if ((*node_a)->n <= avg)
		push_b(node_a, node_b);
	else
		ra(node_a);
}

void	sort_3_stack(t_node **sortme)
{
	int		top;

	if (is_sorted(*stack))
		return ;
	top = find_top_index(*stack);
	if ((*stack)->index == top)
		ra(stack);
	else if ((*stack)->next->index == top)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

int	find_top_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}
