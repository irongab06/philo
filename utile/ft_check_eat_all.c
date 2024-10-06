/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_eat_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:27:10 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/04 11:29:36 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_eat_all(t_philo *philo, t_philo_data *philo_data)
{
	int i;

	i = 0;
	while (i < philo->nbr_philo)
	{
		pthread_mutex_lock(&philo_data->philo->mutex_for_eat_check);
		if (philo_data[i].eat < philo->nbr_eat_philo)
		{
			pthread_mutex_unlock(&philo_data->philo->mutex_for_eat_check);
			return (0);
		}
		pthread_mutex_unlock(&philo_data->philo->mutex_for_eat_check);
		i++;
	}
	return (1);
}

void	ft_all_eat(t_philo *philo, t_philo_data *philo_data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo_data->philo->mutex_for_eat_check);
	while (i < philo->nbr_philo)
	{
		philo_data[i].all_eat = 1;
		i++;
	}
	pthread_mutex_unlock(&philo_data->philo->mutex_for_eat_check);
	return ;
}