/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:02:09 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/27 09:56:42 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_philo(void *data)
{
	t_philo_data 	*philo_data;

	philo_data = (t_philo_data*)data;
	while (philo_data->die == 0)
	{
		if (philo_data->die == 0)
			thinking(philo_data);
		if (philo_data->die == 0)
			ft_lock_odd(philo_data);
		if (philo_data->die == 0)
			ft_sleep(philo_data);
	}
	return (NULL);
}

