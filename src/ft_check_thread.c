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

void	ft_check_thread(void *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)data;
	while (1)
	{
		i = 0;
		while (i < philo->nbr_philo)
		{
			if (philo->philo_data[i].die == 1)
			{
				die(philo, i);
				ft_all_die(philo);
				return ;
			}
			i++;
		}
	}
}