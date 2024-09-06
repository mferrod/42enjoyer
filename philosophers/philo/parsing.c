/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:50:34 by marianof          #+#    #+#             */
/*   Updated: 2024/09/06 12:37:18 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_param(char **argv, int argc, t_table *table)
{
	table = malloc(sizeof(t_table *));
	table->n_philos = make_number(argv[1]);
	table->ttd = make_number(argv[2]);
	table->tte = make_number(argv[3]);
	table->tts = make_number(argv[4]);
	if (argc == 5)
		table->times_to_eat = make_number(
				argv[5]);
	else
		table->times_to_eat = -1;
	if (table->n_philos == -500
		|| table->ttd == -500
		|| table->tte == -500
		|| table->tts == -500
		|| table->times_to_eat == -500)
		return (-1);
	return (0);
}

int	make_number(char *number)
{
	int	i;
	int	to_ret;

	i = 0;
	to_ret = 0;
	while (number[i])
	{
		if (number[i] >= '0' && number[i] <= '9')
			to_ret = to_ret * 10 + (number[i] - '0');
		else
			return (-500);
		i++;
	}
	if (to_ret > INT_MAX)
		return (-500);
	return (to_ret);
}
