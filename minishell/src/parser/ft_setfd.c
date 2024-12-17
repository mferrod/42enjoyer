/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setfd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:57 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:21:58 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_setfd(t_minishell *msh, t_token **tkns, t_cmd *cmd)
{
	while (*tkns && (*tkns)->type != T_PIPE)
	{
		if ((*tkns)->type == T_OUT)
			ft_outfile(msh, cmd, tkns);
		else if ((*tkns)->type == T_DOUT)
			ft_apdfile(msh, cmd, tkns);
		else if ((*tkns)->type == T_IN)
			ft_infile(msh, cmd, tkns);
		else if ((*tkns)->type == T_DIN)
			ft_heredoc_init(msh, cmd, tkns);
		else
			*tkns = (*tkns)->next;
	}
}

void	ft_set_cmd_id(t_cmd **cmds)
{
	t_cmd	*cmd;
	int		id;

	id = 0;
	cmd = *cmds;
	while (cmd)
	{
		id++;
		cmd->id = id;
		cmd = cmd->next;
	}
}
