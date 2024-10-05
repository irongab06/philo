/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex_thread.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:26:47 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/04 11:35:48 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../philo.h"

int	ft_init_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	philo->mutex = malloc(sizeof(pthread_mutex_t) * philo->nbr_philo);
	if (philo->mutex == NULL)
	{
		printf("fail malloc mutex\n");
		return (EXIT_FAILURE);
	}
	while (i < philo->nbr_philo)
	{
		pthread_mutex_init(&philo->mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&philo->mutex_for_printf, NULL);
	pthread_mutex_init(&philo->mutex_for_die_check, NULL);
	pthread_mutex_init(&philo->mutex_for_eat_check, NULL);
	pthread_mutex_init(&philo->mutex_for_time, NULL);
	return (EXIT_SUCCESS);
}

int	ft_init_thread(t_philo *philo)
{
	philo->thread = malloc(sizeof(pthread_t) * philo->nbr_philo);
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
		(*philo_data)[i].eat = 0;
		(*philo_data)[i].all_eat = 0;
		i++;
	}
	i = 0;
	while (i < philo->nbr_philo)
	{
		(*philo_data)[i].id = i + 1;
		(*philo_data)[i].philo = philo;
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_create_philo(t_philo *philo, t_philo_data *philo_data)
{
	int	i;

	i = 0;
	while(i < philo->nbr_philo)
	{
		if (philo_data[i].id % 2 != 0)
		{
			init_die(&philo_data[i]);
			pthread_create(&philo->thread[i], NULL, ft_philo, &philo_data[i]);
		}
		i++;
	}
	usleep(100);
	i = 0;
	while(i < philo->nbr_philo)
	{
		if (philo_data[i].id % 2 == 0)
		{
			init_die(&philo_data[i]);
			pthread_create(&philo->thread[i], NULL, ft_philo, &philo_data[i]);
		}
		i++;
	}
}