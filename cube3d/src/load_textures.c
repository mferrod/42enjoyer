/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:11:37 by marianof          #+#    #+#             */
/*   Updated: 2025/05/26 13:11:50 by marianof         ###   ########.fr       */
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

int	get_rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	paint_section(mlx_image_t *img, int start_y, int end_y, int color)
{
	int	x;
	int	y;

	y = start_y;
	while (y < end_y)
	{
		x = 0;
		while (x < M_WIDTH)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	paint_all(t_data *data)
{
	int	rgb_ceiling;
	int	rgb_floor;

	rgb_ceiling = get_rgb(data->ceiling_tex[0], data->ceiling_tex[1],
			data->ceiling_tex[2], 255);
	rgb_floor = get_rgb(data->floor_tex[0], data->floor_tex[1],
			data->floor_tex[2], 255);
	paint_section(data->mapi, 0, M_HEIGHT / 2, rgb_ceiling);
	paint_section(data->mapi, M_HEIGHT / 2, M_HEIGHT, rgb_floor);
}

void	load_textures(t_data *data)
{
	set_texture(data, &data->texture_north, data->north_tex);
	set_texture(data, &data->texture_south, data->south_tex);
	set_texture(data, &data->texture_east, data->east_tex);
	set_texture(data, &data->texture_west, data->west_tex);
}
