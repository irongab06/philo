/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:14:57 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/26 16:55:00 by gacavali         ###   ########.fr       */
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
	long	timer_start;
	int		die;
	pthread_mutex_t	*mutex;
	pthread_mutex_t mutex_for_die;
	pthread_mutex_t mutex_for_printf;
	pthread_t	*thread;
	pthread_t	check_thread;
	t_philo_data	*philo_data;
}			t_philo;

typedef struct s_philo_data
{
	int		id;
	int		die;
	long	eat_time;
	long	sleep_time;
	long	die_time;
	long	philo_time_start;
	long	philo_time_end;
	t_philo *philo;
}			t_philo_data;


void	*ft_philo(void *data);
void	check_die(t_philo_data *philo_data);
void	init_die(t_philo_data *philo_data);
void	thinking(t_philo_data *philo_data);
void	eat(t_philo_data *philo_data);
void	sleep(t_philo_data *philo_data);
void	ft_check_thread(void *data);
void	die(t_philo *philo, int i);
void	ft_lock_odd(t_philo_data *philo_data);

int	ft_init_struct(t_philo *philo, t_philo_data **philo_data, int argc, char **argv);
int	main(int	argc, char **argv);
int	ft_check_argv(char *str);
int	ft_check(int argc, char **argv);
int	ft_init_mutex(t_philo *philo);
int	ft_init_thread(t_philo *philo);
int	ft_check_zero(t_philo *philo, int argc);
int	ft_init_thread_data(t_philo *philo, t_philo_data **philo_data);

long ft_atol(char *str);
long	get_time(void);

#endif
