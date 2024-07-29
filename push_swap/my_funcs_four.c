/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:56:48 by marianof          #+#    #+#             */
/*   Updated: 2024/07/29 17:37:25 by marianof         ###   ########.fr       */
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
	t_node	*aux_b;
	int		size_a;
	int		size_b;

	aux_b = *stack_b;
	size_a = stack_len(stack_a);
	size_b = stack_len(stack_b);
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

void	get_the_lowest_cost(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux;
	t_node	*low_node;
	int		cost;
	int		my_low_num;

	cost = 0;
	my_low_num = -1;
	aux = *stack_b;
	while (aux)
	{
		cost = absolute_cost(aux->cost_a, aux->cost_b);
		if (my_low_num == -1 || cost < my_low_num)
		{
			my_low_num = cost;
			low_node = aux;
		}
		aux = aux->next;
	}
	make_moves(stack_a, stack_b, low_node);
}

int	absolute_cost(int a, int b)
{
	int	cost;

	if (a == 0 && b == 0)
		return (0);
	if (a < 0)
		cost = a * -1;
	else
		cost = a;
	if (b < 0)
		cost = cost + (b * -1);
	else
		cost = cost + b;
	return (cost);
}

void	make_moves(t_node **stack_a, t_node **stack_b, t_node *low_node)
{
	int	cost_of_a;
	int	cost_of_b;

	cost_of_a = low_node->cost_a;
	cost_of_b = low_node->cost_b;
	if (cost_of_a > 0 && cost_of_b > 0)
		rr_mov(stack_a, stack_b, &cost_of_a, &cost_of_b);
	else if (cost_of_a < 0 && cost_of_b < 0)
		rrr_mov(stack_a, stack_b, &cost_of_a, &cost_of_b);
	while (cost_of_a != 0 || cost_of_b != 0)
	{
		ra_mov(stack_a, &cost_of_a);
		rb_mov(stack_b, &cost_of_b);
		rra_mov(stack_a, &cost_of_a);
		rrb_mov(stack_b, &cost_of_b);
	}
	push_a(stack_a, stack_b);
}
