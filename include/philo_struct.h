/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:51:01 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 19:45:37 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H
typedef struct s_fork{
	int				fork_id;
	pthread_mutex_t	fork_mutex;
}	t_fork;
typedef struct s_philo{
	pthread_t		thread_id;
	int				philo_id;
	void			*table;
	int				state;
	int				must_eat;
	size_t			timestamp;
	t_fork			*right_fork;
	t_fork			*left_fork;
	pthread_mutex_t	philo_mutex;
}	t_philo;
typedef struct s_diningtable{
	t_philo			**philo;
	t_fork			**fork;
	int				state;
	int				die;
	int				eat;
	int				sleep;
	int				total_philo;
	int				must_eat;
	pthread_mutex_t	diecheck_mutex;
	pthread_t		monitor_tid;
}	t_diningtable;
#endif
