/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:19:20 by marianof          #+#    #+#             */
/*   Updated: 2024/09/06 13:11:00 by marianof         ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				times_eaten;
	long			start_eating;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	last_food_t;
	pthread_mutex_t	num_food_t;
	t_table			*table;
}					t_philo;

typedef struct s_table
{
	int					n_philos;
	int					ttd;
	int					tte;
	int					tts;
	int					times_to_eat;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	int					eating;
	long				start_time;
}						t_table;

//PARSING
int		handle_param(char **argv, int argc, t_table *philo);
int		make_number(char *number);

//INITS
void	init_forks(t_table *philosophers);
void	init_philos(t_philo *philo, int i, t_table *table);
//UTILS
void	ft_sleep(long milliseconds);
long	get_current_time(void);
void	error_msg(char *str);
#endif
