/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:44 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:21:45 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	new_handler(int sig)
{
	if (sig == SIGINT)
		ctrl_c_hd(sig);
}

static void	handle_ctrl_c(t_minishell *mini)
{
	struct sigaction	new_act;

	new_act.sa_handler = &new_handler;
	new_act.sa_flags = SA_RESTART;
	sigemptyset(&new_act.sa_mask);
	if (sigaction(SIGINT, &new_act, NULL) == -1)
		ft_error_minishell("Error: sigaction", mini, 1);
}

static void	wait_hd(t_token *tok, t_cmd *cmd, t_minishell *shl, int fd)
{
	int	stat;

	waitpid(0, &stat, 0);
	if (WEXITSTATUS(stat) == 130)
	{
		cmd->err = 1;
		shl->err_state = 130;
	}
	else if (WEXITSTATUS(stat) == 1)
	{
		ft_putstr_fd(HEDC_CD, 1);
		ft_putstr_fd(tok->str, 1);
		ft_putendl_fd("')", 1);
	}
	close(fd);
	cmd->fd_in = open(".heredoc.tmp", O_RDONLY);
}

void	ft_hd_scnd(char *str, t_cmd *cmd, t_minishell *shl, int fd)
{
	char	*line;
	int		len;

	len = ft_strlen(str);
	line = readline("> ");
	while (line)
	{
		if (ft_strncmp(line, str, len) == 0 && !line[len])
		{
			free(line);
			break ;
		}
		line = expand_heredoc(line, shl);
		if (line)
		{
			ft_putendl_fd(line, fd);
			free(line);
		}
		line = readline("> ");
	}
	if (!line)
		free_exit_hd(shl, cmd, 1);
	free_exit_hd(shl, cmd, 0);
}

void	ft_heredoc_init(t_minishell *msh, t_cmd *cmd, t_token **tkn)
{
	pid_t	pid;
	int		fd;

	*tkn = (*tkn)->next;
	if (cmd->err == 0)
	{
		if (cmd->fd_in > 2)
			close(cmd->fd_in);
		fd = open(".heredoc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		g_mini_signal = 2;
		pid = fork();
		if (pid == 0)
		{
			handle_ctrl_c(msh);
			ft_hd_scnd((*tkn)->str, cmd, msh, fd);
		}
		else
			wait_hd(*tkn, cmd, msh, fd);
		g_mini_signal = 0;
	}
	*tkn = (*tkn)->next;
}
