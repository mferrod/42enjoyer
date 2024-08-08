/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:36:30 by marianof          #+#    #+#             */
/*   Updated: 2024/08/08 19:36:25 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_exit(t_data *data)
{
	if (data->colec_c == 0 && data->map[data->player_y][data->player_x] == 'E')
	{
		write(1, "YOU WIN, MAQUINA\n", 18);
		free_all(data);
	}
	else if (data->colec_c > 0
		&& data->map[data->player_y][data->player_x] == 'C')
	{
		data->colec_c--;
		mlx_image_to_window(data->game_init, data->ground_img, data->player_x
			* IMG, data->player_y * IMG);
		set_texture(data->game_init, &data->player_img, "images/player.png");
		mlx_image_to_window(data->game_init, data->player_img, data->player_x
			* IMG, data->player_y * IMG);
		data->map[data->player_y][data->player_x] = '0';
	}
}

void	free_images(t_data *data)
{
	if (data->exit_img)
		mlx_delete_image(data->game_init, data->exit_img);
	if (data->wall_img)
		mlx_delete_image(data->game_init, data->wall_img);
	if (data->colec_img)
		mlx_delete_image(data->game_init, data->colec_img);
	if (data->ground_img)
		mlx_delete_image(data->game_init, data->ground_img);
	if (data->player_img)
		mlx_delete_image(data->game_init, data->player_img);
}

void	free_all(t_data *data)
{
	if (data)
	{
		free_flood_map(data->map);
		free_images(data);
		mlx_close_window(data->game_init);
		mlx_terminate(data->game_init);
	}
	exit(0);
}

void	valid_map_flood(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->c_map[i])
	{
		while (data->c_map[i][j])
		{
			if (data->c_map[i][j] == 'P')
				error("INVALID MAP");
			if (data->c_map[i][j] == 'C')
				error("INVALID MAP");
			if (data->c_map[i][j] == 'E')
				error("INVALID MAP");
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_interiors(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] != 'P' && matrix[i][j] != 'C'
				&& matrix[i][j] != 'E' && matrix[i][j] != '1'
				&& matrix[i][j] != '0' && matrix[i][j] != '\n')
				error("INVALID MAP");
			j++;
		}
		j = 0;
		i++;
	}
}
