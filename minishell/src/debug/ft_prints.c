/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:18:48 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:18:49 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_print_env(t_env *list)
{
	t_env	*aux;

	aux = list;
	while (aux)
	{
		printf("Address %p, key %s, value %s, next %p\n", aux, aux->key,
			aux->value, aux->next);
		aux = aux->next;
	}
}

void	ft_print_tokens(t_token *list)
{
	t_token	*aux;

	aux = list;
	while (aux)
	{
		printf("ID: %d\t STRING: %s\t JOIN: %d \t TYPE: %d\n", aux->id,
			aux->str, aux->join, aux->type);
		aux = aux->next;
	}
}

void	ft_print_cmds(t_cmd *list)
{
	t_cmd	*aux;
	int		i;

	aux = list;
	while (aux != NULL)
	{
		i = 0;
		while (aux->argv[i])
		{
			printf("ID: %d\t STRING: %s\t FD_IN: %d \t FD_OUT: %d\n",
				aux->id, aux->argv[i], aux->fd_in, aux->fd_out);
			i++;
		}
		aux = aux->next;
	}
}
