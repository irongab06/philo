/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:14:49 by gacavali          #+#    #+#             */
/*   Updated: 2024/09/24 12:23:11 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_init_struct(t_philo *philo, int argc, char **argv)
{
	philo->nbr_philo = ft_atol(argv[1]);
	philo->time_to_die = ft_atol(argv[2]);
	philo->time_to_eat = ft_atol(argv[3]);
	philo->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		philo->nbr_eat_philo = ft_atol(argv[5]);
	else
		philo->nbr_eat_philo = -1;
	if ((ft_init_mutex(philo)) > 0)
		return (EXIT_FAILURE);
	if ((ft_init_thread(philo)) > 0)
		return (EXIT_FAILURE);
}


long ft_atol(char *str)
{
	long	i;
	long	count;
	long	sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' && ++count)
			sign = sign * -1;
		if (str[i] == '+')
			count++;
		if (count > 1)
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + (str[i++] - '0');
	return (number * sign);
}

