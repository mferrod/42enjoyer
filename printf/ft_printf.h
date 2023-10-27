/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:19:26 by marianof          #+#    #+#             */
/*   Updated: 2023/10/27 13:38:52 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				ft_putchar_p(int c);
int				ft_putstr_p(char *str);
int				ft_putnbr_p(int n);
unsigned int	ft_putnbr_un_p(unsigned int n);
int				ft_puthexmay_p(unsigned long n);
int				ft_puthexmin_p(unsigned long n);
#endif
