/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:41:33 by marianof          #+#    #+#             */
/*   Updated: 2025/04/24 17:48:10 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_player_pos(t_data *data, char **map)
{
	if (data->player_y == 0 || data->player_x == 0)
		error_and_finish(data,"Error: Invalid player position\n");
	if ((map[(int)data->player_y][(int)data->player_x - 1] == '\0')
		|| (map[(int)data->player_y][(int)data->player_x + 1] == '\0')
		|| (!map[(int)data->player_y + 1] || map[(int)data->player_y
			+ 1][(int)data->player_x] == '\0') || (map[(int)data->player_y
			- 1][(int)data->player_x] == '\0'))
		error_and_finish(data, "Error: Null around player position\n");
	if ((map[(int)data->player_y][(int)data->player_x - 1] == ' ')
		|| (map[(int)data->player_y][(int)data->player_x + 1] == ' ')
		|| (map[(int)data->player_y + 1][(int)data->player_x] == ' ')
		|| (map[(int)data->player_y - 1][(int)data->player_x] == ' '))
		error_and_finish(data, "Error: Spaces around player position\n");
	if ((map[(int)data->player_y][(int)data->player_x - 1] == '\n')
		|| (map[(int)data->player_y][(int)data->player_x + 1] == '\n')
		|| (map[(int)data->player_y + 1][(int)data->player_x] == '\n')
		|| (map[(int)data->player_y - 1][(int)data->player_x] == '\n'))
		error_and_finish(data, "Error: New line around player position\n");
}

void	save_player_pos(t_data *data, int i, int j)
{
	int	p;

	p = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				p++;
				data->player_x = j;
				data->player_y = i;
			}
			j++;
		}
		i++;
	}
	if (p == 0)
		error_and_finish(data, "Error: No player on the map found.");
	else if (p > 1)
		error_and_finish(data, "Error: Two or more players on the map found.");
	check_player_pos(data, data->map);
}
