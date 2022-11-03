/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:27:38 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 21:18:32 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"
#include "philo_philosopher_bonus.h"
#include "philo_monitor_bonus.h"
#include "philo_waiter_bonus.h"
#include "philo_debug_bonus.h"

int	main(int argc,	char *argv[])
{
	t_diningtable	*table;

	table = create_variables(argc, argv);
	if (table == NULL)
		return (1);
	philosopher(table);
	destroy_variables(table);
	return (0);
}
