/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:13:37 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/04 11:33:40 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check_thread(t_philo *philo, t_philo_data *philo_data)
{
	int		i;

	while (1)
	{
		i = 0;
		while (i < philo->nbr_philo)
		{
			check_die(&philo_data[i]);
			if (check_eat_all(philo, philo_data) == 1 && philo->nbr_eat_philo > 0)
			{
				ft_all_eat(philo, philo_data);
				return (1);
			}
			pthread_mutex_lock(&philo_data->philo->mutex_for_die_check);
			if (philo_data[i].die == 1)
			{
				pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
				die(philo, philo_data, i);
				return (1);
			}
			pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
			i++;
			usleep(100);
		}
	}
}
