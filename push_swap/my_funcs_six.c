/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:49:25 by marianof          #+#    #+#             */
/*   Updated: 2024/07/29 15:42:28 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb_mov(t_node **stack_b, int *cost_of_b)
{
	while ((*cost_of_b) < 0)
	{
		rrb(stack_b);
		(*cost_of_b)++;
	}
}

int	ft_lowest_to_top(t_node **stack_a)
{
	t_node	*aux;
	int		position;

	aux = *stack_a;
	position = 1;
	while (aux->index != 1)
	{
		aux = aux->next;
		position++;
	}
	if (position < stack_len(stack_a) / 2)
		return (1);
	else
		return (0);
}
