/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shellevel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:18:19 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:18:20 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_set_shellevel(t_minishell *mini)
{
	int		n;
	t_env	*aux;

	aux = mini->env_list;
	if (!aux)
		ft_error(mini, "Could not set SHLVL");
	while (aux)
	{
		if (ft_strncmp(aux->key, "SHLVL", 5) == 0)
		{
			n = ft_atoi(aux->value) + 1;
			free(aux->value);
			aux->value = ft_itoa(n);
			break ;
		}
		aux = aux->next;
	}
}
