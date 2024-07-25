/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariano <mariano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:56:48 by marianof          #+#    #+#             */
/*   Updated: 2024/07/24 16:50:44 by mariano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_smallest(t_node **stack)
{
	t_node	*aux;
	t_node	*lowest;

	aux = *stack;
	lowest = *stack;
	while (aux)
	{
		if (aux->n < lowest->n)
			lowest = aux;
		aux = aux->next;
	}
	return (lowest);
}

void	get_cost(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux_a;
	t_node	*aux_b;
	int		size_a;
	int		size_b;

	aux_a = *stack_a;
	aux_b = *stack_b;
	size_a = stack_len(*stack_a);
	size_b = stack_len(*stack_b);
	while (aux_b)
	{
		if (aux_b->pos <= size_b / 2)
			aux_b->cost_b = aux_b->pos;
		else
			aux_b->cost_b = (size_b - aux_b->pos) * -1;
		if (aux_b->target_node->pos <= size_a / 2)
			aux_b->cost_a = aux_b->target_node->pos;
		else
			aux_b->cost_a = (size_a - aux_b->target_node->pos) * -1;
		aux_b = aux_b->next;
	}
}
