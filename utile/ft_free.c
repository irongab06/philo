#include "../philo.h"

void	ft_free(t_philo *philo, t_philo_data *philo_data)
{
	int	i;

	i = 0;
	if (philo->mutex)
	{
		while (i < philo->nbr_philo)
		{
			pthread_mutex_destroy(&philo->mutex[i]);
			i++;
		}
	}
	if (&philo->mutex_for_printf)
		pthread_mutex_destroy(&philo->mutex_for_printf);
	if (&philo->mutex_for_die_check)
		pthread_mutex_destroy(&philo->mutex_for_die_check);
	if (&philo->mutex_for_eat_check)
		pthread_mutex_destroy(&philo->mutex_for_eat_check);
	if (&philo->mutex_for_time)
		pthread_mutex_destroy(&philo->mutex_for_time);
	if (philo->thread)
		free(philo->thread);
	if (philo->mutex)
		free(philo->mutex);
	if (philo_data)
		free(philo_data);
}
