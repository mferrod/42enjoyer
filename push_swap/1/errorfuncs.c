/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorfuncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:00:04 by marianof          #+#    #+#             */
/*   Updated: 2024/04/02 19:06:02 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(2);
}

void	error_and_free(void *c)
{
	free(c);
	write(2, "Error\n", 6);
	exit(2);
}
