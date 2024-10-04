/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:55:51 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/04 10:58:00 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//eat = 1
//thinking == 0
//sleep == 2

void	ft_printf(t_philo_data *philo_data, int i, long time)
{
	pthread_mutex_lock(&philo_data->philo->mutex_for_die_check);
	pthread_mutex_lock(&philo_data->philo->mutex_for_printf);
	if (i == 0 && philo_data->die == 0)
		printf("\033[1;49;93m%ld %d is thinking\033[0m\n", time, philo_data->id);
	else if (i == 1 && philo_data->die == 0)
	{
		if (philo_data->philo->nbr_eat_philo > 0)
			philo_data->eat += 1; //ici eat philo
		printf("\033[4;49;92m%ld %d is eating\033[0m\n", time, philo_data->id);
	}
	else if (i == 2 && philo_data->die == 0)
		printf("\033[4;49;36m%ld %d is sleeping\033[0m\n", time, philo_data->id);
	else if (i == 4 && philo_data->die == 0)
		printf("\033[1;33m%ld %d has taken a fork\033[0m\n", time, philo_data->id);
	else if (i == 3 && philo_data->die == 1)
		printf("\033[7;31m%ld %d died\033[0m\n", time, philo_data->id);
	pthread_mutex_unlock(&philo_data->philo->mutex_for_printf);
	pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
}