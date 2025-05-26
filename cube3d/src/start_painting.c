/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_painting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:41:37 by marianof          #+#    #+#             */
/*   Updated: 2025/05/22 21:21:38 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	paint_texture(t_data *data, t_ray *ray, int i)
{
	int			y;
	uint32_t	color;

	y = ray->start_two;
	while (y < ray->end_two)
	{
		ray->tex_y = (int)((y - ray->start) * (data->my_texture->height)
				/ (ray->end - ray->start));
		if (ray->tex_y < 0)
			ray->tex_y = 0;
		if (ray->tex_y >= (int)data->my_texture->height)
			ray->tex_y = (int)data->my_texture->height - 1;
		color = *(uint32_t *)(data->my_texture->pixels
				+ (ray->tex_y * data->my_texture->width + ray->tex_x) * 4);
		color = (color & 0xff000000) >> 24 | (color & 0x00ff0000) >> 8
			| (color & 0x0000ff00) << 8 | (color & 0x000000ff) << 24;
		mlx_put_pixel(data->mapi, i, y, color);
		y++;
	}
}

void	select_texture(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
	{
		ray->wall_x = data->player_y + ray->distance * ray->sin;
		if (ray->step_x == -1)
			data->my_texture = data->texture_north;
		else
			data->my_texture = data->texture_south;
	}
	else
	{
		ray->wall_x = data->player_x + ray->distance * ray->cos;
		if (ray->step_y == -1)
			data->my_texture = data->texture_west;
		else
			data->my_texture = data->texture_east;
	}
	ray->wall_x -= floor(ray->wall_x);
	if (ray->wall_x < 0)
		ray->wall_x += 1.0;
	ray->tex_x = (int)(ray->wall_x * data->my_texture->width);
	if (ray->tex_x >= (int)data->my_texture->width)
		ray->tex_x = (int)data->my_texture->width - 1;
	if (ray->tex_x < 0)
		ray->tex_x = 0;
}

void	start_painting(t_data *data, t_ray *ray, int i, double distance)
{
	ray->start = M_HEIGHT / 2 - (M_WIDTH / (2 * distance));
	ray->end = M_HEIGHT / 2 + (M_WIDTH / (2 * distance));
	if (ray->start < 0)
		ray->start_two = 0;
	else
		ray->start_two = ray->start;
	if (ray->end >= M_HEIGHT)
		ray->end_two = M_HEIGHT;
	else
		ray->end_two = ray->end;
	select_texture(ray, data);
	paint_texture(data, ray, i);
}
