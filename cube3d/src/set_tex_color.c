/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tex_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:39:09 by marianof          #+#    #+#             */
/*   Updated: 2025/05/09 13:57:10 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	set_tex_color(t_data *list, char *tex, int *num)
{
	if (!list->east_tex && ft_strncmp(tex, "EA ", 3) == 0)
	{
		list->east_tex = ft_substr(tex, skip_spaces(tex + 2) + 2,
				(ft_strlen(tex) - 4));
		*(num) += 1;
	}
	else if (!list->floor_tex && ft_strncmp(tex, "F ", 2) == 0)
	{
		list->floor_tex = parse_numbers(list, tex);
		*(num) += 1;
	}
	else if (!list->ceiling_tex && ft_strncmp(tex, "C ", 2) == 0)
	{
		list->ceiling_tex = parse_numbers(list, tex);
		*(num) += 1;
	}
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
			break;
		i++;
	}
	map[i] = NULL;
	return (map);
}
