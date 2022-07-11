#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

void	take_right_fork(t_philo *philo)
{
	int	rc;

	rc = pthread_mutex_lock(&(philo->right_fork->mutex));
	if (rc != 0)
		philo->stop_flg = ERR;
}

void	take_left_fork(t_philo *philo)
{
	int	rc;

	rc = pthread_mutex_lock(&(philo->left_fork->mutex));
	if (rc != 0)
		philo->stop_flg = ERR;
}

void	put_right_fork(t_philo *philo)
{
	int	rc;

	rc = pthread_mutex_unlock(&(philo->right_fork->mutex));
	if (rc != 0)
		philo->stop_flg = ERR;
}

void	put_left_fork(t_philo *philo)
{
	int	rc;

	rc = pthread_mutex_unlock(&(philo->left_fork->mutex));
	if (rc != 0)
		philo->stop_flg = ERR;
}
