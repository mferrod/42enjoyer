/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:41:53 by marianof          #+#    #+#             */
/*   Updated: 2024/09/11 17:04:36 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((philo->id % 2) == 0)
		usleep(100);
	while (philo->table->death_flag == 0)
	{
 		if (philo->table->death_flag == 1 || (
			(philo->table->times_to_eat != -500 && philo->table->times_to_eat != -1)
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
	print_msg("is eating", philo);
	ft_sleep(philo->table->tte);
	pthread_mutex_lock(&philo->last_food_t);
	philo->last_food = get_current_time() - philo->table->start_time;
	pthread_mutex_unlock(&philo->last_food_t);
	pthread_mutex_lock(&philo->num_food_t);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->num_food_t);
}

void	sleep_routine(t_philo *philo)
{
	print_msg("is sleeping", philo);
	ft_sleep(philo->table->tts);
}

void	think_routine(t_philo *philo)
{
	print_msg("is thinking", philo);
}
