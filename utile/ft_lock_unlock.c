/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock_unlock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:21:01 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/27 09:58:03 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_lock_odd(t_philo_data *philo_data)
{
	// int	inter;

	// inter = 0;
	// if (philo_data->id != philo_data->philo->nbr_philo)
	// {
	// 	pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id - 1]);
	// 	pthread_mutex_lock(&philo_data->philo->mutex[(philo_data->id)]);
	// }
	// else
	// {
	// 	pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id - 1]);
	// 	pthread_mutex_lock(&philo_data->philo->mutex[(philo_data->id % philo_data->philo->nbr_philo)]);
	// 	inter++;
	// }
	// if (philo_data->die == 0)
	// 	eat(philo_data);
	// pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id - 1]);
	// if (inter == 0)
	// 	pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id]);
	// else
	// 	pthread_mutex_unlock(&philo_data->philo->mutex[(philo_data->id % philo_data->philo->nbr_philo)]);
	int	left_fork = philo_data->id - 1;
	int	right_fork = philo_data->id % philo_data->philo->nbr_philo;
	int	inter = 0;

	// Ordre de verrouillage strict pour éviter les deadlocks
	if (philo_data->id % 2 == 0)  // Philosophe pair
	{
		pthread_mutex_lock(&philo_data->philo->mutex[right_fork]);
		pthread_mutex_lock(&philo_data->philo->mutex[left_fork]);
	}
	else  // Philosophe impair
	{
		pthread_mutex_lock(&philo_data->philo->mutex[left_fork]);
		pthread_mutex_lock(&philo_data->philo->mutex[right_fork]);
	}

	// Protéger l'accès à la variable die avec un mutex
	pthread_mutex_lock(&philo_data->philo->mutex_for_die_check);
	if (philo_data->die == 0)
	{
		pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
		eat(philo_data);  // Le philosophe mange
	}
	else
	{
		pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
	}

	// Déverrouiller les fourchettes dans le même ordre
	pthread_mutex_unlock(&philo_data->philo->mutex[left_fork]);
	pthread_mutex_unlock(&philo_data->philo->mutex[right_fork]);
}

// void	ft_lock_even(t_philo_data *philo_data)
// {
// 	pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id - 1]);
// 	pthread_mutex_lock(&philo_data->philo->mutex[(philo_data->id)]);
// 	if (philo_data->die == 0)
// 		eat(philo_data);
// 	pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id - 1]);
// 	pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id]);
// }

