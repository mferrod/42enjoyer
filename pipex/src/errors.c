/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:00:51 by marianof          #+#    #+#             */
/*   Updated: 2024/08/09 15:13:27 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_and_free(t_data *data, char *error)
{
	ft_putendl_fd(error, 2);
	free(data);
	exit(EXIT_FAILURE);
}
