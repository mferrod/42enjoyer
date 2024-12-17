/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:19:15 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:33:04 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_basic_io(t_cmd *cmd)
{
	if (cmd->fd_in != STDIN_FILENO)
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != STDOUT_FILENO)
	{
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
	}
}

void	ft_create_pipes(t_cmd *cmd, t_minishell *mini)
{
	int	tube[2];

	if (cmd->next)
	{
		if (pipe(tube) == -1)
			ft_error(mini, "Error creating pipe\n");
		if (cmd->fd_out == STDOUT_FILENO)
			cmd->fd_out = dup(tube[1]);
		close(tube[1]);
		if (cmd->next->fd_in == STDIN_FILENO)
			cmd->next->fd_in = dup(tube[0]);
		close(tube[0]);
	}
}

void	ft_set_io(t_cmd *cmd)
{
	if (cmd->fd_in != STDIN_FILENO)
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != STDOUT_FILENO)
	{
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
	}
}
