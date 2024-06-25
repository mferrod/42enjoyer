/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:42:52 by marianof          #+#    #+#             */
/*   Updated: 2024/06/25 19:19:53 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **node)
{
	t_node	*last;
	t_node	*pre_last;

	last = *node;
	pre_last = NULL;
	if (!*node || !(*node)->next)
		return ;
	while (last->next != NULL)
	{
		pre_last = last;
		last = last->next;
	}
	pre_last->next = NULL;
	last->next = *node;
	*node = last;
}

void	rra(t_node **node)
{
	reverse_rotate(node);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node **node)
{
	reverse_rotate(node);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node **node_a, t_node **node_b)
{
	reverse_rotate(node_a);
	reverse_rotate(node_b);
	ft_putstr_fd("rrr\n", 1);
}
