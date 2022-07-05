#include <pthread.h>
#include <unistd.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"
#include "philo_monitor.h"
#define DIE_MSG "is died"
#define CONTINUE 0
#define STOP 1

static	void do_monitoring(t_diningtable *table)
{
	unsigned long	now;
	int				diff;
	t_philo			*philo;

	philo = table->philo[table->target_philo_id];
	if (philo->timestamp == 0 || philo->state == PHILO_DIED)
		return ;
	now = get_timestamp();
	diff = (int)(now - philo->timestamp);
	if (diff >= philo->die)
	{
		philo->state = PHILO_DIED;
		print_timestamp(philo, DIE_MSG);
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
			if (table->philo[i]->timestamp != 0 || table->philo[i]->state != PHILO_DIED)
			{
				table->target_philo_id = i;
				do_monitoring(table);
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

void	create_monitor_pthread(t_diningtable *table)
{
	pthread_t	thread_id;

	(void)pthread_create(&thread_id, NULL, (void *)monitor, table);
	(void)pthread_join(thread_id, NULL);
}
