/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_funcs4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:56:48 by marianof          #+#    #+#             */
/*   Updated: 2024/07/23 18:06:55 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_smallest(t_node **stack)
{
	t_node	*aux;
	t_node	*lowest;

	aux = *stack;
	lowest = *stack;
	while (aux)
	{
		if (aux->n < lowest->n)
			lowest = aux;
		aux = aux->next;
	}
	return (lowest);
}
