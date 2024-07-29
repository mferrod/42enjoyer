/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:36:26 by marianof          #+#    #+#             */
/*   Updated: 2024/07/29 17:52:08 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stacks(t_node *stack_a, t_node *stack_b)
{
	printf("STACK_A\n");
	printf("NUM	INDEX	POS	TARGET\n");
	while (stack_a)
	{
		printf("%d	%d	%d\n", stack_a->n, stack_a->index, stack_a->pos);
		stack_a = stack_a->next;
	}
	printf("STACK_B\n");
	printf("NUM	INDEX	POS	TARGET\n");
	while (stack_b)
	{
		printf("%d	%d	%d	%d\n", stack_b->n, stack_b->index, stack_b->pos,
			stack_b->target_node->pos);
		stack_b = stack_b->next;
	}
}

void	sort_big_stack(t_node **stack_a, t_node **stack_b)
{
	assing_index(stack_a);
	save_and_push_3(stack_a, stack_b);
	sort_3_stack(stack_a);
	cal_costs(stack_a, stack_b);
}

void	save_and_push_3(t_node **stack_a, t_node **stack_b)
{
	int	length;
	int	i;

	length = stack_len(stack_a);
	i = 0;
	while (stack_len(stack_a) > 3 && i < length / 2)
	{
		if ((*stack_a)->index <= length / 2)
		{
			push_b(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	while (stack_len(stack_a) > 3)
		push_b(stack_a, stack_b);
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
	int	check;

	while (*stack_b)
	{
		set_positions(stack_a);
		set_positions(stack_b);
		get_target(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		get_the_lowest_cost(stack_a, stack_b);
	}
	check = ft_lowest_to_top(stack_a);
	while ((*stack_a)->index != 1)
	{
		if (check == 1)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
