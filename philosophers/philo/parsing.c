/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:50:34 by marianof          #+#    #+#             */
/*   Updated: 2024/09/05 19:14:36 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_param(char **argv, int argc, t_global *philo)
{
	t_philo_param	*param;

	param = malloc(sizeof(t_philo_param *));
	param->n_philos = make_number(argv[1]);
	param->ttd = make_number(argv[2]);
	param->tte = make_number(argv[3]);
	param->tts = make_number(argv[4]);
	if (argc == 5)
		param->times_to_eat = make_number(
				argv[5]);
	else
		param->times_to_eat = -1;
	if (param->n_philos == -500
		|| param->ttd == -500
		|| param->tte == -500
		|| param->tts == -500
		|| param->times_to_eat == -500)
		return (-1);
	philo->params = param;
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
	return (to_ret);
}
