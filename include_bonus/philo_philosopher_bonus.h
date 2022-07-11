#ifndef PHILO_PHILOSOPHERS_BONUS_H
#define PHILO_PHILOSOPHERS_BONUS_H
int		create_philo_pthread(t_diningtable *);
int		join_philo_pthread(t_diningtable *);
size_t	get_timestamp(void);
void	eat(t_philo *);
void	philo_sleep(t_philo *);
void	think(t_philo *);
void	take_right_fork(t_philo *);
void	take_left_fork(t_philo *);
void	put_right_fork(t_philo *);
void	put_left_fork(t_philo *);
void	philosopher(void *);
void	destroy_variables(t_diningtable *);
#endif
