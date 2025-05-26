/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:35:47 by achacon-          #+#    #+#             */
/*   Updated: 2025/05/26 12:36:15 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_not_wall(t_data *data, double x, double y)
{
	if (data->map[(int)y][(int)x] == '1')
		return (0);
	else
		return (1);
}

void	move(t_data *data, double mod_x, double mod_y)
{
	double	new_x;
	double	new_y;

	new_x = data->player_x + mod_x;
	new_y = data->player_y + mod_y;
	if (is_not_wall(data, new_x, new_y))
	{
		data->player_x = new_x;
		data->player_y = new_y;
	}
}

void	keyhook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move(data, PLAYER_SPEED * cos(data->radian_view), PLAYER_SPEED
			* sin(data->radian_view));
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move(data, -PLAYER_SPEED * cos(data->radian_view), -PLAYER_SPEED
			* sin(data->radian_view));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move(data, -PLAYER_SPEED * cos(data->radian_view + M_PI / 2),
			-PLAYER_SPEED * sin(data->radian_view + M_PI / 2));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move(data, PLAYER_SPEED * cos(data->radian_view + M_PI / 2),
			PLAYER_SPEED * sin(data->radian_view + M_PI / 2));
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->radian_view -= ANGLE_MOVE;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->radian_view += ANGLE_MOVE;
	paint_all(data);
	ray_casting(data, data->ray);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}
