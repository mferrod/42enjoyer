/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:17:34 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 02:03:20 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_cd(char **argv, t_minishell *mini)
{
	if (argv[1])
	{
		ft_putstr_fd("AweboteShell: cd: too many arguments\n", 2);
		mini->err_state = 1;
	}
	mini->err_state = 0;
	if (!argv[0])
	{
		if (chdir(mini->home) != 0)
		{
			perror("chdir error");
			mini->err_state = 1;
		}
	}
	else
	{
		if (chdir(argv[0]) != 0)
		{
			perror("chdir error");
			mini->err_state = 1;
		}
	}
}
