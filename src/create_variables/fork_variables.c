/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:15:47 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 20:03:01 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

static int	init_fork_variables(int total_philo, t_fork **fork)
{
	int	i;

	i = 0;
	while (i < total_philo)
	{
		fork[i] = malloc(sizeof(t_fork));
		if (fork[i] == NULL)
		{
			free_array(i, FREE_FORK, fork);
			return (FAIL);
		}
		if (pthread_mutex_init(&fork[i]->fork_mutex, NULL) != 0)
		{
			free_array(i, FREE_FORK, fork);
			return (FAIL);
		}
		fork[i]->fork_id = i;
		i++;
	}
	return (SUCCESS);
}

t_fork	**create_fork_variables(int total_philo)
{
	t_fork	**fork;

	fork = malloc(sizeof(t_fork *) * total_philo);
	if (fork == NULL)
		return (NULL);
	if (init_fork_variables(total_philo, fork) == FAIL)
		return (NULL);
	return (fork);
}
