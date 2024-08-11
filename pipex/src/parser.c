/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:54:38 by marianof          #+#    #+#             */
/*   Updated: 2024/08/11 21:04:20 by marianof         ###   ########.fr       */
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
			path = ft_split(env[i], ':');
			break ;
		}
		i++;
	}
	if (!path)
		error_and_free(path, "FAILED TO SPLIT");
	path[0] = ft_substr(path[0], 5, ft_strlen(path[0]));
	return (path);
}

char	*search_command(char *cmd, char **cmd_paths)
{
	int		i;
	char	*c;

	i = 0;
	while (cmd_paths[i])
	{
		c = ft_strjoin(cmd_paths[i], "/");
		c = ft_strjoin(c, ft_substr(cmd, 0, ft_strlen(ft_strchr(cmd,
							' '))));
		if (access(c, F_OK) == 0)
			return (c);
		printf("ACCESO: %d\n", access(c, F_OK));
		printf("ITERACIÓN: %s\n", c);
		i++;
		free(c);
	}
	return (NULL);
}
