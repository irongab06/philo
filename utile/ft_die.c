/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:38:13 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/26 14:57:06 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_die(t_philo_data *philo_data)
{
	philo_data->die_time = philo_data->philo->time_to_die;
	philo_data->philo_time_start = get_time();
	return ;
}

void	check_die(t_philo_data *philo_data)
{
	long	result_time;

	philo_data->philo_time_end = get_time();
	result_time = philo_data->philo_time_end - philo_data->philo_time_start;
	if (result_time >= philo_data->philo->time_to_die)
	{
		philo_data->die = 1;
	}	
	return ;
}

void	die(t_philo *philo, t_philo_data *philo_data, int i)
{
	long	time_die;

	time_die = get_time();
	time_die -= philo->timer_start;
	pthread_mutex_lock(&philo->mutex_for_printf);
	printf("\033[1;31m%ld %d died\033[0m\n", time_die, philo_data[i].id);
	pthread_mutex_unlock(&philo->mutex_for_printf);
	return ;
}

void	ft_all_die(t_philo *philo, t_philo_data *philo_data)
{
	int	i;

	i = 0;
	while (i < philo->nbr_philo)
	{
		philo_data[i].die = 1;
	}
	return ;

}