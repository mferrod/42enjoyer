/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:51:50 by marianof          #+#    #+#             */
/*   Updated: 2024/06/25 19:39:15 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **node_a, t_node **node_b)
{
	t_node	*aux;
	t_node	*new;

	if (node_a != NULL && node_b != NULL)
	{
		new = *node_a;
		aux = *node_b;
		*node_a = (*node_a)->next;
		new->next = aux;
		*node_b = new;
	}
}

void	push_a(t_node **node_a, t_node **node_b)
{
	push(node_b, node_a);
	ft_putstr_fd("push_a\n", 1);
}

void	push_b(t_node **node_a, t_node **node_b)
{
	push(node_a, node_b);
	ft_putstr_fd("push_b\n", 1);
}
