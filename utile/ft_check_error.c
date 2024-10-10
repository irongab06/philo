/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:10:24 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/10 08:52:05 by gacavali         ###   ########.fr       */
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
		if (str[i] < 48 || str[i] > 57)
		{
			printf("%s is not a valid value\n", str + i);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_zero(t_philo *philo)
{
	int	error;

	error = 0;
	if (philo->time_to_die == 0)
	{
		printf("Bad duration for die\n");
		error = 1;
	}
	if (philo->time_to_eat == 0 || (philo->nbr_eat_philo == 0))
	{
		printf("Bad duration for eat\n");
		error = 1;
	}
	if (philo->time_to_sleep == 0)
	{
		printf("Bad duration for sleep\n");
		error = 1;
	}
	if (philo->nbr_philo == 0)
	{
		printf("Wrong number of philo\n");
		error = 1;
	}
	return (error);
}
