/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_philosopher_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:15:07 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/03 18:44:30 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_PHILOSOPHER_BONUS_H
# define PHILO_PHILOSOPHER_BONUS_H
size_t	get_timestamp(void);
void	print_timestamp(t_philo *philo, char *MSG, int set_flg);
void	eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	think(t_philo *philo);
void	take_fork(t_philo *philo);
void	put_fork(t_philo *philo);
void	philosopher(t_diningtable *table);
void	destroy_variables(t_diningtable *table);
void	confirm_die(t_philo *philo);
void	my_sem_open(t_diningtable *table);
void	my_sem_unlink(void);
void	my_sem_close(void *arg, int type);
void	sync_philo(t_diningtable *table);
void	terminate_proc_sema(t_diningtable *table);
void	my_sleep(size_t sleep_time);
#endif
