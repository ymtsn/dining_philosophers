#ifndef PHILO_STRUCT_H
#define PHILO_STRUCT_H
#define PHILO_DIED 1
typedef struct s_philo{
	pthread_t		thread_id;
	int				philo_id;
	int				philo_num;
	int				die;
	int				eat;
	int				sleep;
	int				state;
	unsigned long	timestamp;
	size_t			must_eat;
}t_philo;
typedef struct s_fork{
	int				fork_id;
	int				fork_num;
	int				use_philo_num;
	pthread_mutex_t	mutex;
} t_fork;
typedef struct s_diningtable{
	t_philo **philo;
	t_fork	**fork;
	int		target_philo_id;
} t_diningtable;
#endif
