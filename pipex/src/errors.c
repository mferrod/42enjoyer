/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:00:51 by marianof          #+#    #+#             */
/*   Updated: 2024/08/12 16:07:43 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_and_free(void *c, char *error)
{
	ft_putendl_fd(error, 2);
	free(c);
	exit(EXIT_FAILURE);
}

void	error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	error_and_free_matrix(char **matrix, char *error)
{
	ft_putendl_fd(error, 2);
	free_matrix(matrix);
	exit(EXIT_FAILURE);
}
