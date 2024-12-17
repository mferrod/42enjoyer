/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:11:54 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/01/09 20:39:13 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if ((char *)src < (char *)dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((char *)dst)[i] = ((char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/* 
int main()
{
   char src[30]  = "hello world";

   printf("Before dst = %s\n", &src[6]);
   printf("Before src = %s\n", &src[0]);
   ft_memmove(&src[6], &src[0], 12);
   printf("Before dst = %s\n", &src[6]);
   printf("Before src = %s\n", &src[0]);

   return(0);
} */