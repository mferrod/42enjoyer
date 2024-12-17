/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:11:13 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/13 11:11:13 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_exec_b(t_cmd *cmd, t_minishell *mini)
{
	if (!ft_strncmp(cmd->argv[0], "cd", 2))
		ft_cd(&cmd->argv[1], mini);
	if (!ft_strncmp(cmd->argv[0], "echo", 4))
		ft_echo(&cmd->argv[1], mini);
	if (!ft_strncmp(cmd->argv[0], "env", 3))
		ft_env(mini);
	if (!ft_strncmp(cmd->argv[0], "export", 6))
		ft_export(&cmd->argv[1], mini);
	if (!ft_strncmp(cmd->argv[0], "pwd", 3))
		ft_pwd(mini);
	if (!ft_strncmp(cmd->argv[0], "unset", 5))
		ft_unset(&cmd->argv[1], mini);
	if (!ft_strncmp(cmd->argv[0], "exit", 4))
		ft_exit(&cmd->argv[1], mini);
}

int	ft_is_build(char *cmd)
{
	if (ft_strlen(cmd) == 4 && !ft_strncmp(cmd, "echo", 4))
		return (1);
	if (ft_strlen(cmd) == 2 && !ft_strncmp(cmd, "cd", 2))
		return (1);
	if (ft_strlen(cmd) == 3 && !ft_strncmp(cmd, "pwd", 3))
		return (1);
	if (ft_strlen(cmd) == 6 && !ft_strncmp(cmd, "export", 6))
		return (1);
	if (ft_strlen(cmd) == 5 && !ft_strncmp(cmd, "unset", 5))
		return (1);
	if (ft_strlen(cmd) == 3 && !ft_strncmp(cmd, "env", 3))
		return (1);
	if (ft_strlen(cmd) == 4 && !ft_strncmp(cmd, "exit", 4))
		return (1);
	return (0);
}
