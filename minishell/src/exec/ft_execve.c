/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:19:04 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:32:56 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_execve(t_cmd *cmd, t_minishell *mini)
{
	char	*aux;

	aux = cmd->argv[0];
	if (aux == NULL)
		ft_error(mini, "No command found\n");
	if (ft_strchr(aux, '/'))
		cmd->route = ft_strdup(aux);
	else
		cmd->route = ft_search_path(aux, ft_get_path_ptr(mini));
	if (ft_permission(cmd->route))
		execve(cmd->route, cmd->argv, mini->envp);
	ft_error(mini, "Error executing command\n");
}
