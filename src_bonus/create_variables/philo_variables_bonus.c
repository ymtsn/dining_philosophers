#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"
#include "philo_philosopher_bonus.h"
#include <stdio.h>

static int	init_philo_variables(t_diningtable *table)
{
	int	i;

	i = 0;
	while (i < table->philo_num)
	{
		table->philo[i] = malloc(sizeof(t_philo));
		if (table->philo[i] == NULL)
		{
			free_array(i, table->philo);
			return (FAIL);
		}
		table->philo[i]->philo_id = i;
		table->philo[i]->timestamp = 0;
		table->philo[i]->table = table;
		table->philo[i]->parmission = CANNOT_EAT;
		table->philo[i]->state = PHILO_INIT;
		table->philo[i]->stop_flg = 0;
		table->philo[i]->sema = NULL;
		table->philo[i]->monitor_tid = (pthread_t)0;
		table->philo[i]->must_eat = table->must_eat;
		i++;
	}
	return (SUCCESS);
}

t_philo	**create_philo_variables(t_diningtable *table)
{
	table->philo = malloc(sizeof(t_philo *) * table->philo_num);
	if (table->philo == NULL)
		return (NULL);
	if (init_philo_variables(table) == FAIL)
		return (NULL);
	return (table->philo);
}
