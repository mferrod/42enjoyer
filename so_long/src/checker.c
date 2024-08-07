/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:09:26 by marianof          #+#    #+#             */
/*   Updated: 2024/08/07 18:55:50 by marianof         ###   ########.fr       */
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

	i = 0;
	file = open(path_to_file, O_RDONLY);
	matrix = (char **) malloc(sizeof(char *)
			* (count_lines_from_file(path_to_file) + 1));
	if (!matrix)
		error();
	text_for_matrix = get_next_line(file);
	if (!text_for_matrix)
		error();
	while (text_for_matrix)
	{
		matrix[i++] = text_for_matrix;
		text_for_matrix = get_next_line(file);
	}
	matrix[i] = text_for_matrix;
	close(file);
	free(text_for_matrix);
	text_for_matrix = NULL;
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
