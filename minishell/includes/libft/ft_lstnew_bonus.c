/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:34:04 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/01/22 12:11:07 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nodo;

	nodo = malloc(sizeof(*nodo));
	if (!nodo)
		return (0);
	nodo->content = content;
	nodo->next = NULL;
	return (nodo);
}
/* 
int	main(void)
{
	ft_lstnew("awebo");
} */