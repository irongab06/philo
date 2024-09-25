#include "../philo.h"

void	thinking(t_philo_data *philo_data)
{
	long	time_thinking;

	time_thinking = get_time();
	time_thinking -= philo_data->philo->timer_start;
	printf("%ld %d is thinking\n", time_thinking, philo_data->id);
	check_die(philo_data);
	return ; 
}

void	eat(t_philo_data *philo_data)
{
	long	time_eat;

	time_eat = get_time();
	time_eat -= philo_data->philo->timer_start;
	printf("%ld %d is eating\n", time_eat, philo_data->id);
	usleep(philo_data->philo->time_to_eat);
	check_die(philo_data);
	init_die(philo_data);
	return ;
}

void	sleep(t_philo_data *philo_data)
{
	long	time_sleep;

	time_sleep = get_time();
	time_sleep -= philo_data->philo->timer_start;
	printf("%ld %d is sleeping\n", time_sleep, philo_data->id);
	usleep(philo_data->philo->time_to_sleep);
	check_die(philo_data);
	return ;
}