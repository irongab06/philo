/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:02:09 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/04 09:53:33 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_philo(void *data)
{
	t_philo_data 	*philo_data;

	philo_data = (t_philo_data*)data;
	while (1)
	{
		if ((ft_check_die_value(philo_data)) == 1)
			break;
		thinking(philo_data);
		if ((ft_check_die_value(philo_data)) == 1)
			break;
		ft_lock_odd(philo_data);
		//if (philo_data->philo->nbr_philo == 1)
		//	return (NULL);
		if ((ft_check_die_value(philo_data)) == 1)
			break;
		ft_sleep(philo_data);
	}
	return (NULL);
}

