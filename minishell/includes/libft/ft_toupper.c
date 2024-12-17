/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:23:17 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/04/25 14:27:01 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c > 96 && c < 123))
		return (c - 32);
	return (c);
}

/* 
int main(void)
{
    char letra;

    letra = 'a';
    printf("%d", ft_toupper(letra));
	ft_isalpha(letra);
    return (0);
} */