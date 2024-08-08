/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:26:28 by marianof          #+#    #+#             */
/*   Updated: 2024/08/08 19:35:06 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	save_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_h)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
			}
			j++;
		}
		i++;
	}
	valid_map(data);
	i = -1;
	while (data->map[++i])
		data->c_map[i] = ft_strdup(data->map[i]);
	data->c_map[i] = NULL;
	flood_fill(data, data->player_x, data->player_y);
	valid_map_flood(data);
}

void	valid_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				data->player_c++;
			if (data->map[i][j] == 'C')
				data->colec_c++;
			if (data->map[i][j] == 'E')
				data->exit_c++;
			j++;
		}
		j = 0;
		i++;
	}
	if (data->player_c != 1 || data->colec_c <= 0 || data->exit_c != 1)
		error("INVALID MAP");
}

void	flood_fill(t_data *data, int x, int y)
{
	if (data->c_map[y][x] == '1' || data->c_map[y][x] == 'F')
		return ;
	data->c_map[y][x] = 'F';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}
