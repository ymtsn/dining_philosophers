#include <pthread.h>
#include <stdio.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"
#include "philo_philosopher_bonus.h"
#include "philo_debug_bonus.h"

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
		printf("stop_flg:%d\n", philo[i]->stop_flg);
		i++;
	}
		printf("philo_num:%d\n", table->philo_num);
		printf("die:%d\n", table->die);
		printf("eat:%d\n", table->eat);
		printf("sleep:%d\n", table->sleep);
}
