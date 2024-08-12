/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:54:38 by marianof          #+#    #+#             */
/*   Updated: 2024/08/12 18:25:28 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**parser(char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			path = ft_split(&env[i][5], ':');
			break ;
		}
		i++;
	}
	if (!path)
		error_and_free_matrix(path, "FAILED TO SPLIT");
	return (path);
}

char	*search_command(char *cmd, char **cmd_paths)
{
	int		i;
	char	*c;
	char	**cmd_matrix;
	char	*aux;

	i = 0;
	cmd_matrix = ft_split(cmd, ' ');
	while (cmd_paths[i])
	{
		aux = ft_strjoin(cmd_paths[i], "/");
		c = ft_strjoin(aux, cmd_matrix[0]);
		if (access(c, F_OK | X_OK) == 0)
			return (free_matrix(cmd_matrix), free(aux), c);
		i++;
		free(c);
		free(aux);
	}
	return (free_matrix(cmd_matrix), NULL);
}

char	**cmd_split(char *args)
{
	char	**cmd_split;

	cmd_split = ft_split(args, ' ');
	if (!cmd_split)
		error("error in cmd split");
	return (cmd_split);
}
