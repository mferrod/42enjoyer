/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:35:02 by marianof          #+#    #+#             */
/*   Updated: 2025/05/12 17:48:11 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_parse(t_data *data, char *param)
{
	check_param(param);
	init_list(data, param);
	check_map(data, 0, 0, data->map);
	save_player_pos(data, 0, 0);
}

void	init_list(t_data *list, char *param)
{
	list->map_h = 0;
	list->map_w = 0;
	list->map_count = 0;
	list->player_x = 0;
	list->player_y = 0;
	list->north_tex = NULL;
	list->south_tex = NULL;
	list->east_tex = NULL;
	list->west_tex = NULL;
	list->map = NULL;
	list->ceiling_tex = NULL;
	list->floor_tex = NULL;
	get_textures(list, param);
	valid_list(list);
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init(1920, 1080, "Cub3D", false);
	load_textures(data);
	mlx_loop(data->mlx);
}

int	main(int argc, char const *argv[])
{
	t_data	data;

	if (argc != 2)
		error("Only one parameter.");
	init_parse(&data, (char *)argv[1]);
	//init_game(&data);
	free_all(&data);
	return (0);
}
