/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex_thread.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:26:47 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/24 12:14:18 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../philo.h"

int	ft_init_mutex(t_philo *philo)
{
	philo->mutex = malloc(sizeof(pthread_mutex_t) * philo->nbr_philo);
	if (philo->mutex == '\0')
	{
		printf("fail malloc mutex");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_init_thread(t_philo *philo)
{
	philo->thread = malloc(sizeof(pthread_mutex_t) * philo->nbr_philo);
	if (philo->thread == '\0')
	{
		printf("fail malloc thread");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_init_thread_data(t_philo *philo, t_philo_data **philo_data)
{
	*philo_data = malloc(sizeof(t_philo_data) * philo->nbr_philo);
	if (*philo_data == NULL)
	{
		printf("fail malloc philo_data");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}