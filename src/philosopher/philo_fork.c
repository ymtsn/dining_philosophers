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
}

void	take_left_fork(t_philo *philo)
{
	if (philo->state == PHILO_DIED)
		return ;
	pthread_mutex_lock(&(philo->left_fork->mutex));
}

void	put_right_fork(t_philo *philo)
{
	philo->right_fork->use = NO_USE;
	philo->parmission = CANNOT_EAT;
	pthread_mutex_unlock(&(philo->right_fork->mutex));
}

void	put_left_fork(t_philo *philo)
{
	philo->left_fork->use = NO_USE;
	philo->parmission = CANNOT_EAT;
	pthread_mutex_unlock(&(philo->left_fork->mutex));
}
