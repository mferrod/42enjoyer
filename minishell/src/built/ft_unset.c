/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:17:59 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 02:08:59 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_free_env_node(t_env *node)
{
	if (node == NULL)
		return (0);
	free(node->key);
	if (node->value)
		free(node->value);
	free(node);
	return (1);
}

void	ft_try_unset(char *key, t_minishell *mini)
{
	t_env	*aux;
	t_env	*prev;
	t_env	*delete;
	int		first_node;

	first_node = 1;
	delete = ft_find_node(key, mini);
	aux = mini->env_list;
	while (aux)
	{
		if (aux == delete)
		{
			if (first_node)
				mini->env_list = delete->next;
			else
				prev->next = delete->next;
			ft_free_env_node(delete);
			return ;
		}
		first_node = 0;
		prev = aux;
		aux = aux->next;
	}
}

void	ft_unset(char **args, t_minishell *mini)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (ft_find_node(args[i], mini) != NULL)
			ft_try_unset(args[i], mini);
		i++;
	}
	ft_update_env_ptr(mini);
	mini->err_state = 0;
}
