#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

void	philosopher(void *arg)
{
	t_philo			*philo;

	philo = (t_philo*)arg;
	eat(philo);
	philo_sleep(philo);
	think(philo);
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
		(void)pthread_create(&philo[i]->thread_id, NULL, (void *)philosopher, table->philo[i]);
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
