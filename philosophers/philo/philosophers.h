/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:19:20 by marianof          #+#    #+#             */
/*   Updated: 2024/09/04 17:00:05 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> 

typedef struct s_philo_param
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}		t_philo_param;

typedef struct s_philo
{
	t_philo_param	*params;
}							t_philosophers;

//PARSING
int	handle_param(char **argv, int argc, t_philosophers *philo);
int	make_number(char *number);
#endif
