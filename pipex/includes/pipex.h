/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:55:45 by marianof          #+#    #+#             */
/*   Updated: 2024/08/09 15:13:43 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <sys/types.h>

// MY LIBRARIES
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_data
{
	int		fd_in;
	int		fd_out;
	char	*cmd;
	char	**path;
	int		pipe[2];
	pid_t	child;
	pid_t	child_s;
}			t_data;

void	error_and_free(t_data *data, char *error);

#endif