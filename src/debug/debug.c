#include <pthread.h>
#include <stdio.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"
#include "philo_debug.h"

void	print_argv(char *argv[])
{
	printf("number_of_philosophers:%s\n", argv[1]);
	printf("time_to_die:%s\n", argv[2]);
	printf("time_to_eat:%s\n", argv[3]);
	printf("time_to_sleep:%s\n", argv[4]);
}

void	print_philo(t_diningtable *table)
{
	int		i;
	int		philo_num;
	t_philo	**philo;

	i = 0;
	philo_num = table->philo_num;
	philo = table->philo;
	while (i < philo_num)
	{
		printf("philo_id:%d\n", philo[i]->philo_id);
		printf("thread_id:%d\n", (int)(philo[i]->thread_id));
		printf("die:%d\n", ((t_diningtable *)philo[i]->table)->die);
		printf("eat:%d\n", ((t_diningtable *)philo[i]->table)->eat);
		printf("sleep:%d\n", ((t_diningtable *)philo[i]->table)->sleep);
		i++;
	}
}

void	print_fork(t_diningtable *table)
{
	int		i;
	int		philo_num;
	t_fork	**fork;

	i = 0;
	philo_num = table->philo_num;
	fork = table->fork;
	while (i < philo_num)
	{
		printf("fork_id:%d\n", fork[i]->fork_id);
		i++;
	}
}
