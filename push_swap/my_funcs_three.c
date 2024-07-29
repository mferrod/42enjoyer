/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:18:22 by marianof          #+#    #+#             */
/*   Updated: 2024/07/25 18:59:08 by marianof         ###   ########.fr       */
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
	t_node	*aux;
	t_node	*current;
	t_node	*target;

	aux = *stack_b;
	while (aux)
	{
		current = *stack_a;
		target = NULL;
		while (current)
		{
			if (current->n > aux->n
				&& (target == NULL || current->n < target->n))
				target = current;
			current = current->next;
		}
		if (target == NULL)
			target = find_smallest(stack_a);
		aux->target_node = target;
		aux = aux->next;
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

void	assing_index(t_node **stack)
{
	t_node	*tmp;
	t_node	*aux;
	int		i;

	i = 1;
	aux = *stack;
	while (aux)
	{
		tmp = *stack;
		while (tmp)
		{
			if (aux->n > tmp->n)
				i++;
			tmp = tmp->next;
		}
		aux->index = i;
		i = 1;
		aux = aux->next;
	}
}
