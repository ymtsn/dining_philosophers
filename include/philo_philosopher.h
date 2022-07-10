#ifndef PHILO_PHILOSOPHERS_H
#define PHILO_PHILOSOPHERS_H
#define FORK_MSG "has taken a fork"
#define EAT_MSG "is eating"
#define SLEEP_MSG "is sleeping"
#define THINK_MSG "is thinking"
#define DIE_MSG "died"
#define PHILO_INIT -1
#define PHILO_EAT 0
#define PHILO_SLEEP 1
#define PHILO_THINK 2
#define PHILO_DIED 3
#define NO_USE -1
#define CANNOT_EAT 1
#define CAN_EAT 0
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
