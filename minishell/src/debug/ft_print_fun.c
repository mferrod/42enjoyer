/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:18:45 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:18:46 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_print_list(t_env *list)
{
	while (list)
	{
		printf("Address %p, key %s, value %s, next %p\n", list, list->key,
			list->value, list->next);
		list = list->next;
	}
}

void	ft_print_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		printf("%s ~<br>\n", ptr[i]);
		i++;
	}
}
