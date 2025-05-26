/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:16:33 by marianof          #+#    #+#             */
/*   Updated: 2025/05/26 13:07:13 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	set_radian_view(t_data *data)
{
	if (data->player_view == 'E')
		return (0);
	else if (data->player_view == 'N')
		return (M_PI_2 + M_PI);
	else if (data->player_view == 'W')
		return (M_PI);
	else
		return (M_PI_2);
}

void	ray_casting(t_data *data, t_ray *ray)
{
	int		i;
	double	ang;
	double	start;
	double	radian_fov;

	i = 0;
	radian_fov = (FIOV * M_PI) / 180;
	ang = (FIOV / M_WIDTH) * M_PI / 180;
	start = data->radian_view - radian_fov / 2;
	while (i < M_WIDTH)
	{
		ray[i].ang = start + (ang * i);
		ray[i].sin = sin(ray[i].ang);
		ray[i].cos = cos(ray[i].ang);
		dda(&ray[i], data, i);
		i++;
	}
}

static void	wall_finder(t_ray *ray, t_data *data)
{
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->map_y][ray->map_x] == '1'
			|| data->map[ray->map_y][ray->map_x] == '\n'
			|| data->map[ray->map_y][ray->map_x] == '\0'
			|| data->map[ray->map_y][ray->map_x] == ' ')
			break ;
	}
}

static void	ray_steps(t_ray *ray, t_data *data)
{
	if (ray->cos < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player_x)
			* ray->delta_dist_x;
	}
	if (ray->sin < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player_y)
			* ray->delta_dist_y;
	}
}

void	dda(t_ray *ray, t_data *data, int i)
{
	double	distance;

	ray->map_x = (int)data->player_x;
	ray->map_y = (int)data->player_y;
	ray->delta_dist_x = fabs(1 / ray->cos);
	ray->delta_dist_y = fabs(1 / ray->sin);
	ray_steps(ray, data);
	wall_finder(ray, data);
	if (ray->side == 0)
		ray->distance = (ray->map_x - data->player_x + (1 - ray->step_x) / 2)
			/ ray->cos;
	else
		ray->distance = (ray->map_y - data->player_y + (1 - ray->step_y) / 2)
			/ ray->sin;
	distance = ray->distance * cos(ray->ang - data->radian_view);
	start_painting(data, ray, i, distance);
}
