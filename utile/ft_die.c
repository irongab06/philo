#include "../philo.h"

void	init_die(t_philo_data *philo_data)
{
	philo_data->die_time = philo_data->philo->time_to_die;
	philo_data->philo_time_start = get_time();
	return ;
}

void	check_die(t_philo_data *philo_data)
{
	long	result_time;

	philo_data->philo_time_end = get_time();
	result_time = philo_data->philo_time_end - philo_data->philo_time_start;
	if (result_time >= philo_data->philo->time_to_die)
	{
		pthread_mutex_lock(&philo_data->philo->mutex_for_die);
		if (philo_data->philo->die == 0)
		{
			die(philo_data);
			philo_data->philo->die = 1;
		}	
		pthread_mutex_unlock(&philo_data->philo->mutex_for_die);
	}
	return ;
}

void	die(t_philo_data *philo_data)
{
	long	time_die;

	time_die = get_time();
	time_die -= philo_data->philo->timer_start;
	printf("%ld %d died\n", time_die, philo_data->id);
	return ;
}