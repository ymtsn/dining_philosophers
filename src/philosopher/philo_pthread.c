#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

void	philosopher(void *arg)
{
	t_philo			*philo;

	philo = (t_philo*)arg;
	while (philo->must_eat--)
	{
		eat(philo);
		if (philo->stop_flg == ERR)
		{
			printf("err philosopher thread\n");
			return ;
		}
		philo_sleep(philo);
		if (philo->stop_flg == ERR)
		{
			printf("err philosopher thread\n");
			return ;
		}
		think(philo);
	}
}

int	create_philo_pthread(t_diningtable *table)
{
	int	philo_num;
	int	i;
	t_philo **philo;

	philo = table->philo;
	philo_num = table->philo_num;
	i = 0;
	while (i < philo_num)
	{
		if ((pthread_create(&philo[i]->thread_id, NULL, (void *)philosopher, table->philo[i])) != 0)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	join_philo_pthread(t_diningtable *table)
{
	int	philo_num;
	int	i;

	philo_num = table->philo_num;
	i = 0;
	while (i < philo_num)
	{
		if (pthread_join(table->philo[i]->thread_id, NULL) != 0)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}
