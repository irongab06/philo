/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:02:09 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/26 15:28:03 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_philo(void *data)
{
	t_philo_data 	*philo_data;

	philo_data = (t_philo_data*)data;
	init_die(philo_data); // fait
	while (philo_data->die == 0)
	{
		thinking(philo_data); //fait
		if (philo_data->id == philo_data->philo->nbr_philo && philo_data->philo->nbr_philo % 2 != 0)
			usleep(10);
		if (philo_data->id % 2 != 0)
		{
			// ne pas oublier le printf pour les take fork
			pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id]);
			pthread_mutex_lock(&philo_data->philo->mutex[(philo_data->id + 1)]);
		}
		else
		{ 
			pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id - 1]);
			pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id]);
		}
		eat(philo_data); //fait
		pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id]);
		pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id - 1]);
		sleep(philo_data); // fait;
	}
}

void	*ft_philo(void *data)
{
	t_philo_data 	*philo_data;

	philo_data = (t_philo_data*)data;
	init_die(philo_data); // fait
	while (philo_data->die == 0)
	{
		thinking(philo_data); //fait
		if (philo_data->id == philo_data->philo->nbr_philo && philo_data->philo->nbr_philo % 2 != 0)
			usleep(10);
		if (philo_data->id % 2 != 0)
			ft_lock_odd(philo_data);
		else
			ft_lock_even(philo_data);
		eat(philo_data); //fait
		pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id]);
		pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id - 1]);
		sleep(philo_data); // fait;
	}
}
