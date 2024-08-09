/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:54:38 by marianof          #+#    #+#             */
/*   Updated: 2024/08/09 16:07:01 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	**parser(char **env, t_data *data)
{
	char	*path;
	char	**path_splitted;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			path_splitted = ft_split(env[i], ':');
			break ;
		}
		i++;
	}
	if (!path_splitted)
		error_and_free();
}
