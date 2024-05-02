/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianonof@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:15:44 by marianof          #+#    #+#             */
/*   Updated: 2024/04/29 13:53:32 by marianof         ###   ########.fr       */
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
	if (((*sortme)->n > (*sortme)->next->n)
		&& ((*sortme)->next->n < (*sortme)->next->next->n)
		&& (*sortme)->n > (*sortme)->next->next->n)
		ra(sortme);
	else if (((*sortme)->n < (*sortme)->next->n)
		&& ((*sortme)->next->n > (*sortme)->next->next->n)
		&& (*sortme)->n < (*sortme)->next->next->n)
	{
		sa(sortme);
		ra(sortme);
	}
	else if (((*sortme)->n > (*sortme)->next->n)
		&& ((*sortme)->next->n < (*sortme)->next->next->n)
		&& (*sortme)->n < (*sortme)->next->next->n)
		sa(sortme);
	else if (((*sortme)->n < (*sortme)->next->n)
		&& ((*sortme)->next->n > (*sortme)->next->next->n)
		&& (*sortme)->n > (*sortme)->next->next->n)
		rra(sortme);
	else if (((*sortme)->n > (*sortme)->next->n)
		&& ((*sortme)->next->n > (*sortme)->next->next->n))
	{
		sa(sortme);
		rra(sortme);
	}
}
