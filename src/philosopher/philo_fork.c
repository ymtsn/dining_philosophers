/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_take_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:24:26 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/07/29 21:02:42 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->fork_mutex);
	if (print_timestamp(philo, FORK_MSG, get_timestamp()) != SUCCESS)
	{
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
		return (FAIL);
	}
	pthread_mutex_lock(&philo->left_fork->fork_mutex);
	if (print_timestamp(philo, FORK_MSG, get_timestamp()) != SUCCESS)
	{
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		return (FAIL);
	}
	return (SUCCESS);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->right_fork->fork_mutex);
	pthread_mutex_unlock(&philo->left_fork->fork_mutex);
}
