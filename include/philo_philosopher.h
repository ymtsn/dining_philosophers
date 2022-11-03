/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_philosopher.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:12:45 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/03 18:45:51 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_PHILOSOPHER_H
# define PHILO_PHILOSOPHER_H
int		create_philo_pthread(t_diningtable *table);
int		detach_philo_pthread(t_diningtable *table);
size_t	get_timestamp(void);
int		print_timestamp(t_philo *philo, char *MSG, int set_flg);
int		eat(t_philo *philo);
int		philo_sleep(t_philo *philo);
int		think(t_philo *philo);
int		take_fork(t_philo *philo);
void	put_fork(t_philo *philo);
void	philosopher(void *arg);
void	destroy_variables(t_diningtable *table);
int		confirm_die(t_philo *philo);
void	my_sleep(size_t sleep_time);
#endif
