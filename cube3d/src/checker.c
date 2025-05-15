/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:43:34 by marianof          #+#    #+#             */
/*   Updated: 2025/05/15 12:21:36 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_textures_on_list(t_data *list, char *tex, int *num)
{
	if (ft_strncmp(tex, "NO ", 3) == 0)
	{
		if (list->north_tex)
			error_and_finish(list, "ERROR: TEXTURE_NO ALREADY SETTED.");
		list->north_tex = ft_substr(tex, skip_spaces(tex + 2) + 2,
				(ft_strlen(tex) - 4));
		*(num) += 1;
	}
	else if (ft_strncmp(tex, "SO ", 3) == 0)
	{
		if (list->south_tex)
			list->flag_dupe = 1;
		else
			list->south_tex = ft_substr(tex, skip_spaces(tex + 2) + 2,
					ft_strlen(tex) - 4);
		*(num) += 1;
	}
	else
		set_tex_color(list, tex, num);
}

static void	check_flag(t_data *list, char *param)
{
	if (list->flag_dupe == 1)
	{
		if (param)
			free(param);
		error_and_finish(list, "ERROR: TEXTURE OR COLOR DUPED.");
	}
}

void	get_textures(t_data *list, char *param)
{
	char	*text_check;
	int		num;

	num = 0;
	list->file_pid = open(param, O_RDONLY);
	text_check = get_next_line(list->file_pid);
	if (!text_check)
		error("Error: FAILED TO MALLOC on get_textures");
	while (text_check)
	{
		set_textures_on_list(list, text_check, &num);
		free(text_check);
		text_check = get_next_line(list->file_pid);
		list->file_count++;
	}
	check_flag(list, text_check);
	close(list->file_pid);
	if (num != 6)
		error_and_finish(list, "ERROR: DATA MAP NOT FOUND.");
	make_matrix(param, list);
	close(list->file_pid);
	if (text_check)
		free(text_check);
}

static char	*find_map(char *dir, t_data *data)
{
	char	*get_next;

	data->file_pid = open(dir, O_RDONLY);
	get_next = get_next_line(data->file_pid);
	if (!get_next)
		error_and_finish(data, "Error: FAILED TO MALLOC on find_map");
	while (get_next[skip_spaces(get_next)] != '1'
		&& get_next[skip_spaces(get_next)] != '0')
	{
		free(get_next);
		get_next = NULL;
		get_next = get_next_line(data->file_pid);
	}
	return (get_next);
}

void	make_matrix(char *param, t_data *list)
{
	char	*text_for_matrix;
	char	*text_join;
	char	*text_aux;

	text_join = find_map(param, list);
	text_for_matrix = get_next_line(list->file_pid);
	if (!text_for_matrix)
		error("Error: FAILED TO MALLOC on make_matrix");
	while (text_for_matrix)
	{
		text_aux = ft_strdup(text_join);
		free(text_join);
		text_join = ft_strjoin(text_aux, text_for_matrix);
		free(text_aux);
		free(text_for_matrix);
		text_for_matrix = get_next_line(list->file_pid);
		list->map_count++;
	}
	list->map_count++;
	free(text_for_matrix);
	text_for_matrix = NULL;
	list->map = remake_map(text_join, list->map_count);
	if (text_join)
		free(text_join);
}
