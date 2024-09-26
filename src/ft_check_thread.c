/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:13:37 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/26 14:54:17 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check_thread(t_philo *philo, t_philo_data *philo_data)
{
	int		i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < philo->nbr_philo)
		{
			if (philo_data[i].die == 1)
			{
				die(philo, philo_data, i);
				return (1) ;
			}
			i++;
		}
	}
}