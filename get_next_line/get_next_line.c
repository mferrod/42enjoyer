/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:44:49 by marianof          #+#    #+#             */
/*   Updated: 2023/11/15 10:38:35 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*statica;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(statica);
		statica = NULL;
		return (statica);
	}
	statica = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!statica)
		return (NULL);
	ret = ft_readline(fd, statica);
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
		statica = ft_strjoin(statica, temp, (size_t)readl);
	}
	free(temp);
	printf("%s", statica);
	return (statica);
}

int	main(void)
{
	int		c;
	char	*as;

	c = open("txt.txt", O_RDONLY);
	as = get_next_line(c);
	printf("%s", as);
	close(c);
	return (0);
}
//05880