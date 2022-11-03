/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:24:26 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/03 18:17:30 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"
#include "philo_philosopher_bonus.h"

void	take_fork(t_philo *philo)
{
	sem_wait(philo->sema_fork);
	sem_wait(philo->sema_fork);
	print_timestamp(philo, FORK_MSG, SET_TIME_NO);
	print_timestamp(philo, FORK_MSG, SET_TIME_NO);
}

void	put_fork(t_philo *philo)
{
	sem_post(philo->sema_fork);
	sem_post(philo->sema_fork);
}
