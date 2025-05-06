/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tex_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:39:09 by marianof          #+#    #+#             */
/*   Updated: 2025/05/06 16:38:53 by marianof         ###   ########.fr       */
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
