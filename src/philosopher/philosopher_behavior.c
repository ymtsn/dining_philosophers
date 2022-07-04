#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_fork.h"
#include "philo_philosopher.h"
#define NG	0
#define OK	1
#define FORK_MSG "has taken a fork"
#define EAT_MSG "is eating"
#define SLEEP_MSG "is sleeping"
#define THINK_MSG "is thinking"

void	print_timestamp(t_philo *philo, char *MSG)
{
	struct timeval	tv;
	unsigned long	timestamp;

	(void)gettimeofday(&tv, NULL);
	timestamp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	printf("%lu %d %s\n", timestamp, philo->philo_id, MSG);
}

void	take_fork(t_philo *philo, t_fork **fork)
{
	pthread_mutex_lock(&fork[philo->philo_id]->mutex);
	print_timestamp(philo, FORK_MSG);
	pthread_mutex_lock(&fork[(philo->philo_id + 1) % (*fork)->fork_num]->mutex);
	print_timestamp(philo, FORK_MSG);
}

void	eat(t_philo *philo)
{
	print_timestamp(philo, EAT_MSG);
	usleep(philo->eat);
}

void	philo_sleep(t_philo *philo, t_fork **fork)
{
	pthread_mutex_unlock(&fork[philo->philo_id]->mutex);
	pthread_mutex_unlock(&fork[(philo->philo_id + 1) % philo->philo_num]->mutex);
	print_timestamp(philo, SLEEP_MSG);
	usleep(philo->sleep);
}

void	think(t_philo *philo)
{
	print_timestamp(philo, THINK_MSG);
}
