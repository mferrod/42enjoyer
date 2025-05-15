/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:11:37 by marianof          #+#    #+#             */
/*   Updated: 2025/05/14 20:28:52 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	check_param(char *param)
{
	char	*my_param;
	char	*extension;

	my_param = ".cub";
	extension = ft_substr(param, ft_strlen(param) - 4, ft_strlen(param));
	if (ft_strncmp(extension, my_param, 4) != 0)
		error_and_free(extension);
	free(extension);
}

/*void	paint_all(t_data *data, int x, int y)
{
	int	rgb_ceiling;
	int	rgb_floor;

	rgb_ceiling = rgb(data->ceiling_tex[0], data->ceiling_tex[1],
			data->ceiling_tex[2], 255);
	rgb_floor = rgb(data->floor_tex[0], data->floor_tex[1],
			data->floor_tex[2], 255);
	while (M_HEIGHT / 2 > y)
	{
		x = 0;
		while (M_WIDTH > x++)
			mlx_put_pixel(data->mapi, x, y, rgb_ceiling);
		y++;
	}
	while (M_HEIGHT > y)
	{
		x = 0;
		while (M_WIDTH > x++)
			mlx_put_pixel(data->mapi, x, y, rgb_floor);
		y++;
	}
}*/

void	set_texture(mlx_t *game, mlx_image_t **image, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error("INVALID TEXTURE");
	(*image) = mlx_texture_to_image(game, texture);
	if (!(*image))
		error("INVALID IMAGE");
	mlx_delete_texture(texture);
}

void	load_textures(t_data *data)
{
	set_texture(data->mlx, &data->texture_north, data->north_tex);
	set_texture(data->mlx, &data->texture_south, data->south_tex);
	set_texture(data->mlx, &data->texture_east, data->east_tex);
	set_texture(data->mlx, &data->texture_west, data->west_tex);
}
