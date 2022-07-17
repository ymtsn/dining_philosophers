#ifndef PHILO_MONITOR_H
# define PHILO_MONITOR_H
void	monitor(void *arg);
int		create_monitor_pthread(t_diningtable *table);
int		join_monitor_pthread(t_diningtable *table);
#endif
