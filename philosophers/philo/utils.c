/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:17:14 by marianof          #+#    #+#             */
/*   Updated: 2024/09/10 19:31:01 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(long milliseconds)
{
	long	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		usleep(500);
	}
}

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_msg(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write_t);
	printf("[%ld] %d %s\n", get_current_time() - philo->table->start_time,
		philo->id, str);
	pthread_mutex_unlock(&philo->table->write_t);
}

void	forks_states(t_philo *philo, int i)
{
	if (i == 1)
	{
		pthread_mutex_lock(philo->r_fork);
		print_msg("has taken a fork", philo);
		pthread_mutex_lock(philo->l_fork);
		print_msg("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
}

int	create_joins(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philos)
	{
		if (pthread_join(&table->philos[i].thread, NULL))
			return (error_msg("PHILOSOPHERS: ERROR JOINING THREADS FOR PHILOS.",
					table));
	}
	return (0);
}
