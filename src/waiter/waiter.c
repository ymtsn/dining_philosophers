#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"
#include "philo_waiter.h"
#define CONTINUE 0
#define STOP 1

void	do_waiter(void *arg)
{
	int				i;
	int				upper_array;
	t_diningtable	*table;
	int				continue_flg;

	table = (t_diningtable*)arg;
	i = 0;
	upper_array = table->philo_num;
	while(1)
	{
		continue_flg = STOP;
		while (i < upper_array)
		{
			if (table->philo[i]->state == PHILO_EAT)
				if (table->philo[i]->right_fork->use == NO_USE && table->philo[i]->left_fork->use == NO_USE)
					if (table->philo[i]->parmission == CANNOT_EAT)
					{
						table->philo[i]->right_fork->use = table->philo[i]->philo_id;
						table->philo[i]->left_fork->use = table->philo[i]->philo_id;
						table->philo[i]->parmission = CAN_EAT;
					}
			if (table->philo[i]->state != PHILO_DIED)
				continue_flg = CONTINUE;
			i++;
		}
		if (continue_flg == STOP)
			return ;
		i = 0;
	}
}

void	create_waiter_pthread(t_diningtable *table)
{
	(void)pthread_create(&table->waiter_tid, NULL, (void *)do_waiter, table);
}

void	join_waiter_pthread(t_diningtable *table)
{
	(void)pthread_join(table->waiter_tid, NULL);
}
