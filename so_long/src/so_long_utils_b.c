/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:12:55 by marianof          #+#    #+#             */
/*   Updated: 2024/08/07 18:03:35 by marianof         ###   ########.fr       */
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

	if (!map || !*map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	init_textures(t_data *data)
{
	set_texture(data->game_init, &data->wall_img, "images/wall.png");
	set_texture(data->game_init, &data->player_img, "images/player.png");
	set_texture(data->game_init, &data->colec_img, "images/colec.png");
	set_texture(data->game_init, &data->exit_img, "images/exit.png");
	set_texture(data->game_init, &data->ground_img, "images/ground.png");
	set_textu_on_chars(data);
	mlx_image_to_window(data->game_init, data->player_img, data->player_x * IMG,
		data->player_y * IMG);
}

void	set_texture(mlx_t *game, mlx_image_t **image, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error();
	(*image) = mlx_texture_to_image(game, texture);
	if (!(*image))
		error();
	mlx_delete_texture(texture);
}

void	set_textu_on_chars(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < data->map_h)
		textu_on_char_two(i, j, data);
}
