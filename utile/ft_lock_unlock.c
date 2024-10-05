/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock_unlock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:21:01 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/04 09:33:45 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// void	ft_lock_odd(t_philo_data *philo_data)
// {
// 	int	inter;
// 	long	time_fork_left;
// 	long	time_fork_right;
// 	//int right_fork_index;
// 	int left_fork_index;

// 	//right_fork_index = philo_data->id;
// 	left_fork_index = philo_data->id - 1;
// 	if (left_fork_index < 0)
// 		left_fork_index = 0;
// 	inter = 0;

// 	if (philo_data->id != philo_data->philo->nbr_philo)
// 	{
// 		if (philo_data->id % 2 != 0)
// 		{
// 			pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id - 1]);
// 			time_fork_left = get_time();
// 			time_fork_left -= philo_data->philo->timer_start;
// 			ft_printf(philo_data, 4, time_fork_left);
// 			pthread_mutex_lock(&philo_data->philo->mutex[(philo_data->id)]);
// 			time_fork_right = get_time();
// 			time_fork_right -= philo_data->philo->timer_start;
// 			ft_printf(philo_data, 4, time_fork_right);
// 		}
// 		else
// 		{
// 			pthread_mutex_lock(&philo_data->philo->mutex[(philo_data->id)]);
// 			time_fork_left = get_time();
// 			time_fork_left -= philo_data->philo->timer_start;
// 			ft_printf(philo_data, 4, time_fork_left);
// 			pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id - 1]);
// 			time_fork_right = get_time();
// 			time_fork_right -= philo_data->philo->timer_start;
// 			ft_printf(philo_data, 4, time_fork_right);
// 		}
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id - 1]);
// 		time_fork_left = get_time();
// 		time_fork_left -= philo_data->philo->timer_start;
// 		ft_printf(philo_data, 4, time_fork_left);
// 		if (philo_data->philo->nbr_philo == 1)
// 		{
// 			pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id - 1]);
// 			return ;
// 		}
// 		pthread_mutex_lock(&philo_data->philo->mutex[0]);
// 		time_fork_right = get_time();
// 		time_fork_right -= philo_data->philo->timer_start;
// 		ft_printf(philo_data, 4, time_fork_right);
// 		inter++;
// 	}
// 	if (philo_data->die == 0)
// 		eat(philo_data);
// 	pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id - 1]);
// 	if (inter == 0)
// 		pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id]);
// 	else
// 		pthread_mutex_unlock(&philo_data->philo->mutex[(philo_data->id % philo_data->philo->nbr_philo)]);
// }

void	ft_lock_odd(t_philo_data *philo_data)
{
	long	time_fork;
	int 	right_fork;
	int 	left_fork;

	time_fork = 0;
	right_fork = 0;
	left_fork = 0;
	ft_init_lock(philo_data, &right_fork, &left_fork);
	pthread_mutex_lock(&philo_data->philo->mutex[left_fork]);
	pthread_mutex_lock(&philo_data->philo->mutex_for_time);
	time_fork = get_time() - philo_data->philo->timer_start;
	pthread_mutex_unlock(&philo_data->philo->mutex_for_time);
	ft_printf(philo_data, 4, time_fork);
	if (philo_data->philo->nbr_philo == 1)
	{
		pthread_mutex_unlock(&philo_data->philo->mutex[left_fork]);
		return ;
	}
	pthread_mutex_lock(&philo_data->philo->mutex[right_fork]);
	pthread_mutex_lock(&philo_data->philo->mutex_for_time);
	time_fork = get_time() - philo_data->philo->timer_start;
	pthread_mutex_unlock(&philo_data->philo->mutex_for_time);
	ft_printf(philo_data, 4, time_fork);
	pthread_mutex_lock(&philo_data->philo->mutex_for_die_check);
	if (philo_data->die == 0)
	{
		pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
		eat(philo_data);
	}
	else
		pthread_mutex_unlock(&philo_data->philo->mutex_for_die_check);
	pthread_mutex_unlock(&philo_data->philo->mutex[right_fork]);
	pthread_mutex_unlock(&philo_data->philo->mutex[left_fork]);
}

void	ft_init_lock(t_philo_data *philo_data, int *right_fork , int *left_fork)
{
	if (philo_data->id == philo_data->philo->nbr_philo && philo_data->philo->nbr_philo != 2)
	{
		*left_fork = philo_data->id - 1;
		*right_fork = 0;
	}
	else if (philo_data->id % 2 != 0)
	{
		*left_fork = philo_data->id - 1;
		*right_fork = philo_data->id;
	}
	else
	{
		*left_fork = philo_data->id;
		*right_fork = philo_data->id - 1;
	}
}

