/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:36:02 by marianof          #+#    #+#             */
/*   Updated: 2024/08/01 12:17:20 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_lines_from_file(char *path)
{
	int		i;
	int		file;
	char	*text_from_file;

	if (!path)
		error();
	file = open(path, O_RDONLY);
	i = 0;
	text_from_file = get_next_line(file);
	while (text_from_file)
	{
		i++;
		text_from_file = get_next_line(file);
	}
	close(file);
	text_from_file = NULL;
	free(text_from_file);
	return (i);
}

int	matrix_length(char **matrix)
{
	int	i;

	while (matrix[i])
		i++;
	return (i);
}

void	init_struct(t_data *data)
{
	data->player_c = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->colec_c = 0;
	data->exit_c = 0;
	data->map_h = 0;
	data->map_w = 0;
}

void	map_things(t_data *data, char *param)
{
	check_param(param);
	init_struct(data);
	data->map = make_matrix(param);
	data->c_map = ft_calloc(sizeof(char *), count_lines_from_file(param));
	check_matrix(data->map);
	data->map_w = ft_strlen(data->map[0]);
	data->map_h = count_lines_from_file(param);
	save_player_pos(data);
}
