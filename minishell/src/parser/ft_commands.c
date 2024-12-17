/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:27 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:34:28 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd	*ft_new_cmd_node(void)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->id = -1;
	new->argv = NULL;
	new->fd_in = 0;
	new->fd_out = 1;
	new->err = 0;
	new->route = NULL;
	new->tube[0] = 0;
	new->tube[1] = 0;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new)
{
	t_cmd	*first;

	if (!new)
		return ;
	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}
	first = *lst;
	while (first->next != NULL)
		first = first->next;
	first->next = new;
}

void	ft_create_cmds(t_minishell *msh, t_token **tkns)
{
	t_cmd	*cmd;

	cmd = ft_new_cmd_node();
	cmd->argv = ft_make_cmd_str(&*tkns);
	if (cmd->argv == NULL)
	{
		ft_error_minishell(MALLOC_ERR, msh, 2);
		cmd->err = 1;
	}
	if (cmd && cmd != NULL)
		ft_lstadd_back_cmd(&msh->cmds, cmd);
	ft_set_cmd_id(&msh->cmds);
	ft_setfd(msh, tkns, cmd);
}

char	**ft_make_cmd_str(t_token **tkn)
{
	char	**str;
	int		i;
	t_token	*toks;

	toks = *tkn;
	str = ft_allocate_cmd_str(toks);
	if (!str)
		return (NULL);
	i = 0;
	while (toks && toks->type != T_PIPE)
	{
		if (ft_is_cmd_token(toks->type))
		{
			str[i] = ft_dup_token_str(toks);
			if (!str[i])
				return (ft_free_cmd_str(str, i));
			i++;
		}
		else
			toks = toks->next;
		toks = toks->next;
	}
	str[i] = NULL;
	return (str);
}

int	ft_count_args(t_token *tkn)
{
	t_token	*tok;
	int		i;

	i = 0;
	tok = tkn;
	while (tok && tok->type != T_PIPE)
	{
		if (tok->type != T_DIN && tok->type != T_DOUT && tok->type != T_IN
			&& tok->type != T_OUT)
			i++;
		tok = tok->next;
	}
	return (i);
}
