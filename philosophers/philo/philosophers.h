/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:19:20 by marianof          #+#    #+#             */
/*   Updated: 2024/09/05 19:13:47 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_philo_param
{
	int	n_philos;
	int	ttd;
	int	tte;
	int	tts;
	int	times_to_eat;
}		t_philo_param;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	int			eating;
	int			times_eaten;
	long		start_time;
	long		start_eating;
}				t_philo;

typedef struct s_global
{
	t_philo_param		*params;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	
}						t_global;

//PARSING
int	handle_param(char **argv, int argc, t_global *philo);
int	make_number(char *number);

//INITS


//UTILS
void	ft_sleep(size_t milliseconds);
long	get_current_time(void);
#endif
