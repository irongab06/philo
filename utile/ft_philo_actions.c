/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:38:26 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/27 11:48:59 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	thinking(t_philo_data *philo_data)
{
	long	time_thinking;

	time_thinking = get_time();
	time_thinking -= philo_data->philo->timer_start;	
	// pthread_mutex_lock(&philo_data->philo->mutex_for_printf);
	// printf("\e[38;2;255;182;193m%ld %d is thinking\033[0m\n", time_thinking, philo_data->id);
	// pthread_mutex_unlock(&philo_data->philo->mutex_for_printf);
	ft_printf(philo_data, 0, time_thinking);
	check_die(philo_data);
	return ; 
}

void	eat(t_philo_data *philo_data)
{
	long	time_eat;

	time_eat = get_time();
	time_eat -= philo_data->philo->timer_start;
	init_die(philo_data);
	// pthread_mutex_lock(&philo_data->philo->mutex_for_printf);
	// printf("\033[1;32m%ld %d is eating\033[0m\n", time_eat, philo_data->id);
	// pthread_mutex_unlock(&philo_data->philo->mutex_for_printf);
	ft_printf(philo_data, 1, time_eat);
	usleep(philo_data->philo->time_to_eat * 1000);
	check_die(philo_data);
	return ;
}

void	ft_sleep(t_philo_data *philo_data)
{
	long	time_sleep;

	time_sleep = get_time();
	time_sleep -= philo_data->philo->timer_start;
	// pthread_mutex_lock(&philo_data->philo->mutex_for_printf);
	// printf("\033[1;34m%ld %d is sleeping\033[0m\n", time_sleep, philo_data->id);
	// pthread_mutex_unlock(&philo_data->philo->mutex_for_printf);
	ft_printf(philo_data, 2, time_sleep);
	usleep(philo_data->philo->time_to_sleep * 1000);
	check_die(philo_data);
	return ;
}