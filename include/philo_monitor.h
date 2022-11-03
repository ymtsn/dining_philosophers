/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:12:37 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/07/23 11:29:34 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_MONITOR_H
# define PHILO_MONITOR_H
void	monitor(void *arg);
int		create_monitor_pthread(t_diningtable *table);
int		join_monitor_pthread(t_diningtable *table);
#endif
