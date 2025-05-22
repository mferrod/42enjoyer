/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:41:33 by marianof          #+#    #+#             */
/*   Updated: 2025/05/22 20:38:47 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_player_pos(t_data *data, char **map)
{
	if ((int)data->player_y == 0 || (int)data->player_x == 0)
		error_and_finish(data, "Error: Invalid player position\n");
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
				data->player_x = (double)j + 0.5;
				data->player_y = (double)i + 0.5;
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
	check_map_positions(data);
}

int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

void	check_map_positions(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != 'N' && data->map[i][j] != 'E'
				&& data->map[i][j] != 'S' && data->map[i][j] != 'W'
				&& data->map[i][j] != ' ' && data->map[i][j] != '\n'
				&& data->map[i][j] != '0' && data->map[i][j] != '1')
				error_and_finish(data, "Error: Bad character on map.");
			j++;
		}
		i++;
	}
}

void	valid_list(t_data *data)
{
	if (!data->north_tex)
		error_and_finish(data, "Error: North texture not found.");
	if (!data->east_tex)
		error_and_finish(data, "Error: East texture not found.");
	if (!data->south_tex)
		error_and_finish(data, "Error: South texture not found.");
	if (!data->west_tex)
		error_and_finish(data, "Error: West texture not found.");
	if (!data->map)
		error_and_finish(data, "Error: Map not found.");
}
