/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_confirm_die_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 07:26:14 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/07/29 22:51:59 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_philosopher_bonus.h"

void	confirm_die(t_philo *philo)
{
	sem_wait(philo->sema_diecheck);
	sem_post(philo->sema_diecheck);
}
