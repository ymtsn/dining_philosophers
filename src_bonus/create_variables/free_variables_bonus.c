/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:26:00 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 20:03:38 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"

void	free_array(int total_index, void *arg)
{
	int	i;

	i = 0;
	while (i <= total_index)
	{
		free(((t_philo **)arg)[i]);
		i++;
	}
	free(arg);
}

void	destroy_variables(t_diningtable *table)
{
	int	total_index;

	total_index = table->total_philo;
	total_index--;
	free_array(total_index, table->philo);
	free(table);
}
