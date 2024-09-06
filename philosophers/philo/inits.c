/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:25:11 by marianof          #+#    #+#             */
/*   Updated: 2024/09/05 19:19:07 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philos(t_global *philosophers)
{
	int i;

	i = 0;
	philosophers->philos = malloc(sizeof(t_philo) * 
		philosophers->params->n_philos);
	while (i <= philosophers->params->n_philos)
	{
		
	}
	
}

void	init_forks(t_global *philosophers)
{
	int	i;

	philosophers->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 
		philosophers->params->n_philos);
	if (!philosophers->forks)
		return ;
	i = -1;
	while (++i < philosophers->params->n_philos)
	{
		if (pthread_mutex_init(&philosophers->forks[i], NULL) != 0)
		{
			return ;
		}
	}
}
