/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:38:22 by marianof          #+#    #+#             */
/*   Updated: 2025/05/15 17:38:57 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	last_text(t_data *list, char *tex, int *num)
{
	if (ft_strncmp(tex, "WE ", 3) == 0)
	{
		if (list->west_tex)
			list->flag_dupe = 1;
		else
			list->west_tex = ft_substr(tex, skip_spaces(tex + 2) + 2,
					ft_strlen(tex) - 4);
		*(num) += 1;
	}
	else if (ft_strncmp(tex, "C ", 2) == 0)
	{
		if (list->ceiling_tex)
			list->flag_dupe = 1;
		else
			list->ceiling_tex = parse_numbers(list, tex);
		*(num) += 1;
	}
}

int	get_max_lenght(char **str)
{
	int	max;
	int	i;

	i = 0;
	max = 0;
	while (str[i])
	{
		if (max < ft_strlen(str[i]))
			max = ft_strlen(str[i]);
		i++;
	}
	return (max);
}

void	set_tex_color(t_data *list, char *tex, int *num)
{
	if (ft_strncmp(tex, "EA ", 3) == 0)
	{
		if (list->east_tex)
			list->flag_dupe = 1;
		else
			list->east_tex = ft_substr(tex, skip_spaces(tex + 2) + 2,
					ft_strlen(tex) - 4);
		*(num) += 1;
	}
	else if (ft_strncmp(tex, "F ", 2) == 0)
	{
		if (list->floor_tex)
			list->flag_dupe = 1;
		else
			list->floor_tex = parse_numbers(list, tex);
		*(num) += 1;
	}
	else
		last_text(list, tex, num);
}
