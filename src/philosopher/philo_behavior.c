/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:24:14 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/07/29 21:04:51 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_waiter.h"
#include "philo_philosopher.h"

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

int	eat(t_philo *philo)
{
	if (take_fork(philo) != SUCCESS)
		return (FAIL);
	if (print_timestamp(philo, EAT_MSG, SET_TIME) != SUCCESS)
		return (FAIL);
	my_sleep(((t_diningtable *)philo->table)->eat);
	put_fork(philo);
	if (philo->must_eat != GO_ON_EAT)
		philo->must_eat--;
	return (SUCCESS);
}

int	philo_sleep(t_philo *philo)
{
	if (print_timestamp(philo, SLEEP_MSG, SET_TIME_NO) != SUCCESS)
		return (FAIL);
	my_sleep(((t_diningtable *)philo->table)->sleep);
	return (SUCCESS);
}

int	think(t_philo *philo)
{
	if (print_timestamp(philo, THINK_MSG, SET_TIME_NO) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}
