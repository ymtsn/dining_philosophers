/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_process_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:30:08 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/03 00:34:36 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"
#include "philo_philosopher_bonus.h"
#include "philo_waiter_bonus.h"
#include "philo_monitor_bonus.h"

static void	do_philosopher(t_philo *philo)
{
	sem_wait(philo->sema_sync);
	waiter(philo);
	pthread_mutex_lock(&philo->mutex);
	philo->timestamp = get_timestamp();
	pthread_mutex_unlock(&philo->mutex);
	while (philo->must_eat)
	{
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
}

static void	init_philo_monitor(t_philo *philo)
{
	philo->sema_fork = ((t_diningtable *)philo->table)->sema_fork;
	philo->sema_sync = ((t_diningtable *)philo->table)->sema_sync;
	philo->sema_diecheck = ((t_diningtable *)philo->table)->sema_diecheck;
	philo->sema_killer = ((t_diningtable *)philo->table)->sema_killer;
	if (create_monitor_pthread(philo) == FAIL)
		exit(1);
	if (detach_monitor_pthread(philo) == FAIL)
		exit(1);
	do_philosopher(philo);
	exit(0);
}

static void	manage_init_philo_monitor(t_diningtable *table)
{
	int	i;

	i = 0;
	while (i < table->total_philo)
	{
		table->philo[i]->pid = fork();
		if (table->philo[i]->pid == 0)
			init_philo_monitor(table->philo[i]);
		if (table->philo[i]->pid < 0)
		{
			do_child_killer(table);
			terminate_proc_sema(table);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	wait_philo(t_diningtable *table)
{
	int		i;
	int		status;

	i = 0;
	while (i < table->total_philo)
	{
		if (waitpid(table->philo[i]->pid, &status, 0) < 0)
		{
			do_child_killer(table);
			terminate_proc_sema(table);
			exit(EXIT_FAILURE);
		}
		table->philo[i]->pid = 0;
		i++;
	}
}

void	philosopher(t_diningtable *table)
{
	my_sem_open(table);
	manage_init_philo_monitor(table);
	init_killer(table);
	sync_philo(table);
	wait_philo(table);
	terminate_proc_sema(table);
}
