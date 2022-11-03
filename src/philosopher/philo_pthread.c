/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:24:36 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 19:48:22 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"
#include "philo_waiter.h"

void	philosopher(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->philo_mutex);
	philo->timestamp = get_timestamp();
	pthread_mutex_unlock(&philo->philo_mutex);
	waiter(philo);
	while (philo->must_eat)
	{
		if (eat(philo) != SUCCESS)
			return ;
		if (philo_sleep(philo) != SUCCESS)
			return ;
		if (think(philo) != SUCCESS)
			return ;
	}
	pthread_mutex_lock(&philo->philo_mutex);
	philo->state = PHILO_FIN;
	pthread_mutex_unlock(&philo->philo_mutex);
}

int	create_philo_pthread(t_diningtable *table)
{
	int		i;
	t_philo	**philo;

	philo = table->philo;
	i = 0;
	while (i < table->total_philo)
	{
		if ((pthread_create(&philo[i]->thread_id, NULL, \
				(void *)philosopher, philo[i])) != 0)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	detach_philo_pthread(t_diningtable *table)
{
	int	i;

	i = 0;
	while (i < table->total_philo)
	{
		if (pthread_detach(table->philo[i]->thread_id) != 0)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}
