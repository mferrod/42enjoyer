/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:44:49 by marianof          #+#    #+#             */
/*   Updated: 2023/11/22 12:13:07 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_give_line(char *line)
{
	char	*c;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	c = malloc((sizeof(char) * i) + 1);
	if (!c)
		return (NULL);
	while (k < i)
	{
		c[k] = line[k];
		k++;
	}
	c[i] = '\0';
	free(line);
	return (c);
}

char	*ft_readline(int fd, char *statica)
{
	int		readl;
	char	*temp;
	char	*aux;

	temp = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!temp)
		return (NULL);
	readl = 1;
	while (!ft_strchr(temp, '\n') || readl >= 1)
	{
		readl = read(fd, temp, BUFFER_SIZE);
		if (readl < 0)
			return (free(temp), NULL);
		aux = statica;
		statica = ft_strjoin(statica, temp, (size_t)readl);
	}
	free(temp);
	return (statica);
}

char	*ft_clnbuf(char *cleanme)
{
	char	*c;
	int		k;
	int		i;

	i = 0;
	k = ft_strlen(cleanme) - (ft_strlen(ft_strchr(cleanme, '\n')) + 2);
	while (cleanme[k])
	{
		c[i] = cleanme[k];
		k++;
	}
	free(cleanme);
	return (c);
}

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
	statica = ft_readline(fd, statica);
	if (!statica)
		return (NULL);
	ret = ft_give_line(statica);
	statica = ft_clnbuf(statica);
	return (ret);
}

int	main(void)
{
	int		c;
	char	*as;
	char	*l = "Kaksjaksjkasjkajs\nkjksdkad";

	c = open("txt.txt", O_RDONLY);
	ft_clnbuf(l);
	as = get_next_line(c);
	printf("%s", as);
	close(c);
	return (0);
}
//05880
