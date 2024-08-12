/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:57:56 by marianof          #+#    #+#             */
/*   Updated: 2024/08/12 17:55:01 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc == 5)
	{
		pipex(argv, envp, fd);
	}
	else
		error("ONLY 5 ARGUMENTS");
	return (EXIT_SUCCESS);
}

void	pipex(char **args, char **env, int *fd)
{
	pid_t	child;
	pid_t	child_s;
	char	**pars;

	if (pipe(fd) == -1)
		error("CANT DO PIPE");
	pars = parser(env);
	child = fork();
	if (child == -1)
		error("ERROR CREATING CHILD");
	if (child == 0)
	{
		create_first_child(fd, pars, args, env);
		waitpid(child, NULL, 0);
	}
	close(fd[1]);
	child_s = fork();
	if (child_s == -1)
		error("ERROR CREATING CHILD");
	if (child_s == 0)
		create_second_child(fd, pars, args, env);
	close(fd[0]);
	waitpid(child_s, NULL, 0);
	free_matrix(pars);
}
