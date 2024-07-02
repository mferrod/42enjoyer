/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:51:50 by marianof          #+#    #+#             */
/*   Updated: 2024/07/02 13:43:59 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*aux;
	t_node	*new;

	if (src != NULL && dest != NULL)
	{
		new = *src;
		aux = *dest;
		*src = (*src)->next;
		new->next = aux;
		*dest = new;
	}
}

void	push_a(t_node **node_a, t_node **node_b)
{
	push(node_b, node_a);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_node **node_a, t_node **node_b)
{
	push(node_a, node_b);
	ft_putstr_fd("pb\n", 1);
}
