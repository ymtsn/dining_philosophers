/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_timestamp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:53:59 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 22:37:05 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_philosopher.h"

size_t	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	print_timestamp(t_philo *philo, char *MSG, int set_flg)
{
	size_t			time;
	t_diningtable	*table;

	table = (t_diningtable *)philo->table;
	pthread_mutex_lock(&table->diecheck_mutex);
	if (table->state == PHILO_DIED)
	{
		pthread_mutex_unlock(&table->diecheck_mutex);
		return (FAIL);
	}
	time = get_timestamp();
	printf("%lu %d %s\n", time, philo->philo_id + 1, MSG);
	pthread_mutex_unlock(&table->diecheck_mutex);
	if (set_flg == SET_TIME)
	{
		pthread_mutex_lock(&philo->philo_mutex);
		philo->timestamp = time;
		pthread_mutex_unlock(&philo->philo_mutex);
	}
	return (SUCCESS);
}
