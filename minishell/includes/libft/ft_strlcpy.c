/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:07:33 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/01/09 17:28:41 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != 0 && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}
/* 
int main(void)
{
    char    origen[] = "holawewo";
    char    destino[10] = "adios";
	char    destino2[10] = "adios";

    printf("%s\n", origen);
    printf("%s\n", destino);
	printf("%s\n", destino2);
    //ft_strlcpy(destino, &origen[2], 3);
    
    printf("%zu\n", ft_strlcpy(destino, origen, 2));
	printf("%zu\n", strlcpy(destino2, origen, 2));

	printf("%s\n", origen);
    printf("%s\n", destino);
	printf("%s\n", destino2);
    return (0);
} */