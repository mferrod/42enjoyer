/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:44:49 by marianof          #+#    #+#             */
/*   Updated: 2023/11/10 13:22:15 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*statica;

	return (ret);
}

char	*ft_readline(int fd, char *statica)
{
	int		readl;
	char	*temp;
	char	*aux;

	temp = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	readl = 1;
	while (!ft_strchr(temp, '\n') || readl >= 1)
	{
		readl = read(fd, temp, BUFFER_SIZE);
		if (readl < 1)
			return (free(temp), NULL);
		aux = statica;
		statica = ft_strjoin(statica, temp);
	}
	free(temp);
	return (statica);
}
