/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:41:53 by marianof          #+#    #+#             */
/*   Updated: 2024/09/12 16:51:30 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((philo->id % 2) == 0)
		usleep(100);
	while (check_death_global(philo) == 0)
	{
		if (check_death_global(philo) == 1 || (
				(philo->table->times_to_eat != -500
					&& philo->table->times_to_eat != -1)
				&& philo->table->times_to_eat <= philo->times_eaten))
			break ;
		forks_states(philo, 1);
		eat_routine(philo);
		forks_states(philo, 2);
		sleep_routine(philo);
		think_routine(philo);
	}
	return (NULL);
}

void	eat_routine(t_philo *philo)
{
	if (check_death_global(philo) == 1)
		return ;
	print_msg("is eating", philo);
	pthread_mutex_lock(&philo->last_food_t);
	philo->last_food = get_current_time() - philo->table->start_time;
	pthread_mutex_unlock(&philo->last_food_t);
	ft_sleep(philo->table->tte);
	pthread_mutex_lock(&philo->num_food_t);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->num_food_t);
}

void	sleep_routine(t_philo *philo)
{
	if (check_death_global(philo) == 1)
		return ;
	print_msg("is sleeping", philo);
	ft_sleep(philo->table->tts);
}

void	think_routine(t_philo *philo)
{
	if (check_death_global(philo) == 1)
		return ;
	print_msg("is thinking", philo);
}

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	print_msg("has taken a fork", philo);
	return (NULL);
}
