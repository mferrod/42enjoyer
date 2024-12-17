/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:14 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:21:15 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_free_cmds(t_cmd *cmds)
{
	t_cmd	*aux;

	while (cmds)
	{
		aux = (cmds);
		cmds = cmds->next;
		ft_free_cmd(aux);
	}
	cmds = NULL;
}

void	ft_free_sarr(char **str)
{
	int		i;
	char	*c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		i++;
		if (c)
			free(c);
	}
}

void	ft_free_double(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
