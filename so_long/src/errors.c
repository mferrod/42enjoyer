/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:10:21 by marianof          #+#    #+#             */
/*   Updated: 2024/07/31 19:52:07 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error(void)
{
	write(2, "ERROR.\n", 7);
	exit(1);
}

void	error_and_free(void *c)
{
	write(2, "ERROR.\n", 7);
	if (c)
		free(c);
	exit(1);
}

void	error_and_free_matrix(void **c)
{
	int	i;

	i = 0;
	write(2, "ERROR.\n", 7);
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	exit(1);
}
