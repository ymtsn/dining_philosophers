#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

size_t get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

static void	print_timestamp(t_philo *philo, char *MSG)
{
	if (philo->state == PHILO_DIED)
		return ;
	printf("%lu %d %s\n", get_timestamp(), philo->philo_id + 1, MSG);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->mutex));
	philo->state = PHILO_EAT;
	pthread_mutex_unlock(&(philo->mutex));
	philo->timestamp = get_timestamp();
	while (waitor(philo))
		usleep(1);
	take_right_fork(philo);
	print_timestamp(philo, FORK_MSG);
	take_left_fork(philo);
	print_timestamp(philo, FORK_MSG);
	pthread_mutex_unlock(&philo->waitor->mutex);
	print_timestamp(philo, EAT_MSG);
	usleep(((t_diningtable*)philo->table)->eat * 1000);
	philo->timestamp = get_timestamp();
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&(philo->mutex));
	philo->state = PHILO_SLEEP;
	pthread_mutex_unlock(&(philo->mutex));
	put_right_fork(philo);
	put_left_fork(philo);
	print_timestamp(philo, SLEEP_MSG);
	usleep(((t_diningtable*)philo->table)->sleep * 1000);
}

void	think(t_philo *philo)
{
	pthread_mutex_lock(&(philo->mutex));
	philo->state = PHILO_THINK;
	pthread_mutex_unlock(&(philo->mutex));
	print_timestamp(philo, THINK_MSG);
}
