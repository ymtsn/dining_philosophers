/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:12:25 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/07/29 12:18:40 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DEFINE_H
# define PHILO_DEFINE_H
# define FORK_MSG "has taken a fork"
# define EAT_MSG "is eating"
# define SLEEP_MSG "is sleeping"
# define THINK_MSG "is thinking"
# define DIE_MSG "died"
# define GO_ON_EAT -1
# define PHILO_INIT -1
# define PHILO_ALIVE 0
# define PHILO_EAT 1
# define PHILO_SLEEP 2
# define PHILO_THINK 3
# define PHILO_DIED 4
# define PHILO_FIN 5
# define NO_USE 0
# define IN_USE 1
# define CANNOT_EAT 1
# define CAN_EAT 0
# define FREE_PHILO 0
# define FREE_FORK 1
# define SUCCESS 0
# define FAIL 1
# define ERR 2
# define FORK_NUM_INDEX 1
# define TOTAL_PHILO_INDEX 1
# define DIE_TIME_INDEX 2
# define EAT_TIME_INDEX 3
# define SLEEP_TIME_INDEX 4
# define MUST_EAT_INDEX 5
# define CONTINUE 0
# define STOP 1
# define SET_TIME 0
# define SET_TIME_NO 1
#endif
