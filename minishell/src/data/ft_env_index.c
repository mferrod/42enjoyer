/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:18:09 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:18:10 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/* void	ft_set_index(t_minishell *mini)
{
	t_env *head;

	while (mini->env_list)
	{
		ft_index(mini->env_list, head);
		mini->env_list = mini->env_list->next;
	}
}

void	ft_env_index(t_env *node, t_env *head)
{
	int		index;
	t_env	*aux;

	index = 0;
	aux = head;
	while (aux)
	{
		if (ft_strncmp(node->key, aux->key, ft_strlen(node->key)) > 0)
		aux = aux->next;
	}
} */
