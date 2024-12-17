/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:22:12 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:22:13 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*ft_find_node(char *key, t_minishell *mini)
{
	t_env	*tmp;

	tmp = mini->env_list;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(key))
			&& (ft_strlen(key) == ft_strlen(tmp->key)))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*ft_get_env(t_env **env, char *search)
{
	t_env	*aux;

	aux = *env;
	while (aux && ft_strncmp(aux->key, search, ft_strlen(search)) != 0)
		aux = aux->next;
	if (aux != NULL)
		return (aux->value);
	return (" ");
}
