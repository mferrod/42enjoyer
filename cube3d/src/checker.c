/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:43:34 by marianof          #+#    #+#             */
/*   Updated: 2025/05/06 16:37:18 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_textures_on_list(t_data *list, char *tex, int *num)
{
	if (!list->north_tex && ft_strncmp(tex, "NO ", 3) == 0)
	{
		list->north_tex = ft_substr(tex, skip_spaces(tex + 2) + 2,
				(ft_strlen(tex) - 4));
		*(num) += 1;
	}
	else if (!list->south_tex && ft_strncmp(tex, "SO ", 3) == 0)
	{
		list->south_tex = ft_substr(tex, skip_spaces(tex + 2) + 2,
				ft_strlen(tex) - 4);
		*(num) += 1;
	}
	else if (!list->west_tex && ft_strncmp(tex, "WE ", 3) == 0)
	{
		list->west_tex = ft_substr(tex, skip_spaces(tex + 2) + 2,
				(ft_strlen(tex) - 4));
		*(num) += 1;
	}
	else
		set_tex_color(list, tex, num);
}

void	get_textures(t_data *list, char *param)
{
	int		file;
	char	*text_check;
	int		num;

	num = 0;
	file = open(param, O_RDONLY);
	text_check = get_next_line(file);
	if (!text_check)
		error("Error: FAILED TO MALLOC on get_textures");
	while (num != 6)
	{
		set_textures_on_list(list, text_check, &num);
		free(text_check);
		text_check = get_next_line(file);
	}
	make_matrix(file, text_check, list);
	close(file);
	if (text_check)
		free(text_check);
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

void	make_matrix(int file, char *param, t_data *list)
{
	char	*text_for_matrix;
	char	*text_join;
	char	*text_aux;

	text_join = ft_strdup(param);
	text_for_matrix = get_next_line(file);
	if (!text_for_matrix)
		error("Error: FAILED TO MALLOC on make_matrix");
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
	list->map = ft_split(text_join, '\n');
	free(text_join);
}
