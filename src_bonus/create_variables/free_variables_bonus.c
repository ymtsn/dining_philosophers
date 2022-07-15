#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"

void	free_array(int i, void *arg)
{
	i--;
	while (i >= 0)
	{
			free(((t_philo **)arg)[i]);
		i--;
	}
	free(arg);
}

void	destroy_variables(t_diningtable *table)
{
	free_array(table->philo_num, table->philo);
	sem_close(table->sema);
	sem_unlink("./philo_bonus/philo_bonus");
	free(table);
}
