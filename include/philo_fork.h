#ifndef PHILO_FORK_H
#define PHILO_FORK_H
#define NO_USE -1
typedef struct s_fork{
	int				fork_id;
	int				fork_num;
	int				use_philo_num;
	pthread_mutex_t	mutex;
} t_fork;
t_fork **create_fork_variable(char *[]);
#endif
