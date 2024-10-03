#include "../philo.h"

void	ft_lock_odd(t_philo_data *philo_data)
{
	int	inter;
	long	time_fork_left;
	long	time_fork_right;

	
	inter = 0;
	if (philo_data->id != philo_data->philo->nbr_philo)
	{
		if (philo_data->id % 2 == 0)
		{
			pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id - 1]);
			time_fork_left = get_time();
			time_fork_left -= philo_data->philo->timer_start;
			ft_printf(philo_data, 4, time_fork_left);
			pthread_mutex_lock(&philo_data->philo->mutex[(philo_data->id)]);
			time_fork_right = get_time();
			time_fork_right -= philo_data->philo->timer_start;
			ft_printf(philo_data, 4, time_fork_right);
		}
		else
		{
			pthread_mutex_lock(&philo_data->philo->mutex[(philo_data->id)]);
			time_fork_left = get_time();
			time_fork_left -= philo_data->philo->timer_start;
			ft_printf(philo_data, 4, time_fork_left);
			pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id - 1]);
			time_fork_right = get_time();
			time_fork_right -= philo_data->philo->timer_start;
			ft_printf(philo_data, 4, time_fork_right);
		}
	}
	else
	{
		pthread_mutex_lock(&philo_data->philo->mutex[philo_data->id - 1]);
		time_fork_left = get_time();
		time_fork_left -= philo_data->philo->timer_start;
		ft_printf(philo_data, 4, time_fork_left);
		pthread_mutex_lock(&philo_data->philo->mutex[(philo_data->id % philo_data->philo->nbr_philo)]);
		time_fork_right = get_time();
		time_fork_right -= philo_data->philo->timer_start;
		ft_printf(philo_data, 4, time_fork_right);
		inter++;
	}

	if (philo_data->die == 0)
		eat(philo_data);
	pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id - 1]);	
	if (inter == 0)
		pthread_mutex_unlock(&philo_data->philo->mutex[philo_data->id]);
	else
		pthread_mutex_unlock(&philo_data->philo->mutex[(philo_data->id % philo_data->philo->nbr_philo)]);

}

pthread_mutex_lock(&philo_data->philo->mutex[(philo_data->id % philo_data->philo->nbr_philo)]);