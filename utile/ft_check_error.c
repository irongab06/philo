/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:10:24 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/24 15:08:14 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if ((ft_check_argv(argv[i])) > 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			printf("negative value ERROR\n");
			return (EXIT_FAILURE);
		}
		if (str[i] <= 48 && str[i] >= 57)
		{
			printf("is not a valid digit\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_zero(t_philo *philo)
{
	if (philo->time_to_die == 0)
	{
		printf("bad duration for die");
		return (EXIT_FAILURE);
	}
	if (philo->time_to_eat == 0 || (philo->nbr_eat_philo == 0))
	{
		printf("bad duration for eat");
		return (EXIT_FAILURE);
	}
	if (philo->time_to_sleep == 0)
	{
		printf("bad duration for sleep");
		return (EXIT_FAILURE);
	}
	if (philo->nbr_philo == 0)
	{
		printf("wrong number of philo");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
