/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:23:14 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 21:15:00 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"

static void	load_argv(int argc, char *argv[], t_diningtable *table)
{
	ft_bzero(table, sizeof(t_diningtable));
	if (argc == 1)
		return ;
	table->total_philo = ft_atoi_plus(argv[TOTAL_PHILO_INDEX]);
	table->must_eat = GO_ON_EAT;
	if (argc == 2)
		return ;
	table->die = ft_atoi_plus(argv[DIE_TIME_INDEX]);
	if (argc == 3)
		return ;
	table->eat = ft_atoi_plus(argv[EAT_TIME_INDEX]);
	if (argc == 4)
		return ;
	table->sleep = ft_atoi_plus(argv[SLEEP_TIME_INDEX]);
	if (argc == 5)
		return ;
	table->must_eat = ft_atoi_plus(argv[MUST_EAT_INDEX]);
}

static int	check_load_value(t_diningtable *table)
{
	if (table->eat == 0 || table->sleep == 0 || table->die == 0 \
		|| table->total_philo == 0 || table->must_eat == 0)
		return (ERR);
	return (SUCCESS);
}

static t_diningtable	*create_table_variables(int argc, char *argv[])
{
	t_diningtable	*table;

	table = malloc(sizeof(t_diningtable));
	if (table == NULL)
		return (NULL);
	load_argv(argc, argv, table);
	if (check_load_value(table) == ERR)
	{
		free(table);
		return (NULL);
	}
	if (pthread_mutex_init(&table->diecheck_mutex, NULL) != 0)
		return (NULL);
	return (table);
}

t_diningtable	*create_variables(int argc, char *argv[])
{
	t_diningtable	*table;

	table = create_table_variables(argc, argv);
	if (table == NULL)
		return (NULL);
	table->fork = create_fork_variables(table->total_philo);
	if (table->fork == NULL)
	{
		free(table);
		return (NULL);
	}
	table->philo = create_philo_variables(table);
	if (table->philo == NULL)
	{
		free_array(table->total_philo - 1, FREE_FORK, table->fork);
		free(table);
		return (NULL);
	}
	return (table);
}
