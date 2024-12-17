/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:17:40 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 02:06:34 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_isflag1(char *str)
{
	return (ft_strlen(str) == 2 && !ft_strncmp(str, "-n", 2));
}

int	ft_isflag2(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_echo(char **args, t_minishell *mini)
{
	int	br;
	int	i;

	br = 1;
	i = 0;
	while (args[i] && (ft_isflag1(args[i]) || ft_isflag2(args[i])))
	{
		i++;
		br = 0;
	}
	while (args[i] && ft_strlen(args[i]) > 0)
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (br)
		ft_putchar_fd('\n', 1);
	mini->err_state = 0;
}
