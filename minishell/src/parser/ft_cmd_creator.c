/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:24 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:21:25 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_cmd_creator(t_minishell *msh)
{
	t_token	*tkn;

	tkn = msh->tokens;
	while (tkn)
	{
		if (tkn->type == T_PIPE)
			tkn = tkn->next;
		else
			ft_create_cmds(msh, &tkn);
	}
}
