#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_fork.h"
#define FORK_NUM_INDEX 1

static void init_fork(int fork_num, t_fork **fork)
{
	int	i;

	i = 0;
	while(i < fork_num)
	{
		fork[i] = malloc(sizeof(t_fork));
		fork[i]->fork_id = i;
		fork[i]->fork_num = fork_num;
		fork[i]->use_philo_num = NO_USE;
		pthread_mutex_init(&fork[i]->mutex, NULL);
		i++;
	}
}

t_fork **create_fork_variable(char *argv[])
{
	int		fork_num;
	t_fork	**fork;

	fork_num = atoi(argv[FORK_NUM_INDEX]);
	if (fork_num == 1)
		fork_num++;
	fork = malloc(sizeof(t_fork*)*fork_num);
	init_fork(fork_num, fork);
	return (fork);
}
