/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:15:44 by marianof          #+#    #+#             */
/*   Updated: 2024/04/26 18:47:23 by marianof         ###   ########.fr       */
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

void	sort_3_stack(t_node **sortme)
{
	if (((*sortme)->n > (*sortme)->next->n)
		&& ((*sortme)->next->n < (*sortme)->next->next->n)
		&& ((*sortme)->next->next->n > (*sortme)->n))
		sa(sortme);
	else if (((*sortme)->n < (*sortme)->next->n)
		&& ((*sortme)->next->n > (*sortme)->next->next->n)
		&& ((*sortme)->next->next->n < (*sortme)->n))
		rra(sortme);
	else if (((*sortme)->n > (*sortme)->next->n)
		&& ((*sortme)->next->n < (*sortme)->next->next->n)
		&& ((*sortme)->next->next->n < (*sortme)->n))
	{
		ra(sortme);
		sa(sortme);
	}
	else if (((*sortme)->n > (*sortme)->next->n)
		&& ((*sortme)->next->n > (*sortme)->next->next->n)
		&& ((*sortme)->next->next->n < (*sortme)->n))
	{
		rra(sortme);
		sa(sortme);
	}
}
