#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

void	philosopher(void *arg)
{
	t_diningtable	*table;
	int				i;
	int				philo_num;

	table = (t_diningtable*)arg;
	i = table->target_philo_id;
	philo_num = table->philo_num;
	table->philo[i]->timestamp = get_timestamp();
	take_fork(table->philo[i], table->fork, philo_num);
	eat(table->philo[i]);
	table->philo[i]->timestamp = get_timestamp();
	philo_sleep(table->philo[i], table->fork, philo_num);
	think(table->philo[i]);
}

void	create_philo_pthread(t_diningtable *table)
{
	int	philo_num;
	int	i;
	t_philo **philo;

	philo = table->philo;
	philo_num = table->philo_num;
	i = 0;
	while (i < philo_num)
	{
		table->target_philo_id = i;
		(void)pthread_create(&philo[i]->thread_id, NULL, (void *)philosopher, table);
		i++;
	}
}

void	join_philo_pthread(t_diningtable *table)
{
	int	philo_num;
	int	i;

	philo_num = table->philo_num;
	i = 0;
	while (i < philo_num)
	{
		(void)pthread_join(table->philo[i]->thread_id, NULL);
		i++;
	}
}
