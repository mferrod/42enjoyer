/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:21:57 by marianof          #+#    #+#             */
/*   Updated: 2024/09/11 20:28:34 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death_global(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_t);
	if (philo->table->death_flag == 1)
	{
		pthread_mutex_unlock(&philo->table->death_t);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->death_t);
	return (0);
}

int	check_times_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->num_food_t);
	if (philo->times_eaten == philo->table->times_to_eat)
	{
		pthread_mutex_unlock(&philo->num_food_t);
		return (1);
	}
	pthread_mutex_unlock(&philo->num_food_t);
	return (0);
}

int	init_threads(t_table *table)
{
	int	i;

	i = -1;
	if (table->n_philos == 1)
	{
		if (pthread_create(&table->philos[0].thread, NULL, one_philo,
				(void *)&table->philos[i]) != 0)
				return (error_msg("PHILOSOPHERS: ERROR CREATING ONE PHILO", table));
	}
	else
	{
		while (++i < table->n_philos)
		{		
			if (pthread_create(&table->philos[i].thread, NULL, philo_routine,
					(void *)&table->philos[i]) != 0)
				return (error_msg("PHILOSOPHERS: ERROR CREATING THREADS FOR PHILOS.",
					table));
		}
	}
	return (0);
}
