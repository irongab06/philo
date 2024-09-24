/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:14:53 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/24 12:12:56 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc >= 5)
	{
		if ((ft_check(argc, argv)) > 0)
			return (EXIT_FAILURE); 
		if ((ft_init_struct(&philo, argv)) > 0);
			return (EXIT_FAILURE);
	}
	return (0);
}