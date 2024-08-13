/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:13:10 by marianof          #+#    #+#             */
/*   Updated: 2024/08/13 17:39:09 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	create_first_child(int *fd, char **pars, char **args, char **envp)
{
	int		fd_file;
	char	*cmd;

	close(fd[0]);
	fd_file = open(args[1], O_RDONLY);
	if (fd_file == -1)
		error_and_free_matrix(pars, "ERROR AT OPEN FILE");
	if (dup2(fd_file, 0) == -1)
		error_and_free_matrix(pars, "BAD DUPE ON FILE");
	close(fd_file);
	if (dup2(fd[1], 1) == -1)
		error_and_free_matrix(pars, "BAD DUPE ON FILE");
	close(fd[1]);
	cmd = search_command(args[2], pars);
	if (!cmd)
		error_and_free_matrix(pars, "ERROR FINDING COMMAND");
	if (execve(cmd, cmd_split(args[2]), envp) == -1)
	{
		free(cmd);
		error_and_free_matrix(pars, "ERROR AT CMD_SPLIT");
	}
}

void	create_second_child(int *fd, char **pars, char **args, char **envp)
{
	int		fd_file;
	char	*cmd;

	close(fd[1]);
	fd_file = open(args[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file == -1)
		error("ERROR AT OPEN FILE");
	if (dup2(fd_file, 1) == -1)
		error("BAD DUPE ON FILE");
	if (dup2(fd[0], 0) == -1)
		error("BAD DUPE ON FILE");
	close(fd[0]);
	cmd = search_command(args[3], pars);
	if (!cmd)
		error_and_free_matrix(pars, "ERROR FINDING COMMAND");
	if (execve(cmd, cmd_split(args[3]), envp) == -1)
	{
		free(cmd);
		error_and_free_matrix(pars, "ERROR AT CMD_SPLIT");
	}
}
