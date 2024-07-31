/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:26:28 by marianof          #+#    #+#             */
/*   Updated: 2024/07/31 23:31:55 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	save_player_pos(sl_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_h)
	{
		while (data->map[i][j] != 'P')
			if (data->map[i][j] == 'P')
				break;
			else
				j++;
		if (data->map[i][j] == 'P')
				break;
		j = 0;
		i++;
	}
	valid_map(data);
	data->player_x = j;
	data->player_y = i;
	i = -1;
	while (++i < data->map_h)
		data->c_map[i] = ft_strdup(data->map[i]);
	//flood_fill(data, data->player_x, data->player_y);
}

void	valid_map(sl_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_h)
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
		error_and_free_matrix(data->map);
}
