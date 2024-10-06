/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:38:13 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/04 11:31:33 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_die(t_philo_data *philo_data)
{
	pthread_mutex_lock(&philo_data->philo->mutex_for_time);
	philo_data->die_time = philo_data->philo->time_to_die;
	philo_data->philo_time_start = get_time();
	pthread_mutex_unlock(&philo_data->philo->mutex_for_time);
	return ;
}

void	check_die(t_philo_data *philo_data)
{
	long	result_time;

	result_time = 0;
	pthread_mutex_lock(&philo_data->philo->mutex_for_time);
	pthread_mutex_lock(&philo_data->philo->mutex_for_die_check);
	if (philo_data->die == 0)
	{
		//pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);

		philo_data->philo_time_end = get_time();
		result_time = philo_data->philo_time_end - philo_data->philo_time_start;
		if (result_time > philo_data->philo->time_to_die)
		{
		//	pthread_mutex_lock(&philo_data->philo->mutex_for_die_check);
			philo_data->die = 1;
		//	pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
		}
	}
	pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
	pthread_mutex_unlock(&philo_data->philo->mutex_for_time);
	return ;
}

void	die(t_philo *philo, t_philo_data *philo_data, int i)
{
	long	time_die;

	time_die = 0;
	pthread_mutex_lock(&philo_data->philo->mutex_for_time);
	time_die = get_time();
	time_die -= philo->timer_start;
	ft_printf(&philo_data[i], 3, time_die);
	pthread_mutex_unlock(&philo_data->philo->mutex_for_time);
	ft_all_die(philo, philo_data);
	return ;
}

void	ft_all_die(t_philo *philo, t_philo_data *philo_data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo_data->philo->mutex_for_die_check);
	while (i < philo->nbr_philo)
	{
		philo_data[i].die = 1;
		i++;
	}
	pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
	return ;

}

int	ft_check_die_value(t_philo_data *philo_data)
{
		pthread_mutex_lock(&philo_data->philo->mutex_for_die_check);
		pthread_mutex_lock(&philo_data->philo->mutex_for_eat_check);
		if (philo_data->die == 1 || philo_data->all_eat == 1)
		{
			pthread_mutex_unlock(&philo_data->philo->mutex_for_eat_check);
			pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
			return (1);
		}
		pthread_mutex_unlock(&philo_data->philo->mutex_for_eat_check);
		pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
		return (0);
}