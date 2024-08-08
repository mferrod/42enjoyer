/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:10:21 by marianof          #+#    #+#             */
/*   Updated: 2024/08/08 19:36:34 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error(char *str)
{
	ft_printf("ERROR: %s", str);
	exit(1);
}

void	error_and_free(void *c)
{
	write(2, "ERROR.\n", 7);
	if (c)
		free(c);
	exit(1);
}

void	error_and_free_matrix(char **c)
{
	write(2, "ERROR.\n", 7);
	free_flood_map(c);
	exit(1);
}
