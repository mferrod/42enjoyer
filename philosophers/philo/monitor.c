/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:50:23 by marianof          #+#    #+#             */
/*   Updated: 2024/09/11 20:09:23 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitoring(void *arg)
{
	t_philo	*philos;
	int		i;
	long	time;

	philos = (t_philo *) arg;
	while (philos->table->death_flag != 1)
	{
		i = -1;
		while (++i < philos->table->n_philos)
		{
			time = get_current_time() - philos->table->start_time;
			if (check_death(&philos[i], time) == 1 || 
				check_times_eaten(&philos[i]) == 1)
				return NULL;
		}
		usleep(50);
	}
	return NULL;
}

int	check_death(t_philo *philo, long time)
{
	pthread_mutex_lock(&philo->last_food_t);
	if (philo->table->ttd < (time - philo->last_food))
	{
		print_msg("died", philo);
		philo->alive = 0;
		pthread_mutex_lock(&philo->table->death_t);
		philo->table->death_flag = 1;
		pthread_mutex_unlock(&philo->table->death_t);
		pthread_mutex_unlock(&philo->last_food_t);
		return (1);
	}
	pthread_mutex_unlock(&philo->last_food_t);
	return (0);
}