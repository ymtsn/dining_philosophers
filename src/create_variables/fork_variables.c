#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"
#define FORK_NUM_INDEX 1
#define SUCCESS 0
#define FAILURE 1

static int init_fork_variables(int philo_num, t_fork **fork)
{
	int	i;

	i = 0;
	while(i < philo_num)
	{
		fork[i] = malloc(sizeof(t_fork));
		if (fork[i] == NULL)
		{
			free_array(i, FREE_FORK, fork);
			return (FAILURE);
		}
		fork[i]->fork_id = i;
		fork[i]->use = NO_USE;
		pthread_mutex_init(&fork[i]->mutex, NULL);
		i++;
	}
	return (SUCCESS);
}

t_fork **create_fork_variables(int philo_num)
{
	t_fork	**fork;

	fork = malloc(sizeof(t_fork*)*philo_num);
	if (fork == NULL)
		return (NULL);
	if (init_fork_variables(philo_num, fork) == FAILURE)
		return (NULL);
	return (fork);
}
