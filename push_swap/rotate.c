/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:36:27 by marianof          #+#    #+#             */
/*   Updated: 2024/06/25 18:51:07 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **node)
{
	t_node	*n;
	t_node	*aux;

	if (!*node || !(*node)->next)
		return ;
	n = (*node);
	aux = *node;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = n;
	*node = (*node)->next;
	n->next = NULL;
}

void	ra(t_node **node)
{
	rotate(node);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_node **node)
{
	rotate(node);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **node_a, t_node **node_b)
{
	rotate(node_a);
	rotate(node_b);
	ft_putstr_fd("rr\n", 1);
}
