/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:19:20 by marianof          #+#    #+#             */
/*   Updated: 2024/09/12 17:13:45 by marianof         ###   ########.fr       */
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

struct	s_philo;

typedef struct s_table
{
	int							n_philos;
	int							ttd; //Time to die
	int							tte; //Time to eat
	int							tts; //Time to sleep
	int							times_to_eat;
	struct s_philo				*philos;
	pthread_mutex_t				*forks;
	int							eating;
	long						start_time;
	int							death_flag;
	pthread_mutex_t				write_t;
	pthread_mutex_t				death_t;
}						t_table;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				times_eaten;
	long			last_food;
	int				alive;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	last_food_t;
	pthread_mutex_t	num_food_t;
	t_table			*table;
}					t_philo;

//PARSING
int		handle_param(char **argv, int argc, t_table *philo);
int		make_number(char *number);
int		check_times(t_table *table);

//INITS
int		init_forks(t_table *philosophers);
void	init_philos(t_philo *philo, int i, t_table *table);
int		init_global(t_table *table);
void	init_table(t_table *table);
int		create_joins(t_table *table);

//UTILS
void	ft_sleep(long milliseconds);
long	get_current_time(void);
void	print_msg(char *str, t_philo *philo);
void	forks_states(t_philo *philo, int i);
int		check_death_global(t_philo *philo);
int		check_times_eaten(t_philo *philo);
int		init_threads(t_table *table);

//ERRORS AND FREES
int		error_msg(char *str, t_table *table);
void	free_philos(t_philo *philo);
void	free_forks(pthread_mutex_t *forks);

//ROUTINES
void	*philo_routine(void *arg);
void	eat_routine(t_philo *philo);
void	sleep_routine(t_philo *philo);
void	think_routine(t_philo *philo);
void	*monitoring(void *arg);
int		check_death(t_philo *philo, long time);
void	*one_philo(void *arg);

#endif
