/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:57:01 by marianof          #+#    #+#             */
/*   Updated: 2025/04/22 14:40:47 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

char	**free_matrix(char **matrix)
{
	int	t;

	t = 0;
	while (matrix[t])
	{
		free(matrix[t]);
		t++;
	}
	free(matrix);
	return (NULL);
}
