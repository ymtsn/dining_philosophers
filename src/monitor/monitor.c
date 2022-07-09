#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"
#include "philo_monitor.h"
#define CONTINUE 0
#define STOP 1

static void	print_timestamp(t_philo *philo, char *MSG)
{
	printf("%lu %d %s\n", get_timestamp(), philo->philo_id + 1, MSG);
}

static	void do_monitoring(t_philo *philo)
{
	size_t	now;
	int		diff;

	if (philo->timestamp == 0 || philo->state == PHILO_DIED)
		return ;
	now = get_timestamp();
	diff = (int)(now - philo->timestamp);
	if (diff >= ((t_diningtable*)philo->table)->die)
	{
		pthread_mutex_lock(&(philo->mutex));
		philo->state = PHILO_DIED;
		pthread_detach(philo->thread_id);
		print_timestamp(philo, DIE_MSG);
		if (philo->right_fork->use == philo->philo_id)
			put_right_fork(philo);
		if (philo->left_fork->use == philo->philo_id)
			put_left_fork(philo);
	}
}

void	monitor(void *arg)
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
			if (table->philo[i]->timestamp != 0 && table->philo[i]->state != PHILO_DIED)
				do_monitoring(table->philo[i]);
			if (table->philo[i]->state != PHILO_DIED)
				continue_flg = CONTINUE;
			i++;
		}
		if (continue_flg == STOP)
			return ;
		i = 0;
	}
}

void	create_monitor_pthread(t_diningtable *table)
{
	(void)pthread_create(&table->monitor_tid, NULL, (void *)monitor, table);
}

void	join_monitor_pthread(t_diningtable *table)
{
	(void)pthread_join(table->monitor_tid, NULL);
}
