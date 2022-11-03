/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:16:00 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 20:03:15 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"

void	free_array(int total_index, int type, void *arg)
{
	int	i;

	i = 0;
	while (i <= total_index)
	{
		if (type == FREE_PHILO)
			free(((t_philo **)arg)[i]);
		else
			free(((t_fork **)arg)[i]);
		i++;
	}
	free(arg);
}

void	destroy_variables(t_diningtable *table)
{
	int	total_index;

	total_index = table->total_philo;
	total_index--;
	free_array(total_index, FREE_PHILO, table->philo);
	free_array(total_index, FREE_FORK, table->fork);
	free(table);
}
