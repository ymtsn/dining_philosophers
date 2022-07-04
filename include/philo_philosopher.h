#ifndef PHILO_PHILOSOPHERS_H
#define PHILO_PHILOSOPHERS_H
typedef struct s_philo{
	pthread_t	thread_id;
	int	philo_id;
	int	philo_num;
	int	die;
	int	eat;
	int	sleep;
	int	state;
	unsigned long birth_time;
	size_t	must_eat;
}t_philo;
t_philo **create_philo_variable(char *[]);
void	take_fork(t_philo *, t_fork **);
void	eat(t_philo *);
void	philo_sleep(t_philo *, t_fork **);
void	think(t_philo *);
void	philosopher(void *);
#endif
