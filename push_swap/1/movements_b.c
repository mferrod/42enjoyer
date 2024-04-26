/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:18:52 by marianof          #+#    #+#             */
/*   Updated: 2024/04/25 19:24:57 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **node)
{
	int	aux;

	if (!node || !(*node) || !(*node)->next)
		return ;
	aux = (*node)->n;
	(*node)->n = (*node)->next->n;
	(*node)->next->n = aux;
}

void	rb(t_node **node)
{
	if (!*node || !(*node)->next)
		return ;
	(*node) = (*node)->next;
}

void	rrb(t_node **node)
{
	t_node	*n;

	n = (*node);
	if (!*node || !(*node)->next)
		return ;
	while ((*node)->next != NULL)
		(*node) = (*node)->next;
	(*node) = n;
}

void	push_b(t_node **node_a, t_node **node_b)
{
	t_node	*aux;

	aux = (*node_a)->next;
	(*node_a)->next = NULL;
	if (!(*node_b))
		(*node_b) = (*node_a);
	else
		(*node_a)->next = (*node_b);
	(*node_b) = (*node_a);
	(*node_a) = aux;
}
