/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:18:14 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:30:52 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_env_values(t_minishell *mini)
{
	t_env	*aux;
	int		count;

	aux = mini->env_list;
	count = 0;
	while (aux)
	{
		if (aux->value)
			count++;
		aux = aux->next;
	}
	return (count);
}

char	*ft_env_str(char *s1, char *s2)
{
	char	*aux;
	char	*final;

	aux = ft_strjoin(s1, "=");
	if (!aux)
		return (NULL);
	final = ft_strjoin(aux, s2);
	free (aux);
	if (!final)
		return (NULL);
	return (final);
}

void	ft_create_env_ptr(t_minishell *mini)
{
	t_env	*aux;
	char	**ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char *) * (ft_env_values(mini) + 1));
	if (!ptr)
		ft_error(mini, "Malloc error\n");
	aux = mini->env_list;
	while (aux)
	{
		if (aux->value)
		{
			ptr[i] = ft_env_str(aux->key, aux->value);
			if (ptr[i] == NULL)
			{
				ft_free_double(ptr);
				ft_error(mini, "Malloc error\n");
			}
			i++;
		}
		aux = aux->next;
	}
	ptr[i] = NULL;
	mini->envp = ptr;
}

void	ft_update_env_ptr(t_minishell *mini)
{
	if (mini->envp)
		ft_free_double(mini->envp);
	ft_create_env_ptr(mini);
}
