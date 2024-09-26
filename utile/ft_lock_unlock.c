/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock_unlock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:21:01 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/26 17:07:07 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_lock_odd(t_philo_data *philo_data)
{
	int	inter;

	inter = 0;
	if (philo_data->id != philo_data->philo->nbr_philo)
	{
		pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id - 1]);
		pthread_mutex_lock(&philo_data->philo->mutex[(philo_data->id)]);
	}
	else
	{
		pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id - 1]);
		pthread_mutex_lock(&philo_data->philo->mutex[(philo_data->id % philo_data->philo->nbr_philo)]);
		inter++;
	}
	if (philo_data->die == 0)
		eat(philo_data);
	pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id - 1]);
	if (inter == 0)
		pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id]);
	else
		pthread_mutex_unlock(&philo_data->philo->mutex[(philo_data->id % philo_data->philo->nbr_philo)]);
}

void	ft_lock_even(t_philo_data *philo_data)
{
	pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id - 1]);
	pthread_mutex_lock(&philo_data->philo->mutex[(philo_data->id)]);
	if (philo_data->die == 0)
		eat(philo_data);
	pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id - 1]);
	pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id]);
}

