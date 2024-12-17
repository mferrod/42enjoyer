/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:17:56 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 02:05:20 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(t_minishell *mini)
{
	char	*wd;

	wd = getcwd(NULL, 0);
	if (!wd)
		ft_error(mini, "Error getting cwd.\n");
	ft_putstr_fd(wd, 1);
	free(wd);
	ft_putchar_fd('\n', 1);
	mini->err_state = 0;
}
