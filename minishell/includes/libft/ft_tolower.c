/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:26:36 by ijerruz-          #+#    #+#             */
/*   Updated: 2023/11/30 14:20:32 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c > 64 && c < 91))
		return (c + 32);
	return (c);
}
/*
int main(void)
{
    char letra;

    letra = 'a';
    printf("%d", ft_tolower(letra));
    return (0);
}*/