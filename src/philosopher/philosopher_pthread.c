#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_fork.h"
#include "philo_philosopher.h"
#include "philo_diningtable.h"

void	philosopher(void *diningtable)
{
	t_diningtable	*table;
	int				i;

	table = (t_diningtable *)diningtable;
	i = table->philo_id;
	take_fork(table->philo[i], table->fork);
	eat(table->philo[i]);
	philo_sleep(table->philo[i], table->fork);
	think(table->philo[i]);
}

void	create_philo_pthread(t_diningtable *table)
{
	int	philo_num;
	int	i;
	t_philo **philo;

	philo = table->philo;
	philo_num = philo[0]->philo_num;
	i = 0;
	while (i < philo_num)
	{
		table->philo_id = i;
		(void)pthread_create(&philo[i]->thread_id, NULL, (void *)philosopher, table);
		(void)pthread_join(philo[i]->thread_id, NULL);
		i++;
	}
}
