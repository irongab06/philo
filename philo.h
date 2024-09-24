/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:14:57 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/24 12:22:22 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo
{
	long	time_to_die;
	long	time_to_sleep;
	long	time_to_eat;
	long	nbr_philo;
	long	nbr_eat_philo;
	pthread_mutex_t	*mutex;
	pthread_t	*thread;
}			t_philo;

int	ft_init_struct(t_philo *philo, int argc, char **argv);
int	main(int	argc, char **argv);
int	ft_check_argv(char *str);
int	ft_check(int argc, char **argv);
int	ft_init_mutex(t_philo *philo);
int	ft_init_thread(t_philo *philo);

long ft_atol(char *str);

#endif
