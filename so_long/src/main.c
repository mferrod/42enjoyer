/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:01:47 by marianof          #+#    #+#             */
/*   Updated: 2024/08/08 19:38:36 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc < 2)
		error("YOU NEED TO ADD AN ARGUMENT");
	else if (argc > 2)
		error("TOO MUCH ARGUMENTS");
	else if (argc == 2)
	{
		map_things(&data, argv[1]);
		free_flood_map(data.c_map);
		setup_game(&data);
	}
	return (0);
}

void	setup_game(t_data *data)
{
	data->game_init = mlx_init((data->map_w - 1) * IMG, data->map_h * IMG,
			"so_long", false);
	if (!data->game_init)
		error("FAIL AT INIT MLX");
	init_textures(data);
	mlx_key_hook(data->game_init, init_controls, data);
	mlx_loop(data->game_init);
	if (data->map)
		free_flood_map(data->map);
	mlx_terminate(data->game_init);
}
