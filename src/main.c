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

	if (argc >= 5 && argc < 7)
	{
		if ((ft_check(argc, argv)) > 0)
			return (EXIT_FAILURE); 
		if ((ft_init_struct(&philo, argv)) > 0);
			return (EXIT_FAILURE);
		ft_philo(philo);
		
	}
	return (0);
}