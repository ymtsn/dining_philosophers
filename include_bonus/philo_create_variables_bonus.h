/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_variables_bonus.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:14:32 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 21:08:23 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_CREATE_VARIABLES_BONUS_H
# define PHILO_CREATE_VARIABLES_BONUS_H
int				ft_atoi_plus(const char *str);
void			ft_bzero(void *arg, size_t size);
t_philo			**create_philo_variables(t_diningtable *table);
t_diningtable	*create_variables(int argc, char *argv[]);
void			free_array(int i, void *arg);
#endif
