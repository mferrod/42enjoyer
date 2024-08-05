/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:12:55 by marianof          #+#    #+#             */
/*   Updated: 2024/08/01 12:28:40 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strlen_sl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	free_flood_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	map = NULL;
}

void init_textures(t_data *data)
{
	set_texture(data->game_init, data->player_img, "../images/player.png");
	set_texture(data->game_init, data->wall_img, "../images/wall.png");
	set_texture(data->game_init, data->colec_img, "../images/colec.png");
	set_texture(data->game_init, data->exit_img, "../images/exit.png");
	set_texture(data->game_init, data->ground_img, "../images/ground.png");
	set_textu_on_chars(data);
	mlx_image_to_window(data->game_init, data->player_img, data->player_x, data->player_y);
}

void	set_texture(mlx_t *game, mlx_image_t *image, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error();
	image = mlx_texture_to_image(game, texture);
	if (!image)
		error();
	mlx_delete_texture(texture);
}

void	set_textu_on_chars(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_h)
	{
		j = -1;
		while (++j < data->map_w)
		{
			if (data->map[i][j] =='1')
				mlx_image_to_window(data->game_init, data->wall_img, j, i);
			if (data->map[i][j] =='0')
				mlx_image_to_window(data->game_init, data->ground_img, j, i);
			if (data->map[i][j] =='E')
				mlx_image_to_window(data->game_init, data->exit_img, j, i);
			if (data->map[i][j] =='C')
			{
				mlx_image_to_window(data->game_init, data->ground_img, j, i);
				mlx_image_to_window(data->game_init, data->colec_img, j, i);
			}
			if (data->map[i][j] =='P')
				mlx_image_to_window(data->game_init, data->ground_img, j, i);
		}
	}
}
