/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:37 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:21:38 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_infile(t_minishell *msh, t_cmd *cmd, t_token **tkn)
{
	*tkn = (*tkn)->next;
	if (cmd->err == 0)
	{
		if (cmd->fd_in > 2)
			close(cmd->fd_in);
		cmd->fd_in = open((*tkn)->str, O_RDONLY);
		if (cmd->fd_in == -1)
		{
			ft_open_errors(strerror(errno), (*tkn)->str);
			cmd->err = 1;
			msh->err_state = 1;
		}
	}
	*tkn = (*tkn)->next;
}

void	ft_apdfile(t_minishell *msh, t_cmd *cmd, t_token **tkn)
{
	*tkn = (*tkn)->next;
	if (cmd->err == 0)
	{
		if (cmd->fd_out > 2)
			close(cmd->fd_out);
		cmd->fd_out = open((*tkn)->str, O_APPEND | O_CREAT | O_WRONLY, 0644);
		if (cmd->fd_out == -1)
		{
			ft_open_errors(strerror(errno), (*tkn)->str);
			cmd->err = 1;
			msh->err_state = 1;
		}
	}
	*tkn = (*tkn)->next;
}

void	ft_outfile(t_minishell *msh, t_cmd *cmd, t_token **tkn)
{
	*tkn = (*tkn)->next;
	if (cmd->err == 0)
	{
		if (cmd->fd_out > 2)
			close(cmd->fd_out);
		cmd->fd_out = open((*tkn)->str, O_TRUNC | O_CREAT | O_WRONLY, 0644);
		if (cmd->fd_out == -1)
		{
			ft_open_errors(strerror(errno), (*tkn)->str);
			cmd->err = 1;
			msh->err_state = 1;
		}
	}
	*tkn = (*tkn)->next;
}
