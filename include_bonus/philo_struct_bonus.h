#ifndef PHILO_STRUCT_BONUS_H
#define PHILO_STRUCT_BONUS_H
#include <semaphore.h>
#define SUCCESS 0
#define FAIL 1
#define ERR 1
typedef struct s_philo{
	int				philo_id;
	int				state;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	int				stop_flg;
	size_t			timestamp;
	sem_t			*sema;
	pid_t			pid;
	pthread_t		monitor_tid;
	int				parmission;
}t_philo;
typedef struct s_diningtable{
	t_philo		**philo;
	int			die;
	int			eat;
	int			sleep;
	int			philo_num;
	int			must_eat;
	sem_t		*sema;
} t_diningtable;
#endif
