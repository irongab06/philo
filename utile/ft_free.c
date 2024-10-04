#include "../philo.h"

void	ft_free(t_philo *philo, t_philo_data *philo_data)
{
	int	i;

	i = 0;
	while (i < philo->nbr_philo)
	{
		pthread_mutex_destroy(&philo->mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->mutex_for_printf);
	pthread_mutex_destroy(&philo->mutex_for_die_check);
	pthread_mutex_destroy(&philo->mutex_for_eat_check);
	free(philo->thread);
	free(philo->mutex);
	free(philo_data);
	return ;
}
