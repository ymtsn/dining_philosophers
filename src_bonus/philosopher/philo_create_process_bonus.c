#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"
#include "philo_philosopher_bonus.h"
#include "philo_monitor_bonus.h"

void	do_philosopher(t_philo *philo)
{
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
	sem_close(philo->sema);
}

void	manage_philo_monitor(t_philo *philo, sem_t *sema)
{
	if (create_monitor_pthread(philo) == FAIL)
	{
		printf("err monitor create thread\n");
		exit(1);
	}
	philo->sema = sema;
	do_philosopher(philo);
	if (join_monitor_pthread(philo) == FAIL)
	{
		printf("err monitor join thread\n");
		exit(1);
	}
	exit(0);
}

sem_t	*my_sem_open(t_diningtable *table)
{
	sem_t	*sema;

	sema = sem_open("/sem", O_CREAT, 0600, table->philo_num);
	if (sema == (sem_t *)SEM_FAILED)
		return (NULL);
	return (sema);
}

void	philosopher(t_diningtable *table)
{
	int		i;
	int		j;
	int		status;
	sem_t	*sema;

	i = 0;
	j = 0;
	sema = my_sem_open(table);
	if (sema == NULL)
		return ;
	while (i < table->philo_num)
	{
		table->philo[i]->pid = fork();
		if (table->philo[i]->pid == 0)
			manage_philo_monitor(table->philo[i], sema);
		i++;
	}
	while (j < table->philo_num)
	{
		waitpid(table->philo[j]->pid, &status, 0);
		kill(table->philo[j]->pid, SIGKILL);
		j++;
	}
	sem_close(sema);
	sem_unlink("/sem");
}
