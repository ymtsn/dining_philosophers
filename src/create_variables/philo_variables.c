/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:23:02 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 19:49:42 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

static int	init_philo_variables(t_diningtable *table)
{
	int	i;

	i = 0;
	while (i < table->total_philo)
	{
		table->philo[i] = malloc(sizeof(t_philo));
		if (table->philo[i] == NULL)
		{
			free_array(i, FREE_PHILO, table->philo);
			return (FAIL);
		}
		ft_bzero(table->philo[i], sizeof(t_philo));
		if (pthread_mutex_init(&table->philo[i]->philo_mutex, NULL) != 0)
		{
			free_array(i, FREE_PHILO, table->philo);
			return (FAIL);
		}
		table->philo[i]->philo_id = i;
		table->philo[i]->table = table;
		table->philo[i]->must_eat = table->must_eat;
		table->philo[i]->right_fork = table->fork[i];
		table->philo[i]->left_fork = table->fork[(i + 1) % table->total_philo];
		i++;
	}
	return (SUCCESS);
}

t_philo	**create_philo_variables(t_diningtable *table)
{
	table->philo = malloc(sizeof(t_philo *) * table->total_philo);
	if (table->philo == NULL)
		return (NULL);
	if (init_philo_variables(table) == FAIL)
		return (NULL);
	return (table->philo);
}
