/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:14:57 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/10 11:06:04 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	long			time_to_die;
	long			time_to_sleep;
	long			time_to_eat;
	long			nbr_philo;
	long			nbr_eat_philo;
	long			timer_start;
	int				die;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	mutex_for_printf;
	pthread_mutex_t	mutex_for_die_check;
	pthread_mutex_t	mutex_for_eat_check;
	pthread_mutex_t	mutex_for_time;
	pthread_t		*thread;
}			t_philo;

typedef struct s_philo_data
{
	int				id;
	int				die;
	int				all_eat;
	long			eat;
	long			eat_time;
	long			sleep_time;
	long			die_time;
	long			philo_time_start;
	long			philo_time_end;
	t_philo			*philo;
}			t_philo_data;

void	*ft_philo(void *data);
void	check_die(t_philo_data *philo_data);
void	init_die(t_philo_data *philo_data);
void	thinking(t_philo_data *philo_data);
void	eat(t_philo_data *philo_data);
void	ft_sleep(t_philo_data *philo_data);
void	die(t_philo *philo, t_philo_data *philo_data, int i);
void	ft_lock_odd(t_philo_data *philo_data);
void	ft_all_die(t_philo *philo, t_philo_data *philo_data);
void	ft_printf(t_philo_data *philo_data, int i, long time);
void	ft_free(t_philo *thread, t_philo_data *philo_data);
void	ft_create_philo(t_philo *philo, t_philo_data *philo_data);
void	ft_all_eat(t_philo *philo, t_philo_data *philo_data);
void	ft_init_lock(t_philo_data *philo_data, int *right_fork, int *left_fork);
void	ft_init_philo_data(t_philo_data **philo_data, int i);
void	ft_time_fork(t_philo_data *philo_data, long time_fork);

int		ft_check_thread(t_philo *philo, t_philo_data *philo_data);
int		ft_init_struct(t_philo *philo, t_philo_data **philo_data,
			int argc, char **argv);
int		main(int argc, char **argv);
int		ft_check_argv(char *str);
int		ft_check(int argc, char **argv);
int		ft_init_mutex(t_philo *philo);
int		ft_init_thread(t_philo *philo);
int		ft_check_zero(char **argv);
int		ft_init_thread_data(t_philo *philo, t_philo_data **philo_data);
int		ft_check_die_value(t_philo_data *philo_data);
int		ck_eat_all(t_philo *philo, t_philo_data *philo_data);

long	ft_atol(char *str);
long	get_time(void);

#endif
