/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:13:10 by marianof          #+#    #+#             */
/*   Updated: 2024/08/11 20:30:21 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	create_first_child(int fd[2], char **args)
{
	int	fd_file;

	close(fd[0]);
	fd_file = open(args[1], O_RDONLY);
	if (fd_file == -1)
		error("ERROR AT OPEN FILE");
}
