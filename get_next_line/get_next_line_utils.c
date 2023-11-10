/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:44:47 by marianof          #+#    #+#             */
/*   Updated: 2023/11/10 13:19:39 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	fullenght;
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = malloc(1);
	fullenght = (size_t)ft_strlen(s1) + (size_t)ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (fullenght + 1));
	if (!s3)
		return (NULL);
	while (s1[i])
		s3[i++] = s1[i];
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != (char)c)
	{
		if (!str[i])
			return (0);
		i++;
	}
	return (&str[i]);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size * count);
	while (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	ft_bzero(void *dst, size_t n)
{
	size_t					i;
	unsigned char			*ptr;

	if (n > 0)
	{
		ptr = (unsigned char *)dst;
		i = 0;
		while (i < n)
		{
			ptr[i] = '\0';
			i++;
		}
	}
}
