/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:14:53 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/04 11:40:23 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_philo			philo;
	t_philo_data	*philo_data;
	int				i;

	i = 0;
	if (argc >= 5 && argc < 7)
	{
		if ((ft_check(argc, argv)) > 0)
			return (EXIT_FAILURE);
		if ((ft_init_struct(&philo, &philo_data, argc, argv)) > 0)
			return (EXIT_FAILURE);
		philo.timer_start = get_time();
		ft_create_philo(&philo, philo_data);
		if ((ft_check_thread(&philo, philo_data)) > 0)
		{
			while (i < philo.nbr_philo)
			{
				pthread_join(philo.thread[i], NULL);
				i++;
			}
			ft_free(&philo, philo_data);
			return (0);
		}
	}
	return (0);
}
