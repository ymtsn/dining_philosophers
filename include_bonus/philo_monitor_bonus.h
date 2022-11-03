/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:14:59 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/07/25 23:16:50 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_MONITOR_BONUS_H
# define PHILO_MONITOR_BONUS_H
void	monitor(void *argv);
int		create_monitor_pthread(t_philo *philo);
int		detach_monitor_pthread(t_philo *philo);
void	init_killer(t_diningtable *table);
void	do_child_killer(t_diningtable *table);
#endif
