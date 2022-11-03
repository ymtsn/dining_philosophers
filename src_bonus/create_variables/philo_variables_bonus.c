/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_variables_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:26:50 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 19:55:59 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"
#include "philo_philosopher_bonus.h"

static int	init_philo_variables(t_diningtable *table)
{
	int	i;

	i = 0;
	while (i < table->total_philo)
	{
		table->philo[i] = malloc(sizeof(t_philo));
		ft_bzero(table->philo[i], sizeof(t_philo));
		if (table->philo[i] == NULL)
		{
			free_array(i, table->philo);
			return (FAIL);
		}
		if (pthread_mutex_init(&table->philo[i]->mutex, NULL) != 0)
		{
			free_array(i, table->philo);
			return (FAIL);
		}
		table->philo[i]->philo_id = i;
		table->philo[i]->table = table;
		table->philo[i]->must_eat = table->must_eat;
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
