/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:16:33 by marianof          #+#    #+#             */
/*   Updated: 2025/05/20 21:42:49 by marianof         ###   ########.fr       */
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
	double	angle;
	double	start;
	double	local_fov;

	i = 0;
	local_fov = (FIOV * M_PI) / 180;
	angle = (FIOV / M_WIDTH) * M_PI / 180;
	start = data->radian_view - local_fov / 2;
	while (i < M_WIDTH)
	{
		ray[i].ang = start + (angle * 1);
		ray[i].sin = sin(ray[i].ang);
		ray[i].cos = cos(ray[i].ang);
		i++;
	}
}

void	dda_algo(t_ray *ray, t_data *data, int i)
{
	double	distance;

	ray->map_x = (int)data->player_x;
	ray->map_y = (int)data->player_y;
	ray->delta_dist_x = fabs(1 / ray->cos);
	ray->delta_dist_y = fabs(1 / ray->sin);
	if (ray->side == 0)
		ray->distance = (ray->map_x - data->player_x
				+ (1 - ray->step_x) / 2) / ray->cos;
	else
		ray->distance = (ray->map_y - data->player_y
				+ (1 - ray->step_y) / 2) / ray->sin;
	distance = ray->distance * cos (ray->ang - data->radian_view);
}
