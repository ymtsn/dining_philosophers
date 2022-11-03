/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:23:50 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/03 19:40:59 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"
#include "philo_monitor.h"

static	int	do_monitoring(t_philo *philo)
{
	size_t			diff;
	t_diningtable	*table;

	if (philo->state == PHILO_FIN)
		return (PHILO_FIN);
	pthread_mutex_lock(&philo->philo_mutex);
	diff = get_timestamp() - philo->timestamp;
	if (diff >= (size_t)((t_diningtable *)philo->table)->die)
	{
		table = (t_diningtable *)philo->table;
		pthread_mutex_lock(&table->diecheck_mutex);
		pthread_mutex_unlock(&philo->philo_mutex);
		table->state = PHILO_DIED;
		printf("%lu %d %s\n", get_timestamp(), philo->philo_id + 1, DIE_MSG);
		pthread_mutex_unlock(&table->diecheck_mutex);
		return (PHILO_DIED);
	}
	pthread_mutex_unlock(&philo->philo_mutex);
	return (PHILO_ALIVE);
}

void	monitor(void *arg)
{
	int				i;
	int				result;
	int				continue_flg;
	t_diningtable	*table;

	table = (t_diningtable *)arg;
	while (1)
	{
		i = 0;
		continue_flg = STOP;
		while (i < table->total_philo)
		{
			usleep(300);
			result = do_monitoring(table->philo[i]);
			if (result == PHILO_DIED)
				return ;
			else if (result == PHILO_ALIVE)
				continue_flg = CONTINUE;
			i++;
		}
		if (continue_flg == STOP)
			return ;
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
