/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:57:01 by marianof          #+#    #+#             */
/*   Updated: 2025/05/13 15:13:15 by marianof         ###   ########.fr       */
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
		matrix[t] = NULL;
		t++;
	}
	free(matrix);
	return (NULL);
}

void	free_all(t_data *data)
{
	if (data)
	{
		if (data->map)
			data->map = free_matrix(data->map);
		if (data->east_tex)
			free(data->east_tex);
		if (data->north_tex)
			free(data->north_tex);
		if (data->south_tex)
			free(data->south_tex);
		if (data->west_tex)
			free(data->west_tex);
		if (data->ceiling_tex)
			free(data->ceiling_tex);
		if (data->floor_tex)
			free(data->floor_tex);
		if (data->file_pid > 0)
			close(data->file_pid);
	}
}
