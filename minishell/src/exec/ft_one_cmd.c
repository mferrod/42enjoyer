/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:19:12 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 15:53:06 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_one_cmd(t_cmd *cmd, t_minishell *mini)
{
	pid_t	pid;

	ft_basic_io(cmd);
	if (cmd->err == 1)
		return ;
	if (!cmd->argv[0])
		return ;
	if (ft_is_build(cmd->argv[0]))
	{
		ft_exec_b(cmd, mini);
		return ;
	}
	pid = fork();
	if (pid < 0)
		(ft_error(mini, "Fork error\n"));
	if (pid == 0)
	{
		ft_execve(cmd, mini);
		exit(127);
	}
	mini->err_state = ft_wait();
}
