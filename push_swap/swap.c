/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:32:07 by marianof          #+#    #+#             */
/*   Updated: 2024/07/29 17:51:42 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **node)
{
	t_node	*aux;
	t_node	*tmp;

	if (*node && (*node)->next)
	{
		tmp = (*node)->next->next;
		aux = *node;
		*node = (*node)->next;
		aux->next = tmp;
		(*node)->next = aux;
	}
}

void	sa(t_node **node)
{
	swap(node);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **node)
{
	swap(node);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **node_a, t_node **node_b)
{
	swap(node_a);
	swap(node_b);
	ft_putstr_fd("ss\n", 1);
}
