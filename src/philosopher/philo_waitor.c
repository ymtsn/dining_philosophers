#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

int	waitor(t_philo *philo)
{
	pthread_mutex_lock(&philo->waitor->mutex);
	if (philo->right_fork->use == NO_USE && philo->left_fork->use == NO_USE)
		return (0);
	pthread_mutex_unlock(&philo->waitor->mutex);
	return (1);
}

