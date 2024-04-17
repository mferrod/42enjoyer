/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:45:47 by marianof          #+#    #+#             */
/*   Updated: 2024/04/12 20:10:14 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **node)
{
	int	aux;

	if (!node || !(*node) || (*node)->next)
		return ;
	aux = (*node)->n;
	(*node)->n = (*node)->next->n;
	(*node)->next->n = aux;
}

void	ra(t_node **node)
{
	if (!*node || !(*node)->next)
		return ;
	(*node) = (*node)->next;
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
}
