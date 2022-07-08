#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#define PHILO_NUM_INDEX 1

t_diningtable	*create_variables(int argc, char *argv[])
{
	t_diningtable	*table;

	if (argc == 0)
		return (NULL);
	table = malloc(sizeof(t_diningtable));
	if (table == NULL)
		return (NULL);
	table->philo_num = atoi(argv[PHILO_NUM_INDEX]);
	table->fork = create_fork_variables(table->philo_num);
	if (table->fork == NULL)
	{
		free(table);
		return (NULL);
	}
	table->philo = create_philo_variables(argv, table->philo_num, table->fork);
	if (table->philo == NULL)
	{
		free_array(table->philo_num, FREE_FORK, table->fork);
		free(table);
		return (NULL);
	}
	return (table);
}
