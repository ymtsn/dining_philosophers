#ifndef PHILO_PHILOSOPHER_BONUS_H
# define PHILO_PHILOSOPHER_BONUS_H
int		create_philo_pthread(t_diningtable *table);
int		join_philo_pthread(t_diningtable *table);
size_t	get_timestamp(void);
void	eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	think(t_philo *philo);
void	take_right_fork(t_philo *philo);
void	take_left_fork(t_philo *philo);
void	put_right_fork(t_philo *philo);
void	put_left_fork(t_philo *philo);
sem_t	*my_sem_open(t_diningtable *table);
void	philosopher(t_diningtable *table);
void	destroy_variables(t_diningtable *table);
#endif
