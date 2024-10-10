/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:33:47 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/10 08:33:48 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_free(t_philo *philo, t_philo_data *philo_data)
{
	int	i;

	i = 0;
	if (philo->mutex)
	{
		while (i < philo->nbr_philo)
		{
			pthread_mutex_destroy(&philo->mutex[i]);
			i++;
		}
	}
	pthread_mutex_destroy(&philo->mutex_for_printf);
	pthread_mutex_destroy(&philo->mutex_for_die_check);
	pthread_mutex_destroy(&philo->mutex_for_eat_check);
	pthread_mutex_destroy(&philo->mutex_for_time);
	if (philo->thread)
		free(philo->thread);
	if (philo->mutex)
		free(philo->mutex);
	if (philo_data)
		free(philo_data);
}
