/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:11:37 by marianof          #+#    #+#             */
/*   Updated: 2025/05/09 14:17:42 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

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
