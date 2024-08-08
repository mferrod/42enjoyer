/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:40:48 by marianof          #+#    #+#             */
/*   Updated: 2023/10/17 10:21:20 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*listtemp;

	if (lst)
	{
		while (*lst)
		{
			listtemp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = listtemp;
		}
	}
}
