#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"
#include "philo_waiter.h"

static void	test_and_serve_forks(t_philo *philo)
{
	t_fork	*right_fork;
	t_fork	*left_fork;

	right_fork = philo->right_fork;
	left_fork = philo->left_fork;
	if (philo->state == PHILO_EAT)
	{
		if ((right_fork->use == NO_USE && left_fork->use == NO_USE) \
			&& (right_fork->use_philo_id != philo->philo_id \
			&& left_fork->use_philo_id != philo->philo_id))
		{
			if (philo->parmission == CANNOT_EAT)
			{
				right_fork->use = IN_USE;
				left_fork->use = IN_USE;
				philo->right_fork->use_philo_id = philo->philo_id;
				philo->left_fork->use_philo_id = philo->philo_id;
				philo->parmission = CAN_EAT;
			}
		}
	}
}

void	do_waiter(void *arg)
{
	int				i;
	int				upper_array;
	t_diningtable	*table;
	int				continue_flg;

	table = (t_diningtable *)arg;
	i = 0;
	upper_array = table->philo_num;
	while (1)
	{
		continue_flg = STOP;
		while (i < upper_array)
		{
			test_and_serve_forks(table->philo[i]);
			if (table->philo[i]->stop_flg == 0)
				continue_flg = CONTINUE;
			i++;
		}
		if (continue_flg == STOP)
			return ;
		i = 0;
	}
}

int	create_waiter_pthread(t_diningtable *table)
{
	if (pthread_create(&table->waiter_tid, NULL, (void *)do_waiter, table) != 0)
		return (FAIL);
	return (SUCCESS);
}

int	join_waiter_pthread(t_diningtable *table)
{
	if (pthread_join(table->waiter_tid, NULL) != 0)
		return (FAIL);
	return (SUCCESS);
}
