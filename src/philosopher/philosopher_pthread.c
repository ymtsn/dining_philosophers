#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_struct.h"
#include "philo_fork.h"
#include "philo_philosopher.h"

void	philosopher(void *arg)
{
	t_diningtable	*table;
	int				i;

	table = (t_diningtable*)arg;
	i = table->target_philo_id;
	table->philo[i]->timestamp = get_timestamp();
	take_fork(table->philo[i], table->fork);
	eat(table->philo[i]);
	table->philo[i]->timestamp = get_timestamp();
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
		table->target_philo_id = i;
		(void)pthread_create(&philo[i]->thread_id, NULL, (void *)philosopher, table);
		(void)pthread_join(philo[i]->thread_id, NULL);
		i++;
	}
}
