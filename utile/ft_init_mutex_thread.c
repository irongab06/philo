/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex_thread.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:26:47 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/03 14:44:21 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../philo.h"

int	ft_init_mutex(t_philo *philo)
{
	philo->mutex = malloc(sizeof(pthread_mutex_t) * philo->nbr_philo);
	if (philo->mutex == NULL)
	{
		printf("fail malloc mutex\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_init_thread(t_philo *philo)
{
	philo->thread = malloc(sizeof(pthread_mutex_t) * philo->nbr_philo);
	if (philo->thread == NULL)
	{
		printf("fail malloc thread\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_init_thread_data(t_philo *philo, t_philo_data **philo_data)
{
	int	i;

	i = 0;
	*philo_data = malloc(sizeof(t_philo_data) * philo->nbr_philo);
	if (*philo_data == NULL)
	{
		printf("fail malloc philo_data\n");
		return (EXIT_FAILURE);
	}
	while (i < philo->nbr_philo)
	{
		(*philo_data)[i].id = 0;
		(*philo_data)[i].die = 0;
		(*philo_data)[i].eat_time = 0;
		(*philo_data)[i].sleep_time = 0;
		(*philo_data)[i].die_time = 0;
		(*philo_data)[i].philo_time_start = 0;
		(*philo_data)[i].philo_time_end = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}