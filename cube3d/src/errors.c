/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:35:05 by marianof          #+#    #+#             */
/*   Updated: 2025/04/24 17:28:29 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	error_and_free(void *c)
{
	write(2, "ERROR.\n", 7);
	if (c)
		free(c);
	exit(1);
}

void	error_and_finish(t_data *list, char *txt)
{
	if (txt)
		printf("%s\n", txt);
	free_all(list);
	exit(1);
}
