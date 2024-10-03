/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:55:51 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/27 11:53:09 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//eat = 1
//thinking == 0
//sleep == 2

void	ft_printf(t_philo_data *philo_data, int i, long time)
{
	if (i == 0 && philo_data->die == 0)
	{
		pthread_mutex_lock(&philo_data->philo->mutex_for_printf);
		printf("\e[38;2;255;182;193m%ld %d is thinking\033[0m\n", time, philo_data->id);
		pthread_mutex_unlock(&philo_data->philo->mutex_for_printf);
	}	
	else if (i == 1 && philo_data->die == 0)
	{
		pthread_mutex_lock(&philo_data->philo->mutex_for_printf);
		printf("\033[1;32m%ld %d is eating\033[0m\n", time, philo_data->id);
		pthread_mutex_unlock(&philo_data->philo->mutex_for_printf);
	}
	else if (i == 2 && philo_data->die == 0)
	{
		pthread_mutex_lock(&philo_data->philo->mutex_for_printf);
		printf("\033[1;34m%ld %d is sleeping\033[0m\n", time, philo_data->id);
		pthread_mutex_unlock(&philo_data->philo->mutex_for_printf);
	}	
	else if (i == 3 && philo_data->die == 1)
	{
		pthread_mutex_lock(&philo_data->philo->mutex_for_printf);
		printf("\033[1;31m%ld %d died\033[0m\n", time, philo_data->id);
		pthread_mutex_unlock(&philo_data->philo->mutex_for_printf);
	}	
}
