/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:44:49 by marianof          #+#    #+#             */
/*   Updated: 2024/08/01 13:25:25 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

char	*ft_read(int fd, char *estatic)
{
	int		nbytes;
	char	*buffer;

	nbytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(estatic));
	buffer[0] = '\0';
	while (nbytes > 0 && !ft_strchr(buffer, '\n'))
	{
		nbytes = read (fd, buffer, BUFFER_SIZE);
		if (nbytes > 0)
		{
			buffer[nbytes] = '\0';
			estatic = ft_strjoin(estatic, buffer);
		}
	}
	free(buffer);
	if (nbytes == -1)
		return (ft_free(estatic));
	return (estatic);
}

char	*ft_get_line(char *estatic)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(estatic, '\n');
	len = (ptr - estatic) + 1;
	line = ft_substr(estatic, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_new_estatic(char *estatic)
{
	char	*new_estatic;
	char	*ptr;
	int		len;

	ptr = ft_strchr(estatic, '\n');
	if (!ptr)
	{
		new_estatic = NULL;
		return (ft_free(estatic));
	}
	else
		len = (ptr - estatic) + 1;
	if (!estatic[len])
		return (ft_free(estatic));
	new_estatic = ft_substr(estatic, len, ft_strlen(estatic) - len);
	ft_free(estatic);
	if (!new_estatic)
		return (NULL);
	return (new_estatic);
}

char	*get_next_line(int fd)
{
	static char	*estatic;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(estatic));
	estatic = ft_read(fd, estatic);
	if (!estatic)
		return (NULL);
	line = ft_get_line(estatic);
	if (!line)
		return (ft_free(estatic));
	estatic = ft_new_estatic(estatic);
	return (line);
}
