/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tex_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:39:09 by marianof          #+#    #+#             */
/*   Updated: 2025/05/13 15:04:49 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	last_text(t_data *list, char *tex, int *num)
{
	if (ft_strncmp(tex, "WE ", 3) == 0)
	{
		if (list->west_tex)
			error_and_finish(list, "ERROR: TEXTURE_WE already setted.");
		list->west_tex = ft_substr(tex, skip_spaces(tex + 2) + 2,
				(ft_strlen(tex) - 4));
		*(num) += 1;
	}
}

void	set_tex_color(t_data *list, char *tex, int *num)
{
	if (ft_strncmp(tex, "EA ", 3) == 0)
	{
		if (list->east_tex)
			error_and_finish(list, "ERROR: TEXTURE_EA already setted.");
		list->east_tex = ft_substr(tex, skip_spaces(tex + 2) + 2,
				(ft_strlen(tex) - 4));
		*(num) += 1;
	}
	else if (ft_strncmp(tex, "F ", 2) == 0)
	{
		if (list->floor_tex)
			error_and_finish(list, "ERROR: Floor already setted.");
		list->floor_tex = parse_numbers(list, tex);
		*(num) += 1;
	}
	else if (ft_strncmp(tex, "C ", 2) == 0)
	{
		if (list->ceiling_tex)
			error_and_finish(list, "ERROR: Ceiling already setted.");
		list->ceiling_tex = parse_numbers(list, tex);
		*(num) += 1;
	}
	else
		last_text(list, tex, num);
}

static char	*extract_line(char *str, int *start)
{
	int		len;
	char	*line;

	len = 0;
	while (str[*start + len] && str[*start + len] != '\n')
		len++;
	line = ft_substr(str, *start, len);
	if (str[*start + len] == '\n')
		*start += len + 1;
	else
		*start += len;
	return (line);
}

char	**remake_map(char *str, int count)
{
	char	**map;
	int		i;
	int		start;

	i = 0;
	start = 0;
	map = malloc(sizeof(char *) * (count + 1));
	if (!map)
		return (NULL);
	while (str[start])
	{
		map[i] = extract_line(str, &start);
		if (!map[i])
			break ;
		i++;
	}
	map[i] = NULL;
	return (map);
}
