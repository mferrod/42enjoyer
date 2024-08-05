/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:09:26 by marianof          #+#    #+#             */
/*   Updated: 2024/08/01 12:21:33 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_param(char *param)
{
	char	*my_param;
	char	*extension;

	my_param = ".ber";
	extension = ft_substr(param, ft_strlen(param) - 4, ft_strlen(param));
	if (ft_strncmp(extension, my_param, 4) != 0)
		error_and_free(extension);
	free(extension);
}

char	**make_matrix(char *path_to_file)
{
	char	**matrix;
	int		file;
	char	*text_for_matrix;
	int		i;

	matrix = NULL;
	i = 0;
	file = open(path_to_file, O_RDONLY);
	matrix = malloc(sizeof(char *) * count_lines_from_file(path_to_file));
	text_for_matrix = get_next_line(file);
	if (!text_for_matrix)
		error();
	while (text_for_matrix)
	{
		matrix[i] = text_for_matrix;
		i++;
		text_for_matrix = get_next_line(file);
	}
	matrix[i] = text_for_matrix;
	close(file);
	text_for_matrix = NULL;
	free(text_for_matrix);
	return (matrix);
}

void	check_matrix(char **matrix)
{
	int	length;
	int	i;

	i = 0;
	length = ft_strlen_sl(matrix[0]);
	while (matrix[i])
	{
		if (ft_strlen_sl(matrix[i]) != length)
			error();
		i++;
	}
}
