/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:14:36 by marianof          #+#    #+#             */
/*   Updated: 2023/10/17 10:21:13 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ulti;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			ulti = lst;
		lst = lst->next;
	}
	return (ulti);
}
