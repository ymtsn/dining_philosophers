#ifndef PHILO_PHILOSOPHERS_H
#define PHILO_PHILOSOPHERS_H
#define FORK_MSG "has taken a fork"
#define EAT_MSG "is eating"
#define SLEEP_MSG "is sleeping"
#define THINK_MSG "is thinking"
void			create_philo_pthread(t_diningtable *);
void			join_philo_pthread(t_diningtable *);
unsigned long	get_timestamp(void);
void			print_timestamp(t_philo *, char *);
void			take_fork(t_philo *, t_fork **, int);
void			eat(t_philo *);
void			philo_sleep(t_philo *, t_fork **, int);
void			think(t_philo *);
void			philosopher(void *);
#endif
