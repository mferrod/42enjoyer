/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianonof@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:15:44 by marianof          #+#    #+#             */
/*   Updated: 2024/04/12 17:57:19 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_node *node)
{
	t_node  *last_n;

	last_n = node->prev;
	while (node != last_n)
	{
		if (node->n > node->next->n)
			return (0);
		node = node->next;
	}
	return (1);
}
