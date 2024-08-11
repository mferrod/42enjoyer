/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:00:51 by marianof          #+#    #+#             */
/*   Updated: 2024/08/11 20:32:58 by marianof         ###   ########.fr       */
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
