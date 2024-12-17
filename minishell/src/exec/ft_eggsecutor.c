/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eggsecutor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:18:57 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:18:58 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_eggsecutor(t_minishell *mini)
{
	mini->stdin = dup(STDIN_FILENO);
	mini->stdout = dup(STDOUT_FILENO);
	g_mini_signal = 1;
	if (ft_cmd_len(mini) == 1)
		ft_one_cmd(mini->cmds, mini);
	else
		ft_multi_cmd(mini);
	g_mini_signal = 0;
	dup2(mini->stdin, STDIN_FILENO);
	dup2(mini->stdout, STDOUT_FILENO);
}
