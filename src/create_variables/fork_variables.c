#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#define FORK_NUM_INDEX 1

static void init_fork(int philo_num, t_fork **fork)
{
	int	i;

	i = 0;
	while(i < philo_num)
	{
		fork[i] = malloc(sizeof(t_fork));
		fork[i]->fork_id = i;
		fork[i]->use_philo_num = NO_USE;
		pthread_mutex_init(&fork[i]->mutex, NULL);
		i++;
	}
}

t_fork **create_fork_variables(int philo_num)
{
	t_fork	**fork;

	fork = malloc(sizeof(t_fork*)*philo_num);
	init_fork(philo_num, fork);
	return (fork);
}
