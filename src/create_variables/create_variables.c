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

t_diningtable	*create_variables(int argc, char *argv[])
{
	t_diningtable	*table;

	if (argc == 0)
		return (NULL);
	table = malloc(sizeof(t_diningtable));
	if (table == NULL)
		return (NULL);
	table->philo_num = atoi(argv[PHILO_NUM_INDEX]);
	table->die = atoi(argv[DIE_TIME_INDEX]);
	table->eat = atoi(argv[EAT_TIME_INDEX]);
	table->sleep = atoi(argv[SLEEP_TIME_INDEX]);
/* table->must_eat = atoi(argv[MUST_EAT_INDEX]); */
	table->fork = create_fork_variables(table->philo_num);
	if (table->fork == NULL)
	{
		free(table);
		return (NULL);
	}
	table->philo = create_philo_variables(table);
	if (table->philo == NULL)
	{
		free_array(table->philo_num, FREE_FORK, table->fork);
		free(table);
		return (NULL);
	}
	return (table);
}
