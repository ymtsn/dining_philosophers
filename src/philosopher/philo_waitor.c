#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

void	waitor(t_philo *philo)
{
	while (philo->right_fork->use != NO_USE || philo->left_fork->use != NO_USE)
		usleep(5);
}

