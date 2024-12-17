/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:19:08 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 15:53:09 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_exe_child(t_cmd *cmd, t_minishell *mini)
{
	if (cmd->next)
		close(cmd->next->fd_in);
	ft_set_io(cmd);
	if (ft_is_build(cmd->argv[0]))
	{
		ft_exec_b(cmd, mini);
		cmd = cmd->next;
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_execve(cmd, mini);
		ft_error(mini, "Execve error\n");
	}
}

int	ft_wait(void)
{
	int	status;
	int	out_status;

	out_status = 0;
	wait(&status);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		out_status = WEXITSTATUS(status);
	else if (WIFEXITED(status) && WIFSIGNALED(status) != 0)
		out_status = WTERMSIG(status);
	else
		out_status = 0;
	return (out_status);
}

void	ft_multi_cmd(t_minishell *mini)
{
	t_cmd	*aux;
	pid_t	pid;

	aux = mini->cmds;
	while (aux)
	{
		ft_create_pipes(aux, mini);
		pid = fork();
		if (pid < 0)
			ft_error(mini, "Fork error\n");
		if (pid == 0)
		{
			ft_exe_child(aux, mini);
		}
		close(aux->fd_out);
		if (aux->id == ft_cmd_len(mini))
			mini->err_state = ft_wait();
		aux = aux->next;
	}
}
