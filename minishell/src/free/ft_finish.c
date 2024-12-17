/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:11 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:21:12 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_finish(t_minishell *minishell)
{
	ft_free_tokens(&minishell->tokens);
	ft_free_env(minishell);
	ft_free_cmds(minishell->cmds);
}

void	ft_reboot(t_minishell *minishell)
{
	if (minishell->tokens)
		ft_free_tokens(&minishell->tokens);
	if (minishell->cmds)
		ft_free_cmds(minishell->cmds);
	minishell->cmds = NULL;
	minishell->tokens = NULL;
	minishell->err_par = 0;
}

void	ft_free_tokens(t_token **tokens)
{
	t_token	*token;
	t_token	*prev;

	token = *tokens;
	while (token)
	{
		prev = token;
		token = token->next;
		ft_free_token(prev);
	}
	if (token)
		free(token);
	tokens = NULL;
}

void	ft_free_token(t_token *tok)
{
	free(tok->str);
	free(tok);
}

void	ft_free_cmd(t_cmd *cmd)
{
	if (cmd->fd_in > 0)
	{
		if (access(".heredoc.tmp", F_OK) == 0)
			unlink(".heredoc.tmp");
		close(cmd->fd_in);
	}
	if (cmd->fd_out > 1)
		close(cmd->fd_out);
	ft_free_sarr(cmd->argv);
	free(cmd->argv);
	if (cmd->route)
		free(cmd->route);
	free(cmd);
}
