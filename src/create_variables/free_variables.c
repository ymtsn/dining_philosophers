#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"

void	free_array(int i, int type, void *arg)
{
	i--;
	while (i >= 0)
	{
		if (type == FREE_PHILO)
		{
			free(((t_philo **)arg)[i]);
		}
		else
		{
			pthread_mutex_destroy(&(((t_fork **)arg)[i]->mutex));
			free(((t_fork **)arg)[i]);
		}
		i--;
	}
	free(arg);
}

void	destroy_variables(t_diningtable *table)
{
	free_array(table->philo_num, FREE_PHILO, table->philo);
	free_array(table->philo_num, FREE_FORK, table->fork);
	free(table);
}
