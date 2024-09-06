/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:25:11 by marianof          #+#    #+#             */
/*   Updated: 2024/09/06 15:56:13 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(t_philo *philo, int i, t_table *table)
{
	philo->id = i + 1;
	philo->r_fork = &table->forks[i];
	philo->l_fork = &table->forks[i + 1 % table->n_philos];
	pthread_mutex_init(&philo->last_food_t, NULL);
	pthread_mutex_init(&philo->num_food_t, NULL);
	philo->table = table;
}

void	init_forks(t_table *table)
{
	int	i;

	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->n_philos);
	if (!table->forks)
		return ;
	i = -1;
	table->start_time = get_current_time();
	while (++i < table->n_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			error_msg("PHILOSOPHERS: ERROR CREATING FORKS.");
			return ;
		}
	}
}

void	create_threads(t_table *table)
{
	int	i;

	i = -1;
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->n_philos);
	if (!table->philos)
		return ;
	while (++i < table->n_philos)
		init_philos(&table->philos[i], i, table);
	i = -1;
	while (++i < table->n_philos)
	{
		if (pthread_create(&table->philos[i], NULL, &philo_routine,
				(void *)&table->philos[i]) != 0)
		{
			error_msg("PHILOSOPHERS: ERROR CREATING THREADS FOR PHILOS.");
		}
	}
}
