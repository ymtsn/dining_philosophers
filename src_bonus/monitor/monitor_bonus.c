#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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

	if (philo->timestamp == 0)
		return ;
	now = get_timestamp();
	diff = (int)(now - philo->timestamp);
	if (diff >= ((t_diningtable *)(philo->table))->die)
	{
		philo->stop_flg = PHILO_DIED;
		philo->must_eat = 0;
		print_die_timestamp(philo, DIE_MSG);
	}
}

void	monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	while(1)
	{
		do_monitoring(philo);
		if (philo->stop_flg == PHILO_DIED)
			exit(0);
		usleep(100);
	}
}

int	create_monitor_pthread(t_philo *philo)
{
	if (pthread_create(&philo->monitor_tid, NULL, (void *)monitor, philo) != 0)
		return (FAIL);
	return (SUCCESS);
}

int	join_monitor_pthread(t_philo *philo)
{
	if (pthread_join(philo->monitor_tid, NULL) != 0)
		return (FAIL);
	return (SUCCESS);
}
