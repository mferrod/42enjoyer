/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:57:56 by marianof          #+#    #+#             */
/*   Updated: 2024/08/09 15:54:27 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc == 5)
	{
		pipex(&data, argv, envp);
	}
	else
		error("ONLY 5 ARGUMENTS");
	return (EXIT_SUCCESS);
}

void	pipex(t_data *data, char **args, char **env)
{
	(void) args;
	if (pipe(data->pipe) == -1)
		error_and_free(data, "CANT DO PIPE");
	parser(env, data);
	int i = 0;
	while (data->path[i]) {
		ft_putendl_fd(data->path[i], 0);
		i++;
	}
}
