/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:18:22 by marianof          #+#    #+#             */
/*   Updated: 2024/07/02 17:25:28 by marianof         ###   ########.fr       */
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
	int		i;
	int		target;
	int		size;
	int		num;
	t_node	*aux;

	i = 0;
	aux = *stack_a;
	target = __INT_MAX__;
	size = stack_len(stack_a);
	num = 0;
	while (i <= size)
	{
		num = aux->n - (*stack_b)->n;
		printf("NUM: %d\n", num);
		if ((num < target) && ((aux)->n > (*stack_b)->n))
		{
			target = num;
			(*stack_b)->target_node = (aux);
		}
		i++;
		(aux) = (aux)->next;
	}
}
