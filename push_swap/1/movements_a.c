/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:45:47 by marianof          #+#    #+#             */
/*   Updated: 2024/06/24 15:43:39 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **node)
{
	int	aux;

	if (!node || !(*node)->next || !(*node))
		return ;
	aux = (*node)->n;
	(*node)->n = (*node)->next->n;
	(*node)->next->n = aux;
	printf("sa\n");
}

void	ra(t_node **node)
{
	if (!*node || !(*node)->next)
		return ;
	(*node) = (*node)->next;
	printf("ra\n");
}

void	rra(t_node **node)
{
	t_node	*n;

	n = (*node);
	if (!*node || !(*node)->next)
		return ;
	while ((*node)->next != NULL)
		(*node) = (*node)->next;
	(*node) = n;
	printf("rra\n");
}

void	push_a(t_node **node_a, t_node **node_b)
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
	printf("push_a\n");
}
