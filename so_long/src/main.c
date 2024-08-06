/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:01:47 by marianof          #+#    #+#             */
/*   Updated: 2024/08/06 19:17:52 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		error();
	map_things(&data, argv[1]);
	free_flood_map(data.c_map);
	setup_game(&data);
	return (0);
}

void	setup_game(t_data *data)
{
	data->game_init = mlx_init(data->map_w * IMG, data->map_h * IMG,
			"so_long", false);
	if (!data->game_init)
		error();
	//init_textures(data);
	//mlx_key_hook(data->game_init, init_controls, data);
	//mlx_loop(data->game_init);
	printf("HASTA AQUÍ LLEGO\n");
	free_flood_map(data->map);
	mlx_terminate(data->game_init);
}
