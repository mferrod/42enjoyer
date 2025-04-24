/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:35:02 by marianof          #+#    #+#             */
/*   Updated: 2025/04/24 17:29:14 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_parse(t_data *data, char *param)
{
	check_param(param);
	init_list(data, param);
	check_map(data, 0, 0, data->map);
	save_player_pos(data, 0, 0);
	printf("X: %d \nY: %d \n", data->player_x, data->player_y);
}

int	main(int argc, char const *argv[])
{
	t_data	data;

	if (argc != 2)
		error("Only one parameter.");
	init_parse(&data, (char *)argv[1]);
	free_all(&data);
	return (0);
}
