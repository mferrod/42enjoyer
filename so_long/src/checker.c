/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:09:26 by marianof          #+#    #+#             */
/*   Updated: 2024/08/08 19:35:03 by marianof         ###   ########.fr       */
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
		error("FAILED TO MALLOC MATRIX");
	text_for_matrix = get_next_line(file);
	if (!text_for_matrix)
		error("FAILED TO MALLOC MATRIX");
	while (text_for_matrix)
	{
		matrix[i++] = ft_strdup(text_for_matrix);
		free(text_for_matrix);
		text_for_matrix = get_next_line(file);
	}
	matrix[i] = text_for_matrix;
	close(file);
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
			error("INVALID MAP");
		i++;
	}
	check_all_exteriors(matrix);
	check_interiors(matrix);
}

void	check_all_exteriors(char **matrix)
{
	int	i;
	int	max_length;
	int	lenstr;

	max_length = ft_arraylen(matrix) - 1;
	i = 0;
	lenstr = ft_strlen_sl(matrix[0]) - 1;
	while (matrix[0][i] && matrix[max_length][i])
	{
		if (matrix[0][i] != '1' || matrix[max_length][i] != '1')
			error("INVALID MAP");
		i++;
	}
	i = 0;
	while (matrix[i])
	{
		if (matrix[i][0] != '1' || matrix[i][lenstr] != '1')
			error("INVALID MAP");
		i++;
	}
}

int	ft_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
