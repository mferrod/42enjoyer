/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:22:53 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 15:09:00 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_mini_signal;

int	main(int argc, char **argv, char **env)
{
	t_minishell	minishell;
	char		*line;

	if (!env[0])
		ft_error(NULL, "ENV NOT FOUND");
	ft_start(env, &minishell);
	while (argc && argv)
	{
		line = readline(ft_location(&minishell));
		if (!line)
			break ;
		minishell.tokens = ft_data_entry(line, &minishell);
		if (ft_strlen(line))
			add_history(line);
		free(line);
		if (ft_check_nodes(&minishell) == 0)
		{
			ft_cmd_creator(&minishell);
			ft_eggsecutor(&minishell);
		}
		ft_reboot(&minishell);
	}
	ft_error(&minishell, NULL);
	return (0);
}
