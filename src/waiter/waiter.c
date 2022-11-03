/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:24:46 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/07/29 21:12:06 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_waiter.h"

void	waiter(t_philo *philo)
{
	if (philo->philo_id % 2 == 1)
		usleep(300);
}
