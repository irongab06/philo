#include <stdio.h>
#include <pthread.h>

#define TIME_OF_COUNT 21000

 typedef struct	s_philo
 {
	pthread_mutex_t	mutex_count;
 	unsigned int	count;
 }		t_philo;

void *thread_routine(void *data)
{
	pthread_t	tid;
	t_philo	*philo;
	unsigned int	i;

	tid = pthread_self();

	i = 0;
	philo = (t_philo*)data;

	while (i < TIME_OF_COUNT)
	{
		pthread_mutex_lock(&philo->mutex_count);
		philo->count++;
		pthread_mutex_unlock(&philo->mutex_count);
		i++;
	}
	pthread_mutex_lock(&philo->mutex_count);
	printf("tid %ld    count %u\n", tid, philo->count);
	pthread_mutex_unlock(&philo->mutex_count);
	return (NULL);
}

int main(void)
{
	pthread_t tid1; 
	pthread_t tid2;
	t_philo	philo;

	philo.count = 0;

	pthread_mutex_init(&philoutex_count, NULL);

	pthread_create(&tid1, NULL, thread_routine, &philo);
	pthread_create(&tid2, NULL, thread_routine, &philo);

	pthread_join(tid1, NULL);
	pthread_join(tid2,NULL);
	pthread_mutex_destroy(&philo.mutex_count);
	return (0);
}