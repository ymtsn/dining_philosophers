#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"
#include "philo_monitor.h"
#include "philo_debug.h"

int	main(int argc,	char *argv[])
{
	t_diningtable	*table;

	(void)argc;
	table = create_variables(argc, argv);
	if (table == NULL)
		return (1);
	create_philo_pthread(table);
	create_monitor_pthread(table);
	join_monitor_pthread(table);
	destroy_variables(table);
/* 	print_philo(table);
	print_fork(table); */
	return (0);
}

