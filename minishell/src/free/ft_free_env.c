/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:17 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:21:18 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_free_env(t_minishell *minishell)
{
	t_env	*tmp;
	char	*str;

	while (minishell->env_list)
	{
		str = minishell->env_list->key;
		minishell->env_list->key = NULL;
		free(str);
		str = minishell->env_list->value;
		minishell->env_list->value = NULL;
		free(str);
		tmp = minishell->env_list;
		minishell->env_list = minishell->env_list->next;
		free(tmp);
	}
	if (minishell->home)
		free(minishell->home);
	if (minishell->envp)
		ft_free_double(minishell->envp);
	if (minishell->location)
		free(minishell->location);
	minishell->home = NULL;
	minishell->envp = NULL;
	minishell->location = NULL;
}
