/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:57:56 by marianof          #+#    #+#             */
/*   Updated: 2024/08/11 21:11:44 by marianof         ###   ########.fr       */
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

void	pipex(char **args, char **env, int fd[2])
{
	pid_t	child;
	pid_t	child_s;
	char	**c;

	if (pipe(fd) == -1)
		error("CANT DO PIPE");
	c = parser(env);
	printf("PRUEBA: %s\n", search_command(args[2], c));
	child = fork();
	if (child == -1)
		error("ERROR CREATING CHILD");
	if (child == 0)
	{
		//CREAR HIJOS Y COSAS
	}
}
