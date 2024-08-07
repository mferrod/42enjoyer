/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 09:48:27 by marianof          #+#    #+#             */
/*   Updated: 2024/08/07 19:09:08 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_controls(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS && data->map[data->player_y
			- 1][data->player_x] != '1')
		player_mov_up(data);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS && data->map[data->player_y
			+ 1][data->player_x] != '1')
		player_mov_down(data);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS
		&& data->map[data->player_y][data->player_x - 1] != '1')
		player_mov_left(data);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS
		&& data->map[data->player_y][data->player_x + 1] != '1')
		player_mov_right(data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		free_all(data);
	check_exit(data);
}

void	player_mov_up(t_data *data)
{
	data->player_y--;
	data->player_img->instances[0].y -= IMG;
	data->player_steps++;
	ft_printf("MOVES: %d\n", data->player_steps);
}

void	player_mov_down(t_data *data)
{
	data->player_y++;
	data->player_img->instances[0].y += IMG;
	data->player_steps++;
	ft_printf("MOVES: %d\n", data->player_steps);
}

void	player_mov_left(t_data *data)
{
	data->player_x--;
	data->player_img->instances[0].x -= IMG;
	data->player_steps++;
	ft_printf("MOVES: %d\n", data->player_steps);
}

void	player_mov_right(t_data *data)
{
	data->player_x++;
	data->player_img->instances[0].x += IMG;
	data->player_steps++;
	ft_printf("MOVES: %d\n", data->player_steps);
}
