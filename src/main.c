/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:14:53 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/26 14:28:12 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
	penser a mettre un message d erreur si le nombre d argument n est pas bon 
	penser a ajouter les printf de prise de fourchette
	penser a gerer l option supplementaire.
	faire le makefile
	effectuer les free et les destroys
	mettre a la norme
	gerer avec 1 philo
	ou deux
*/

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
		pthread_mutex_init(&philo.mutex_for_printf, NULL);
		i = 0;
		philo.timer_start = get_time();
		while (i < philo.nbr_philo)
		{
			philo_data[i].id = i + 1;
			philo_data[i].philo = &philo;
			i++;
		}
		i = 0;
		while(i < philo.nbr_philo)
		{
			if (philo_data[i].id % 2 != 0)
				pthread_create(&philo.thread[i], NULL, ft_philo, &philo_data[i]);
			i++;
		}
		usleep(100);
		i = 0;
		while(i < philo.nbr_philo)
		{
			if (philo_data[i].id % 2 == 0)
				pthread_create(&philo.thread[i], NULL, ft_philo, &philo_data[i]);
			i++;
		}
		if ((ft_check_thread(&philo, philo_data)) > 0)
		{
			return (0);
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
		pthread_mutex_destroy(&philo.mutex_for_printf);
	}
	return (0);
}
