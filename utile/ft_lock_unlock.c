/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock_unlock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:21:01 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/10 11:57:27 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_lock_odd(t_philo_data *philo_data)
{
	long	time_fork;
	int		right_fork;
	int		left_fork;

	time_fork = 0;
	right_fork = 0;
	left_fork = 0;
	ft_init_lock(philo_data, &right_fork, &left_fork);
	pthread_mutex_lock(&philo_data->philo->mutex[left_fork]);
	ft_time_fork(philo_data, time_fork);
	if (philo_data->philo->nbr_philo == 1)
	{
		pthread_mutex_unlock(&philo_data->philo->mutex[left_fork]);
		return ;
	}
	pthread_mutex_lock(&philo_data->philo->mutex[right_fork]);
	ft_time_fork(philo_data, time_fork);
	eat(philo_data);
	pthread_mutex_unlock(&philo_data->philo->mutex[right_fork]);
	pthread_mutex_unlock(&philo_data->philo->mutex[left_fork]);
}

void	ft_init_lock(t_philo_data *philo_data, int *right_fork, int *left_fork)
{
	if (philo_data->id == philo_data->philo->nbr_philo
		&& philo_data->philo->nbr_philo != 2)
	{
		*left_fork = philo_data->id - 1;
		*right_fork = 0;
	}
	else if (philo_data->id % 2 != 0)
	{
		*left_fork = philo_data->id - 1;
		*right_fork = philo_data->id;
	}
	else
	{
		*left_fork = philo_data->id;
		*right_fork = philo_data->id - 1;
	}
}

void	ft_time_fork(t_philo_data *philo_data, long time_fork)
{
	pthread_mutex_lock(&philo_data->philo->mutex_for_time);
	time_fork = get_time() - philo_data->philo->timer_start;
	ft_printf(philo_data, 4, time_fork);
	pthread_mutex_unlock(&philo_data->philo->mutex_for_time);
}
