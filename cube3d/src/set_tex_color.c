/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tex_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:39:09 by marianof          #+#    #+#             */
/*   Updated: 2025/05/15 17:43:35 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	pepe(char ***map, int j, int i, int max)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (max + 1));
	if (!tmp)
		return ;
	while (j < max)
	{
		if (j >= ft_strlen((*map)[i]))
			tmp[j] = ' ';
		else
			tmp[j] = (*map)[i][j];
		j++;
	}
	tmp[j] = '\0';
	free((*map)[i]);
	(*map)[i] = tmp;
}

void	modify_less(char ***map, int i, int j)
{
	int		max;

	max = get_max_lenght((*map));
	i = 0;
	while ((*map)[i])
	{
		if (max > ft_strlen((*map)[i]))
		{
			j = 0;
			pepe(map, j, i, max);
		}
		i++;
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
			break ;
		i++;
	}
	map[i] = NULL;
	return (map);
}
