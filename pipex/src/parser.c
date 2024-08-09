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

#include "../includes/pipex.h"

void	parser(char **env, t_data *data)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			data->path = ft_split(env[i], ':');
			break ;
		}
		i++;
	}
	if (!data->path)
		error_and_free(data, "FAILED TO SPLIT");
	data->path[0] = ft_substr(data->path[0], 5, ft_strlen(data->path[0]));
}
