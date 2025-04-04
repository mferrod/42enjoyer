/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:25:11 by marianof          #+#    #+#             */
/*   Updated: 2024/09/12 16:50:26 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(t_philo *philo, int i, t_table *table)
{
	philo->id = i + 1;
	philo->r_fork = &table->forks[i];
	philo->l_fork = &table->forks[(i + 1) % table->n_philos];
	philo->last_food = 0;
	philo->times_eaten = 0;
	pthread_mutex_init(&philo->last_food_t, NULL);
	pthread_mutex_init(&philo->num_food_t, NULL);
	philo->table = table;
}

int	init_forks(t_table *table)
{
	int	i;

	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->n_philos);
	if (!table->forks)
		return (error_msg("PHILOSOPHERS: ERROR ON FORKS MALLOC", table));
	i = -1;
	while (++i < table->n_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (error_msg("PHILOSOPHERS: ERROR CREATING FORKS.", table));
	}
	return (0);
}

int	create_threads(t_table *table)
{
	pthread_t	monitor;
	int			i;

	i = -1;
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->n_philos);
	if (!table->philos)
		return (error_msg("PHILOSOPHERS: ERROR ON PHILOS MALLOC", table));
	while (++i < table->n_philos)
		init_philos(&table->philos[i], i, table);
	table->start_time = get_current_time();
	if (pthread_create(&monitor, NULL, monitoring, (void *)table->philos) != 0)
		return (error_msg("PHILOSOPHERS: ERROR CREATING MONITOR", table));
	if (init_threads(table) == 1)
		return (1);
	if (pthread_join(monitor, NULL))
		return (error_msg("PHILOSOPHERS: ERROR JOINING MONITOR", table));
	return (0);
}

int	init_global(t_table *table)
{
	if (init_forks(table) == 1)
		return (1);
	if (create_threads(table) == 1)
		return (1);
	if (create_joins(table) == 1)
		return (1);
	return (0);
}

void	init_table(t_table *table)
{
	table->tte = 0;
	table->tts = 0;
	table->ttd = 0;
	table->times_to_eat = 0;
	table->start_time = 0;
	table->n_philos = 0 ;
	table->eating = 0;
	table->death_flag = 0;
	pthread_mutex_init(&table->write_t, NULL);
	pthread_mutex_init(&table->death_t, NULL);
}
