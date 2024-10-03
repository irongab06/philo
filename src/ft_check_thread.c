/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:13:37 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/03 11:33:13 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check_thread(t_philo *philo, t_philo_data *philo_data)
{
	int		i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < philo->nbr_philo)
		{
			pthread_mutex_lock(&philo_data->philo->mutex_for_die_check);
			check_die(&philo_data[i]);
			if (philo_data[i].die == 1)
			{
				pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
				die(philo, philo_data, i);
				return (1) ;
			}
			pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
			i++;
		}
	}
}