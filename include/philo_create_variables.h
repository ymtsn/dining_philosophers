/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_variables.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:40:19 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 20:02:18 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_CREATE_VARIABLES_H
# define PHILO_CREATE_VARIABLES_H
int				ft_atoi_plus(const char *str);
void			ft_bzero(void *arg, size_t size);
t_fork			**create_fork_variables(int total_philo);
t_philo			**create_philo_variables(t_diningtable *arg);
t_diningtable	*create_variables(int argc, char *argv[]);
void			free_array(int i, int type, void *arg);
#endif
