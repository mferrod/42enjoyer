/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:17:47 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 01:56:51 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_num_str(const char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_mod_exit(char **argv, t_minishell *mini)
{
	if (!ft_num_str(argv[0]))
	{
		ft_putstr_fd("Aweboteshell: exit: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		ft_finish(mini);
		exit(2);
	}
	if (ft_num_str(argv[0]) && argv[1] == NULL)
	{
		mini->err_state = ft_atoi(argv[0]) % 256;
		ft_finish(mini);
		ft_putstr_fd("exit\n", 1);
		exit(mini->err_state);
	}
	if (ft_num_str(argv[0]) && argv[1] != NULL)
	{
		mini->err_state = 1;
		ft_putstr_fd("exit\nAweboteShell: exit: too many arguments\n", 2);
	}
}

void	ft_exit(char **argv, t_minishell *mini)
{
	if (argv[0] == NULL)
	{
		ft_finish(mini);
		ft_putstr_fd("exit\n", 1);
		exit(EXIT_SUCCESS);
	}
	else
		ft_mod_exit(argv, mini);
}
