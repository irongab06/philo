/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:10:24 by gacavali          #+#    #+#             */
/*   Updated: 2024/10/10 11:04:27 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check(int argc, char **argv)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
	while (i < argc)
	{
		error += ft_check_argv(argv[i]);
		i++;
	}
	error += ft_check_zero(argv);
	if (error > 0)
		return (EXIT_FAILURE);
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

int	ft_check_zero(char **argv)
{
	int	error;

	error = 0;
	if (ft_atol(argv[2]) == 0)
	{
		printf("Bad duration for die\n");
		error = 1;
	}
	if (ft_atol(argv[3]) == 0 || (argv[5] && (ft_atol(argv[5]) == 0)))
	{
		printf("Bad duration for eat\n");
		error = 1;
	}
	if (ft_atol(argv[4]) == 0)
	{
		printf("Bad duration for sleep\n");
		error = 1;
	}
	if (ft_atol(argv[1]) == 0)
	{
		printf("Wrong number of philo\n");
		error = 1;
	}
	return (error);
}
