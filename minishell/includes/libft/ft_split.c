/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:42:38 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/04/29 18:46:07 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char const *s, char c)
{
	int	w_count;
	int	i;
	int	is_word;

	w_count = 0;
	i = 0;
	is_word = 1;
	while (s[i])
	{
		if (s[i] == c)
			is_word = 1;
		else if (s[i] != c && is_word)
		{
			is_word = 0;
			w_count++;
		}
		i++;
	}
	return (w_count);
}

static void	ft_free_double(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		put;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (words(s, c) + 1));
	if (!ret)
		return (0);
	(free(0), put = 0, i = 0, j = 0);
	while (put < words(s, c))
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != 0 && s[i] != c)
			i++;
		ret[put] = ft_substr(s, j, i - j);
		if (!ret[put])
			return (ft_free_double(ret), NULL);
		put++;
	}
	ret[put] = NULL;
	return (ret);
}
