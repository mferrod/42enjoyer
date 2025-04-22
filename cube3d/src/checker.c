/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:43:34 by marianof          #+#    #+#             */
/*   Updated: 2025/04/22 17:01:55 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_textures_on_list(t_data *list, char *tex)
{
	if (tex[0] == 'N')
		list->north_tex = ft_substr(tex, find_char(tex, '.'), (ft_strlen(tex)
					- 4));
	else if (tex[0] == 'S')
		list->south_tex = ft_substr(tex, find_char(tex, '.'), ft_strlen(tex)
				- 4);
	else if (tex[0] == 'W')
		list->west_tex = ft_substr(tex, find_char(tex, '.'), (ft_strlen(tex)
					- 4));
	else if (tex[0] == 'E')
		list->east_tex = ft_substr(tex, find_char(tex, '.'), (ft_strlen(tex)
					- 4));
	else if (tex[0] == 'F')
		list->floor_tex = parse_numbers(list, tex);
	else if (tex[0] == 'C')
		list->ceiling_tex = parse_numbers(list, tex);
}

void	get_textures(t_data *list, char *param)
{
	int		file;
	char	*text_check;

	file = open(param, O_RDONLY);
	text_check = get_next_line(file);
	if (!text_check)
		error("FAILED TO MALLOC MATRIX");
	while (text_check[0] != 32)
	{
		set_textures_on_list(list, text_check);
		free(text_check);
		text_check = get_next_line(file);
	}
	set_textures_on_list(list, text_check);
	list->map = make_matrix(file, text_check);
	close(file);
	if (text_check)
		free(text_check);
}

void	init_list(t_data *list, char *param)
{
	list->map_h = 0;
	list->map_w = 0;
	get_textures(list, param);
	check_map(param);
}

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

char	**make_matrix(int file, char *param)
{
	char	**matrix;
	char	*text_for_matrix;
	char	*text_join;
	char	*text_aux;

	text_join = ft_strdup(param);
	text_for_matrix = get_next_line(file);
	if (!text_for_matrix)
		error("FAILED TO MALLOC MATRIX");
	while (text_for_matrix)
	{
		text_aux = ft_strdup(text_join);
		free(text_join);
		text_join = ft_strjoin(text_aux, text_for_matrix);
		free(text_aux);
		free(text_for_matrix);
		text_for_matrix = get_next_line(file);
	}
	text_for_matrix = NULL;
	matrix = ft_split(text_join, '\n');
	free(text_join);
	return (matrix);
}
