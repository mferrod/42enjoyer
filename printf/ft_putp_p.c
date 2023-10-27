/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:19:42 by marianof          #+#    #+#             */
/*   Updated: 2023/10/27 14:40:21 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp_p(unsigned long punt)
{
	if (!punt)
		return (ft_putstr_p("0x0"));
	return (ft_putstr_p("0x") + ft_puthexmin_p(punt));
}
