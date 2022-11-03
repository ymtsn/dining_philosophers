/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:15:16 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 20:02:50 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_BONUS_H
# define PHILO_STRUCT_BONUS_H
typedef struct s_philo{
	int				philo_id;
	void			*table;
	int				must_eat;
	size_t			timestamp;
	sem_t			*sema_fork;
	sem_t			*sema_sync;
	sem_t			*sema_diecheck;
	sem_t			*sema_killer;
	pid_t			pid;
	pthread_t		monitor_tid;
	pthread_mutex_t	mutex;
}	t_philo;
typedef struct s_diningtable{
	t_philo			**philo;
	sem_t			*sema_fork;
	sem_t			*sema_sync;
	sem_t			*sema_diecheck;
	sem_t			*sema_killer;
	int				state;
	int				die;
	int				eat;
	int				sleep;
	int				total_philo;
	int				must_eat;
	pid_t			killer_pid;
}	t_diningtable;
#endif
