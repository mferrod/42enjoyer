/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:18:52 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:32:19 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_error_minishell(char *msg, t_minishell *shell, int err_state)
{
	ft_putstr_fd(SHLL_NAME, 2);
	ft_putendl_fd(msg, 2);
	shell->err_state = err_state;
}

void	ft_open_errors(char *err_msg, char *err_name)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(err_name, 2);
	ft_putstr_fd(":", 2);
	ft_putendl_fd(err_msg, 2);
}
