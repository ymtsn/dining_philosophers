/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killer_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:02:42 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 20:05:55 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_philosopher_bonus.h"
#include "philo_monitor_bonus.h"

void	do_child_killer(t_diningtable *table)
{
	int	i;

	i = 0;
	while (i < table->total_philo)
	{
		if (table->philo[i]->pid > 0)
			kill(table->philo[i]->pid, SIGKILL);
		i++;
	}
}

void	child_killer(t_diningtable *table)
{
	sem_wait(table->sema_killer);
	do_child_killer(table);
}

void	init_killer(t_diningtable *table)
{
	table->killer_pid = fork();
	if (table->killer_pid < 0)
	{
		do_child_killer(table);
		exit(1);
	}
	else if (table->killer_pid == 0)
	{
		child_killer(table);
		exit(0);
	}
}
