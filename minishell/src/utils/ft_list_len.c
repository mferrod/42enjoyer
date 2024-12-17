/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:22:15 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:35:33 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_cmd_len(t_minishell *mini)
{
	int		count;
	t_cmd	*aux;

	count = 0;
	aux = mini->cmds;
	while (aux)
	{
		count++;
		aux = aux->next;
	}
	return (count);
}

int	ft_env_len(t_minishell *mini)
{
	int		count;
	t_env	*aux;

	count = 0;
	aux = mini->env_list;
	while (aux)
	{
		count++;
		aux = aux->next;
	}
	return (count);
}
