#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"
#include "philo_philosopher_bonus.h"
#include "philo_monitor_bonus.h"

static void	print_die_timestamp(t_philo *philo, char *MSG)
{
	printf("%lu %d %s\n", get_timestamp(), philo->philo_id + 1, MSG);
}

static	void do_monitoring(t_philo *philo)
{
	size_t	now;
	int		diff;

	if (philo->stop_flg == PHILO_DIED || philo->timestamp == 0)
		return ;
	now = get_timestamp();
	diff = (int)(now - philo->timestamp);
	if (diff >= ((t_diningtable*)philo->table)->die)
	{
		philo->stop_flg = PHILO_DIED;
		philo->must_eat = 0;
		print_die_timestamp(philo, DIE_MSG);
		pthread_detach(philo->thread_id);
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
			if (table->philo[i]->timestamp != 0 && table->philo[i]->stop_flg != PHILO_DIED)
				do_monitoring(table->philo[i]);
			if (table->philo[i]->stop_flg != PHILO_DIED)
				continue_flg = CONTINUE;
			i++;
		}
		if (continue_flg == STOP)
			return ;
		i = 0;
	}
}

int	create_monitor_pthread(t_diningtable *table)
{
	if (pthread_create(&table->monitor_tid, NULL, (void *)monitor, table) != 0)
		return (FAIL);
	return (SUCCESS);
}

int	join_monitor_pthread(t_diningtable *table)
{
	if (pthread_join(table->monitor_tid, NULL) != 0)
		return (FAIL);
	return (SUCCESS);
}
