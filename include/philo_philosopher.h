#ifndef PHILO_PHILOSOPHERS_H
#define PHILO_PHILOSOPHERS_H
void			create_philo_pthread(t_diningtable *);
t_philo			**create_philo_variable(char *[]);
unsigned long	get_timestamp(void);
void			print_timestamp(t_philo *, char *);
void			take_fork(t_philo *, t_fork **);
void			eat(t_philo *);
void			philo_sleep(t_philo *, t_fork **);
void			think(t_philo *);
void			philosopher(void *);
#endif
