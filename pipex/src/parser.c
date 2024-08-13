/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:54:38 by marianof          #+#    #+#             */
/*   Updated: 2024/08/13 19:44:33 by marianof         ###   ########.fr       */
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
	int		count;
	char	**cmd_split_args;

	count = wordcount(args, '\'');
	if (count == 2)
	{
		cmd_split_args = ft_split(args, '\'');
		cmd_split = funcioncilla(cmd_split_args, args);
		free(cmd_split_args);
	}
	else
		cmd_split = ft_split(args, ' ');
	if (!cmd_split)
		error("error in cmd split");
	return (cmd_split);
}

char	**funcioncilla(char **split_arg, char *args)
{
	char	**to_malloc;
	int		i;

	i = 0;
	to_malloc = (char **)malloc(sizeof(char *) * (wordcount(args, '\'') + 1));
	if (!to_malloc)
		return (NULL);
	to_malloc[0] = ft_strtrim(split_arg[0], " ");
	while (args[i])
	{
		to_malloc[i] = ft_strdup(split_arg[i]);
		ft_putstr_fd(to_malloc[i], 2);
		i++;
	}
	to_malloc[i] = NULL;
	return (to_malloc);
}
