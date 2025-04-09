/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:34:35 by marianof          #+#    #+#             */
/*   Updated: 2025/04/09 16:03:13 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	find_char(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != (char)c)
	{
		if (!str[i])
			return (-1);
		i++;
	}
	return (i);
}

int	*parse_numbers(t_data *data, char *param)
{
	char **sp;
	int	*ret;
	int	i;

	i = 0;
	ret = (int *)malloc(sizeof(int));
	if (!ret)
		return (NULL);
	sp = ft_split(param, ',');
	if (!sp)
		error_and_finish(data, NULL);
	if (ft_arraylen(sp) != 3)
		error_and_finish(data, NULL);
	while (sp[i])
	{
		ret[i] = ft_atoi(sp[i]);
		if (ret[i] < 0 && ret[i] > 255)
		{
			sp = free_matrix(sp);
			free(ret);
			error_and_finish(data, "Error: Incorrect value for colors.");
		}
		i++;
	}
	return (ret);
}
