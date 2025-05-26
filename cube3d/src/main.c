/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:35:02 by marianof          #+#    #+#             */
/*   Updated: 2025/05/26 12:54:11 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_parse(t_data *data, char *param)
{
	check_param(param);
	init_list(data, param);
	check_map(data, 0, 0, data->map);
	save_player_pos(data, 0, 0);
	data->player_view = data->map[(int)data->player_y][(int)data->player_x];
	data->radian_view = set_radian_view(data);
}

void	init_list(t_data *list, char *param)
{
	list->flag_dupe = 0;
	list->map_h = 0;
	list->map_w = 0;
	list->map_count = 0;
	list->file_count = 0;
	list->player_x = 0.0;
	list->player_y = 0.0;
	list->file_pid = 0;
	list->flag_colors = 0;
	list->north_tex = NULL;
	list->south_tex = NULL;
	list->east_tex = NULL;
	list->west_tex = NULL;
	list->texture_east = NULL;
	list->texture_south = NULL;
	list->texture_north = NULL;
	list->texture_west = NULL;
	list->map = NULL;
	list->mapi = NULL;
	list->mlx = NULL;
	list->ceiling_tex = NULL;
	list->floor_tex = NULL;
	get_textures(list, param);
	valid_list(list);
}

void	set_texture(t_data *data, mlx_texture_t **image, char *path)
{
	(*image) = mlx_load_png(path);
	if (!(*image))
	{
		free_mlx_t(data);
		mlx_terminate(data->mlx);
		error_and_finish(data, "INVALID TEXTURE");
	}
}

void	init_game(t_data *data)
{
	t_ray	ray[M_WIDTH];

	data->ray = ray;
	data->mlx = mlx_init(M_WIDTH, M_HEIGHT, "Cub3D", false);
	data->mapi = mlx_new_image(data->mlx, M_WIDTH, M_HEIGHT);
	load_textures(data);
	paint_all(data);
	mlx_image_to_window(data->mlx, data->mapi, 0, 0);
	ray_casting(data, data->ray);
	mlx_loop_hook(data->mlx, keyhook, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char const *argv[])
{
	t_data	data;

	if (argc != 2)
		error("Only one parameter.");
	init_parse(&data, (char *)argv[1]);
	init_game(&data);
	free_mlx_t(&data);
	mlx_terminate(data.mlx);
	free_all(&data);
	return (0);
}
