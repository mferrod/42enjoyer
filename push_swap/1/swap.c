/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:32:07 by marianof          #+#    #+#             */
/*   Updated: 2024/06/25 17:36:07 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **node)
{
	int	aux;

	if (!node || !(*node)->next || !(*node))
		return ;
	aux = (*node)->n;
	(*node)->n = (*node)->next->n;
	(*node)->next->n = aux;
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
