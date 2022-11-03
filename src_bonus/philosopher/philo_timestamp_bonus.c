/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_timestamp_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:53:59 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 20:34:26 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_philosopher_bonus.h"

size_t	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_timestamp(t_philo *philo, char *MSG, int set_flg)
{
	size_t	time;

	sem_wait(philo->sema_diecheck);
	time = get_timestamp();
	printf("%lu %d %s\n", time, philo->philo_id + 1, MSG);
	if (set_flg == SET_TIME)
	{
		pthread_mutex_lock(&philo->mutex);
		philo->timestamp = time;
		pthread_mutex_unlock(&philo->mutex);
	}
	sem_post(philo->sema_diecheck);
}
