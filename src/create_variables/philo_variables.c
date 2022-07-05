#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#define PHILO_NUM_INDEX 1
#define DIE_TIME_INDEX 2
#define EAT_TIME_INDEX 3
#define SLEEP_TIME_INDEX 4
#define MUST_EAT_INDEX 5

static void	init_philo_variable(int philo_num, char *argv[], t_philo **philo)
{
	int	i;

	i = 0;
	while(i < philo_num)
	{
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->philo_id = i;
		philo[i]->thread_id = (pthread_t)-1;
		philo[i]->die = atoi(argv[DIE_TIME_INDEX]);
		philo[i]->eat = atoi(argv[EAT_TIME_INDEX]);
		philo[i]->sleep = atoi(argv[SLEEP_TIME_INDEX]);
		philo[i]->timestamp = 0;
		/* philo[i]->must_eat = atoi(argv[MUST_EAT_INDEX]); */
		i++;
	}
}

t_philo	**create_philo_variables(char *argv[], int philo_num)
{
	t_philo **philo;

	philo = malloc(sizeof(t_philo*)*philo_num);
	init_philo_variable(philo_num, argv, philo);
	return (philo);
}
