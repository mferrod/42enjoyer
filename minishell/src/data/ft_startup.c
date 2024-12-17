/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:18:41 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:31:55 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_set_home(t_minishell *mini)
{
	mini->home = ft_strdup(ft_find_node("HOME", mini)->value);
	if (!mini->home)
		ft_error(mini, "Error setting home\n");
}

void	ft_start(char **envp, t_minishell *mini)
{
	ft_memset(mini, 0, sizeof(t_minishell));
	ft_start_msg();
	ft_save_env(mini, envp);
	ft_set_shellevel(mini);
	ft_set_home(mini);
	signal(SIGINT, ft_handle_sigint);
	signal(SIGQUIT, ft_handle_sigquit);
	ft_create_env_ptr(mini);
}
