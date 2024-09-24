#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo
{
	unsigned int	time_to_die;
	unsigned int	time_to_sleep;
	unsigned int	time_to_eat;
	unsigned int	number_of_philosophers;
	unsigned int	number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	**mutex;
	pthread_t	**tid;
}			t_philo;

int	main(int	argc, char **argv);

#endif
