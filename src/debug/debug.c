#include <pthread.h>
#include <stdio.h>
#include "philo_struct.h"
#include "philo_fork.h"
#include "philo_philosopher.h"
#include "philo_debug.h"

void	print_argv(char *argv[])
{
	printf("number_of_philosophers:%s\n", argv[1]);
	printf("time_to_die:%s\n", argv[2]);
	printf("time_to_eat:%s\n", argv[3]);
	printf("time_to_sleep:%s\n", argv[4]);
}

void	print_philo(t_philo **philo)
{
	int i;

	i = 0;
	while (i < philo[0]->philo_num)
	{
		printf("philo_id:%d\n", philo[i]->philo_id);
		printf("thread_id:%d\n", (int)(philo[i]->thread_id));
		printf("philo_num:%d\n", philo[i]->philo_num);
		printf("die:%d\n", philo[i]->die);
		printf("eat:%d\n", philo[i]->eat);
		printf("sleep:%d\n", philo[i]->sleep);
		i++;
	}
}

void	print_fork(t_fork **fork)
{
	int i;

	i = 0;
	while (i < fork[0]->fork_num)
	{
		printf("fork_id:%d\n", fork[i]->fork_id);
		printf("fork_num:%d\n", fork[i]->fork_num);
		printf("use_philo_num:%d\n", fork[i]->use_philo_num);
		i++;
	}
}
