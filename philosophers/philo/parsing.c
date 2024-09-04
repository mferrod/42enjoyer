/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:50:34 by marianof          #+#    #+#             */
/*   Updated: 2024/09/04 16:40:29 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_param(char **argv, int argc, t_philosophers *philo)
{
	t_philo_param	*param;

	param = malloc(sizeof(t_philo_param *));
	param->number_of_philosophers = make_number(argv[1]);
	param->time_to_die = make_number(argv[2]);
	param->time_to_eat = make_number(argv[3]);
	param->time_to_sleep = make_number(argv[4]);
	if (argc == 5)
		param->number_of_times_each_philosopher_must_eat = make_number(
				argv[5]);
	else
		param->number_of_times_each_philosopher_must_eat = -1;
	if (param->number_of_philosophers == -500
		|| param->time_to_die == -500
		|| param->time_to_eat == -500
		|| param->time_to_sleep == -500
		|| param->number_of_times_each_philosopher_must_eat == -500)
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
