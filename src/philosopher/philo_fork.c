#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

void	take_right_fork(t_philo *philo)
{
	if (philo->state == PHILO_DIED)
		return ;
	pthread_mutex_lock(&(philo->right_fork->mutex));
	philo->right_fork->use = philo->philo_id;

}

void	take_left_fork(t_philo *philo)
{
	if (philo->state == PHILO_DIED)
		return ;
	pthread_mutex_lock(&(philo->left_fork->mutex));
	philo->left_fork->use = philo->philo_id;
}

void	put_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->right_fork->mutex));
	philo->right_fork->use = NO_USE;
}

void	put_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	philo->left_fork->use = NO_USE;
}
