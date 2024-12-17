/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:22:00 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:22:01 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_suppress_output(void)
{
	struct termios	termios_p;

	if (isatty(0))
	{
		if (tcgetattr(0, &termios_p) != 0)
			perror("Minishell: tcgetattr");
		termios_p.c_lflag &= ~(ECHONL | ECHOCTL);
		if (tcsetattr(0, TCSANOW, &termios_p) != 0)
			perror("Minishell: tcsetattr");
	}
}

void	ft_handle_sigint(int sig)
{
	(void)sig;
	if (g_mini_signal == 0)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
		ft_putstr_fd("\n", 1);
}

void	ft_handle_sigquit(int sig)
{
	(void)sig;
	if (g_mini_signal == 0)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
		ft_putstr_fd("Quit (core dumped)\n", 1);
}
