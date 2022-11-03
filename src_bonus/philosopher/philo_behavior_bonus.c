/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:28:59 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 23:29:32 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"
#include "philo_philosopher_bonus.h"
#include "philo_waiter_bonus.h"

void	my_sleep(size_t sleep_time)
{
	size_t	start;

	start = get_timestamp();
	while (1)
	{
		usleep(50);
		if (get_timestamp() - start >= sleep_time)
			return ;
	}
}

void	eat(t_philo *philo)
{
	take_fork(philo);
	print_timestamp(philo, EAT_MSG, SET_TIME);
	my_sleep(((t_diningtable *)philo->table)->eat);
	put_fork(philo);
	if (philo->must_eat != GO_ON_EAT)
		philo->must_eat--;
}

void	philo_sleep(t_philo *philo)
{
	print_timestamp(philo, SLEEP_MSG, SET_TIME_NO);
	my_sleep(((t_diningtable *)philo->table)->sleep);
}

void	think(t_philo *philo)
{
	print_timestamp(philo, THINK_MSG, SET_TIME_NO);
}
