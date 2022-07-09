#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"
#define PHILO_NUM_INDEX 1
#define DIE_TIME_INDEX 2
#define EAT_TIME_INDEX 3
#define SLEEP_TIME_INDEX 4
#define MUST_EAT_INDEX 5
#define SUCCESS 0
#define FAILURE 1

static int	init_philo_variables(int philo_num, char *argv[], t_waitor *waitor, t_philo **philo, t_fork **fork)
{
	int	i;

	i = 0;
	while(i < philo_num)
	{
		philo[i] = malloc(sizeof(t_philo));
		if (philo[i] == NULL)
		{
			free_array(i, FREE_PHILO, philo);
			return (FAILURE);
		}
		philo[i]->philo_id = i;
		philo[i]->thread_id = (pthread_t)-1;
		philo[i]->die = atoi(argv[DIE_TIME_INDEX]);
		philo[i]->eat = atoi(argv[EAT_TIME_INDEX]);
		philo[i]->sleep = atoi(argv[SLEEP_TIME_INDEX]);
		philo[i]->timestamp = 0;
		philo[i]->state = PHILO_INIT;
		pthread_mutex_init(&philo[i]->mutex, NULL);
		philo[i]->waitor = waitor;
		philo[i]->right_fork = fork[i];
		philo[i]->left_fork = fork[(i + 1) % philo_num];
		/* philo[i]->must_eat = atoi(argv[MUST_EAT_INDEX]); */
		i++;
	}
	return (SUCCESS);
}

t_philo	**create_philo_variables(char *argv[], int philo_num, t_waitor *waitor, t_fork **fork)
{
	t_philo **philo;

	philo = malloc(sizeof(t_philo*)*philo_num);
	if (philo == NULL)
		return (NULL);
	if (init_philo_variables(philo_num, argv, waitor, philo, fork) == FAILURE)
		return (NULL);
	return (philo);
}
