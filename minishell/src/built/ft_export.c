/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:17:52 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 13:34:34 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_export(char **args, t_minishell *mini)
{
	int		i;
	char	*key;
	char	*value;
	int		len;

	i = 0;
	if (!args[i])
		return (ft_print_export(mini));
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
		{
			len = ft_strlen(args[i]) - ft_strlen(ft_strchr(args[i], '='));
			key = ft_substr(args[i], 0, len);
			value = ft_strdup(ft_strchr(args[i], '=') + 1);
			ft_create_var(mini, key, value);
		}
		else
			ft_create_var(mini, ft_strdup(args[i]), NULL);
		i++;
	}
	mini->err_state = 0;
}

void	ft_create_var(t_minishell *mini, char *key, char *value)
{
	t_env	*head;
	t_env	*new;

	head = mini->env_list;
	new = ft_find_node(key, mini);
	if (new)
	{
		if (value)
		{
			free(new->value);
			new->value = value;
		}
	}
	else
	{
		while (head->next)
			head = head->next;
		head->next = ft_new_node(key, value);
	}
	ft_update_env_ptr(mini);
}

void	ft_print_export(t_minishell	*mini)
{
	t_env	*aux;

	aux = mini->env_list;
	while (aux)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(aux->key, 1);
		if (aux->value)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(aux->value, 1);
			ft_putchar_fd('"', 1);
		}
		ft_putchar_fd('\n', 1);
		aux = aux->next;
	}
}
