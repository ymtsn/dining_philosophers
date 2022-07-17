#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H
# define SUCCESS 0
# define FAIL 1
# define ERR 1
typedef struct s_fork{
	int				fork_id;
	int				use;
	int				use_philo_id;
	pthread_mutex_t	mutex;
}	t_fork;
typedef struct s_philo{
	pthread_t		thread_id;
	int				philo_id;
	void			*table;
	int				state;
	int				must_eat;
	int				stop_flg;
	size_t			timestamp;
	t_fork			*right_fork;
	t_fork			*left_fork;
	int				parmission;
}	t_philo;
typedef struct s_diningtable{
	t_philo		**philo;
	t_fork		**fork;
	int			die;
	int			eat;
	int			sleep;
	int			philo_num;
	int			must_eat;
	pthread_t	waiter_tid;
	pthread_t	monitor_tid;
}	t_diningtable;
#endif
