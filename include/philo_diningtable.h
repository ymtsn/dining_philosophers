#ifndef PHILO_DINING_H
#define PHILO_DINING_H
typedef struct s_diningtable{
	t_philo **philo;
	t_fork	**fork;
	int		philo_id;
} t_diningtable;
void	create_philo_pthread(t_diningtable *);
#endif
