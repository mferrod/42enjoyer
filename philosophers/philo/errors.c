/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:09 by marianof          #+#    #+#             */
/*   Updated: 2024/09/10 19:35:58 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_msg(char *str, t_table *table)
{
	printf("%s\n", str);
	if (table->philos)
		free_philos(table->philos);
	if (table->forks)
		free(table->forks);
}

void	free_philos(t_philo *philo)
{
	int	i;

	i = 0;
	while (&philo[i])
	{
		pthread_mutex_destroy(philo->l_fork);
		pthread_mutex_destroy(philo->r_fork);
		pthread_mutex_destroy(&philo->last_food_t);
		pthread_mutex_destroy(&philo->num_food_t);
		i++;
	}
	free(philo);
}

void	free_forks(pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	while (&forks[++i])
		pthread_mutex_destroy(&forks[i]);
	free(forks);
}
