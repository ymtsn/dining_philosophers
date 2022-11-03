/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:23:30 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 19:15:32 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"
#include "philo_monitor.h"
#include "philo_waiter.h"
#include "philo_debug.h"

static int	manage_my_pthread(t_diningtable *table)
{
	if (create_philo_pthread(table) == FAIL)
		return (FAIL);
	if (create_monitor_pthread(table) == FAIL)
		return (FAIL);
	if (detach_philo_pthread(table) == FAIL)
		return (FAIL);
	if (join_monitor_pthread(table) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	main(int argc,	char *argv[])
{
	t_diningtable	*table;

	table = create_variables(argc, argv);
	if (table == NULL)
		return (1);
	if (manage_my_pthread(table) == FAIL)
	{
		destroy_variables(table);
		return (1);
	}
	destroy_variables(table);
	return (0);
}
