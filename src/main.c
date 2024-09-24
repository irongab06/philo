/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:14:53 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/24 12:27:06 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;
	t_philo_data	*philo_data;
	int	i;

	i = 0;
	if (argc >= 5 && argc < 7)
	{
		if ((ft_check(argc, argv)) > 0)
			return (EXIT_FAILURE); 
		if ((ft_init_struct(&philo, &philo_data, argc, argv)) > 0)
			return (EXIT_FAILURE);

		while (i < philo.nbr_philo)
		{
			pthread_mutex_init(&philo.mutex[i], NULL);
			i++;
		}
		i = 0;
		while (i < philo.nbr_philo)
		{
			philo_data[i].id = i + 1;
			philo_data[i].philo = &philo; 
			pthread_create(&philo.thread[i], NULL, ft_philo, &philo_data[i]);
			i++;
		}
		i = 0;
		while (i < philo.nbr_philo)
		{
			pthread_join(philo.thread[i],NULL);
			i++;
		}
		i = 0;
		while (i < philo.nbr_philo)
		{
			pthread_mutex_destroy(&philo.mutex[i]);
			i++;
		}
		
	}
	return (0);
}
