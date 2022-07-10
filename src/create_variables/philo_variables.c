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

static int	init_philo_variables(t_diningtable *table)
{
	int	i;

	i = 0;
	while(i < table->philo_num)
	{
		table->philo[i] = malloc(sizeof(t_philo));
		if (table->philo[i] == NULL)
		{
			free_array(i, FREE_PHILO, table->philo);
			return (FAIL);
		}
		table->philo[i]->philo_id = i;
		table->philo[i]->thread_id = (pthread_t)0;
		table->philo[i]->table = (void *)table;
		table->philo[i]->timestamp = 0;
		table->philo[i]->parmission = CANNOT_EAT;
		table->philo[i]->state = PHILO_INIT;
		table->philo[i]->stop_flg = 0;
		table->philo[i]->must_eat = table->must_eat;
		pthread_mutex_init(&table->philo[i]->mutex, NULL);
		table->philo[i]->right_fork = table->fork[i];
		table->philo[i]->left_fork = table->fork[(i + 1) % table->philo_num];
		i++;
	}
	return (SUCCESS);
}

t_philo	**create_philo_variables(t_diningtable *table)
{

	table->philo = malloc(sizeof(t_philo*)*table->philo_num);
	if (table->philo == NULL)
		return (NULL);
	if (init_philo_variables(table) == FAIL)
		return (NULL);
	return (table->philo);
}
