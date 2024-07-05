/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:36:26 by marianof          #+#    #+#             */
/*   Updated: 2024/07/03 20:30:37 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_stack(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	length;

	i = 0;
	length = stack_len(stack_a);
	save_and_push_3(stack_a, stack_b);
	sort_3_stack(stack_a);
	while (i < length - 3)
	{
		cal_costs(stack_a, stack_b);
		i++;
	}
}

void	save_and_push_3(t_node **stack_a, t_node **stack_b)
{
	while (stack_len(stack_a) > 3)
	{
		if (stack_average(stack_a) <= (*stack_a)->n)
			push_b(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

int	stack_average(t_node **stack)
{
	int		avg;
	int		total_num;
	t_node	*stack_aux;

	if (!stack || !*stack)
		error();
	avg = 0;
	stack_aux = *stack;
	total_num = stack_len(stack);
	while (stack_aux->next != NULL)
	{
		avg += stack_aux->n;
		stack_aux = stack_aux->next;
	}
	avg += stack_aux->n;
	avg = avg / total_num;
	return (avg);
}

void	cal_costs(t_node **stack_a, t_node **stack_b)
{
	int i = 0;
	set_positions(stack_a);
	set_positions(stack_b);
	while ((*stack_b)->next != NULL)
	{
		get_target(stack_a, stack_b);
		(*stack_b)->cost_target = top_calc(&(*stack_b)->target_node);
		(*stack_b)->cost = top_calc(stack_b);
		(*stack_b) = (*stack_b)->next;
		printf("mi iteración nº %d", i++);
	}
	//printf("SALGO DEL BUCLE");
	//set_cheapest_node(stack_b);
}

void	set_cheapest_node(t_node **stack)
{
	int		cheapest;
	int		i;
	int		size;
	t_node	*aux;

	i = 0;
	cheapest = (*stack)->total_cost;
	aux = *(stack);
	aux->cheapest_r_node = (*stack);
	size = stack_len(stack);
	while (i < size)
	{
		if (cheapest > (aux)->total_cost)
		{
			cheapest = aux->total_cost;
			(*stack)->cheapest_r_node = aux;
		}
		aux = aux->next;
		i++;
	}
}
