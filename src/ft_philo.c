/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:02:09 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/03 11:04:34 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_philo(void *data)
{
	t_philo_data 	*philo_data;

	philo_data = (t_philo_data*)data;
	// while (philo_data->die == 0)
	// {
	// 	if (philo_data->die == 0)
	// 		thinking(philo_data);
	// 	if (philo_data->die == 0)
	// 		ft_lock_odd(philo_data);
	// 	if (philo_data->die == 0)
	// 		ft_sleep(philo_data);
	// }
	while (1)
	{
		pthread_mutex_lock(&philo_data->philo->mutex_for_die_check);
		if (philo_data->die == 1)
		{
			pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
			break;
		}
		pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
		thinking(philo_data);
		pthread_mutex_lock(&philo_data->philo->mutex_for_die_check);
		if (philo_data->die == 1)
		{
			pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
			break;
		}
		pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
		ft_lock_odd(philo_data);
		pthread_mutex_lock(&philo_data->philo->mutex_for_die_check);
		if (philo_data->die == 1)
		{
			pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
			break;
		}
		pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
		ft_sleep(philo_data);
	}
	return (NULL);
}

