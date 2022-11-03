/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:28:01 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/03 19:36:20 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"
#include "philo_philosopher_bonus.h"
#include "philo_monitor_bonus.h"

static	int	do_monitoring(t_philo *philo)
{
	size_t	diff;

	pthread_mutex_lock(&philo->mutex);
	if (philo->timestamp == 0)
	{
		pthread_mutex_unlock(&philo->mutex);
		return (PHILO_ALIVE);
	}
	diff = get_timestamp() - philo->timestamp;
	pthread_mutex_unlock(&philo->mutex);
	if (diff >= (size_t)((t_diningtable *)philo->table)->die)
	{
		sem_wait(philo->sema_diecheck);
		printf("%lu %d %s\n", get_timestamp(), philo->philo_id + 1, DIE_MSG);
		sem_post(philo->sema_killer);
		return (PHILO_DIED);
	}
	return (PHILO_ALIVE);
}

void	monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(700);
		if (do_monitoring(philo) == PHILO_DIED)
			return ;
	}
}

int	create_monitor_pthread(t_philo *philo)
{
	if (pthread_create(&philo->monitor_tid, NULL, (void *)monitor, philo) != 0)
		return (FAIL);
	return (SUCCESS);
}

int	detach_monitor_pthread(t_philo *philo)
{
	if (pthread_detach(philo->monitor_tid) != 0)
		return (FAIL);
	return (SUCCESS);
}
