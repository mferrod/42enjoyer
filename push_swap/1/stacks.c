/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:30:00 by marianof          #+#    #+#             */
/*   Updated: 2024/04/08 19:16:41 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(long n)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->n = n;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node	*stack_gen(long *numbers, int numbers_count)
{
	t_node	*head;
	t_node	*aux;
	t_node	*node;
	int		i;

	i = 1;
	head = new_node(numbers[0]);
	aux = head;
	while (i < numbers_count)
	{
		node = new_node(numbers[i]);
		aux->next = node;
		node->prev = aux;
		aux = node;
		i++;
	}
	node->prev = NULL;
	return (head);
}
