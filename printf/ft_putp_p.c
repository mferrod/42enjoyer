/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:25:34 by marianof          #+#    #+#             */
/*   Updated: 2023/11/03 13:29:29 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp_p(unsigned long punt)
{
	if (!punt)
		return (ft_putstr_p("0x0"));
	return (ft_putstr_p("0x") + ft_puthexmin_p(punt));
}
