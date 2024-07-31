/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:36:02 by marianof          #+#    #+#             */
/*   Updated: 2024/07/31 19:23:34 by marianof         ###   ########.fr       */
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
