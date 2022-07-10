#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"
#include "philo_monitor.h"
#include "philo_waiter.h"
#include "philo_debug.h"

static int	create_my_pthread(t_diningtable *table)
{
	if (create_philo_pthread(table) == FAIL)
		return (FAIL);
	if (create_monitor_pthread(table) == FAIL)
		return (FAIL);
	if (create_waiter_pthread(table) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

static int	join_my_pthread(t_diningtable *table)
{
	if (join_monitor_pthread(table) == FAIL)
		return (FAIL);
	if (join_waiter_pthread(table) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	main(int argc,	char *argv[])
{
	t_diningtable	*table;

	table = create_table_variables(argc, argv);
	if (table == NULL)
		return (1);
	if (create_my_pthread(table) == FAIL)
	{
		destroy_variables(table);
		return (1);
	}
	if (join_my_pthread(table) == FAIL)
	{
		destroy_variables(table);
		return (1);
	}
	/* print_philo(table);
	print_fork(table); */
	destroy_variables(table);
	return (0);
}

