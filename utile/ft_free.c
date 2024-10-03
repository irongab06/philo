#include "../philo.h"

void	ft_free(t_philo *philo, t_philo_data *philo_data)
{
	free(philo->thread);
	free(philo->mutex);
	free(philo_data);
	return ;
}
