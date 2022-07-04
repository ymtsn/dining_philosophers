#include <pthread.h>
#include <stdlib.h>
#include "philo_fork.h"
#include "philo_philosopher.h"
#include "philo_diningtable.h"
#include "philo_debug.h"

int	main(int argc,	char *argv[])
{
	t_diningtable	*table;

	(void)argc;
	table = malloc(sizeof(t_diningtable));
	table->philo = create_philo_variable(argv);
	table->fork = create_fork_variable(argv);
	create_philo_pthread(table);
	/* join_philo_pthread(table); */
	/* print_philo(table->philo);
	print_fork(table->fork); */
	return (0);
}

