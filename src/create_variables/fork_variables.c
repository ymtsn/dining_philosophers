#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

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
			return (FAIL);
		}
		fork[i]->fork_id = i;
		fork[i]->use = NO_USE;
		fork[i]->use_philo_id = -1;
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
	if (init_fork_variables(philo_num, fork) == FAIL)
		return (NULL);
	return (fork);
}
