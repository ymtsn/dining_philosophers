#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#define PHILO_NUM_INDEX 1

t_diningtable	*create_variables(char *argv[])
{
	t_diningtable	*table;

	table = malloc(sizeof(t_diningtable));
	table->philo_num = atoi(argv[PHILO_NUM_INDEX]);
	table->philo = create_philo_variables(argv, table->philo_num);
	table->fork = create_fork_variables(table->philo_num);
	return (table);
}
