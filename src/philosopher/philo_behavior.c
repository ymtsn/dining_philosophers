#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

unsigned long get_timestamp(void)
{
	struct timeval	tv;

	(void)gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_timestamp(t_philo *philo, char *MSG)
{
	unsigned long	timestamp;

	timestamp = get_timestamp();
	printf("%lu %d %s\n", timestamp, philo->philo_id + 1, MSG);
}

void	take_fork(t_philo *philo, t_fork **fork, int philo_num)
{
	pthread_mutex_lock(&fork[philo->philo_id]->mutex);
	print_timestamp(philo, FORK_MSG);
	pthread_mutex_lock(&fork[(philo->philo_id + 1) % philo_num]->mutex);
	print_timestamp(philo, FORK_MSG);
}

void	eat(t_philo *philo)
{
	print_timestamp(philo, EAT_MSG);
	usleep(philo->eat * 1000);
}

void	philo_sleep(t_philo *philo, t_fork **fork, int philo_num)
{
	pthread_mutex_unlock(&fork[philo->philo_id]->mutex);
	pthread_mutex_unlock(&fork[(philo->philo_id + 1) % philo_num]->mutex);
	print_timestamp(philo, SLEEP_MSG);
	usleep(philo->sleep * 1000);
}

void	think(t_philo *philo)
{
	print_timestamp(philo, THINK_MSG);
}
