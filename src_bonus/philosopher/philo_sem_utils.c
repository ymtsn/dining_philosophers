/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sem_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:13:20 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 19:59:48 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_philosopher_bonus.h"

void	my_sem_unlink(void)
{
	sem_unlink(SEMA_FORK);
	sem_unlink(SEMA_SYNC);
	sem_unlink(SEMA_DIECHECK);
	sem_unlink(SEMA_KILLER);
}

void	my_sem_open(t_diningtable *table)
{
	my_sem_unlink();
	table->sema_fork = sem_open(SEMA_FORK, O_CREAT, 0600, table->total_philo);
	if (table->sema_fork == SEM_FAILED)
		exit(1);
	table->sema_sync = sem_open(SEMA_SYNC, O_CREAT, 0600, 0);
	if (table->sema_sync == SEM_FAILED)
		exit(1);
	table->sema_diecheck = sem_open(SEMA_DIECHECK, O_CREAT, 0600, 1);
	if (table->sema_sync == SEM_FAILED)
		exit(1);
	table->sema_killer = sem_open(SEMA_KILLER, O_CREAT, 0600, 0);
	if (table->sema_killer == SEM_FAILED)
		exit(1);
}

void	sync_philo(t_diningtable *table)
{
	int	i;

	i = 0;
	while (i < table->total_philo)
	{
		sem_post(table->sema_sync);
		i++;
	}
}

void	my_sem_close(void *arg, int type)
{
	if (type == PHILO_SEM)
	{
		sem_close(((t_philo *)arg)->sema_fork);
		sem_close(((t_philo *)arg)->sema_sync);
		sem_close(((t_philo *)arg)->sema_diecheck);
		sem_close(((t_philo *)arg)->sema_killer);
	}
	else
	{
		sem_close(((t_diningtable *)arg)->sema_fork);
		sem_close(((t_diningtable *)arg)->sema_sync);
		sem_close(((t_diningtable *)arg)->sema_diecheck);
		sem_close(((t_diningtable *)arg)->sema_killer);
	}
}

void	terminate_proc_sema(t_diningtable *table)
{
	kill(table->killer_pid, SIGKILL);
	my_sem_close(table, TABLE_SEM);
	my_sem_unlink();
}
