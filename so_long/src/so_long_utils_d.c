/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:36:30 by marianof          #+#    #+#             */
/*   Updated: 2024/08/06 20:52:42 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_exit(t_data *data)
{
	if (data->colec_c == 0 && data->map[data->player_y][data->player_x] == 'E')
	{
		write(1, "YOU WIN, MAQUINA", 17);
		exit(0);
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
