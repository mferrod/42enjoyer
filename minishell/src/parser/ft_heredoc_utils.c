/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:40 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 15:53:21 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*expand_heredoc(char *str, t_minishell *shl)
{
	int		i;
	char	*aux;

	i = 0;
	aux = ft_strdup(str);
	free(str);
	while (aux[i])
	{
		if (aux[i] == '$')
			return (ft_dollar_util(&i, aux, shl));
		i++;
	}
	return (aux);
}

void	ctrl_c_hd(int signal)
{
	ft_putstr_fd("\n", 1);
	exit(signal);
}

void	ft_free_and_exit(char *msg, t_minishell *msh, int state, int txt)
{
	if (txt == 1)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putendl_fd(msg, 2);
	}
	ft_free_env(msh);
	msh->env_list = NULL;
	ft_finish(msh);
	exit(state);
}

void	free_exit_hd(t_minishell *shl, t_cmd *cmd, int state)
{
	(void)cmd;
	ft_free_and_exit("", shl, state, 0);
}
