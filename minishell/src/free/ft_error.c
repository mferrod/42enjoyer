/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:08 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:34:01 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_error(t_minishell *mini, char *msg)
{
	if (mini)
	{
		ft_free_env(mini);
		ft_free_tokens(&mini->tokens);
		ft_free_cmds(mini->cmds);
	}
	if (msg)
		printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
