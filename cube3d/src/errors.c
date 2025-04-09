/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:35:05 by marianof          #+#    #+#             */
/*   Updated: 2025/04/09 16:00:25 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	error_and_free(void *c)
{
	write(2, "ERROR.\n", 7);
	if (c)
		free(c);
	exit(1);
}

void	error_and_finish(t_data *list, char *txt)
{
	if (txt)
		printf("%s\n", txt);
	if (list)
	{
		if (list->c_map)
			list->map = free_matrix(list->c_map);
		if (list->map)
			list->map = free_matrix(list->map);
		if (list->east_tex)
			free(list->east_tex);
		if (list->north_tex)
			free(list->north_tex);
		if (list->south_tex)
			free(list->south_tex);
		if (list->west_tex)
			free(list->west_tex);
		if (list->ceiling_tex)
			free(list->ceiling_tex);
		if (list->floor_tex)
			free(list->floor_tex);
	}
	free(list);
	exit(1);
}
