/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:18:16 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:18:17 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*ft_new_node(char *key, char *value)
{
	t_env	*new;

	if (!key)
		return (NULL);
	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = key;
	if (value)
		new->value = value;
	else
		new->value = NULL;
	new->next = NULL;
	return (new);
}

void	ft_save_env(t_minishell *minishell, char **envp)
{
	int		i;
	int		index;
	t_env	*head;
	t_env	*aux;

	index = -1;
	i = 1;
	index = ft_find_char(envp[0], '=');
	head = ft_new_node(ft_substr(envp[0], 0, index), ft_substr(envp[0], index
				+ 1, ft_strlen(envp[0])));
	if (!head)
		ft_error(minishell, "Error saving environment");
	minishell->env_list = head;
	while (envp[i])
	{
		index = ft_find_char(envp[i], '=');
		aux = ft_new_node(ft_substr(envp[i], 0, index), ft_substr(envp[i], index
					+ 1, ft_strlen(envp[i])));
		if (!aux)
			ft_error(minishell, "Error saving environment");
		head->next = aux;
		head = head->next;
		i++;
	}
}

int	ft_find_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
