/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:38:26 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/03 11:30:55 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	thinking(t_philo_data *philo_data)
{
	long	time_thinking;

	time_thinking = get_time();
	time_thinking -= philo_data->philo->timer_start;	
	ft_printf(philo_data, 0, time_thinking);
	return ; 
}

void	eat(t_philo_data *philo_data)
{
	long	time_eat;
	long	time_now;

	time_now = get_time();
	time_eat = time_now - philo_data->philo->timer_start;
	if (philo_data->die == 0)
	{
		init_die(philo_data);
		ft_printf(philo_data, 1, time_eat);
		usleep(philo_data->philo->time_to_eat * 1000);
		//check_die(philo_data);
	}
	return ;
}

void	ft_sleep(t_philo_data *philo_data)
{
	long	time_sleep;

	time_sleep = get_time();
	time_sleep -= philo_data->philo->timer_start;
	ft_printf(philo_data, 2, time_sleep);
	usleep(philo_data->philo->time_to_sleep * 1000);
	return ;
}