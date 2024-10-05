/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:38:26 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/04 10:58:06 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	thinking(t_philo_data *philo_data)
{
	long	time_thinking;

	pthread_mutex_lock(&philo_data->philo->mutex_for_time);
	time_thinking = get_time();
	time_thinking -= philo_data->philo->timer_start;
	pthread_mutex_unlock(&philo_data->philo->mutex_for_time);
	ft_printf(philo_data, 0, time_thinking);
	//usleep(20);
	return ;
}

void ft_usleep(t_philo_data *philo_data, int i)
{
	long time;
	long tmp;

	if (i == 1)
		time = get_time() + philo_data->philo->time_to_eat;
	if (i == 2)
		time = get_time() + philo_data->philo->time_to_sleep;
	tmp = get_time();
	while(tmp < time)
	{
		if ((ft_check_die_value(philo_data)) > 0)
			return ;
		usleep(100);
		tmp = get_time();
	}
}

void	eat(t_philo_data *philo_data)
{
	long	time_eat;
	long	time_now;

	pthread_mutex_lock(&philo_data->philo->mutex_for_time);
	time_now = get_time();
	time_eat = time_now - philo_data->philo->timer_start;
	pthread_mutex_unlock(&philo_data->philo->mutex_for_time);
	pthread_mutex_lock(&philo_data->philo->mutex_for_die_check);
	if (philo_data->die == 0)
	{
		pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
		init_die(philo_data);
		ft_printf(philo_data, 1, time_eat);
		ft_usleep(philo_data, 1);
	}
	else
		pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
	return ;
}

void	ft_sleep(t_philo_data *philo_data)
{
	long	time_sleep;

	pthread_mutex_lock(&philo_data->philo->mutex_for_time);
	time_sleep = get_time();
	time_sleep -= philo_data->philo->timer_start;
	pthread_mutex_unlock(&philo_data->philo->mutex_for_time);
	ft_printf(philo_data, 2, time_sleep);
	ft_usleep(philo_data, 2);
	return ;
}