#ifndef PHILO_MONITOR_H
#define PHILO_MONITOR_H
#define SUCCESS 0
#define FAIL 1
void	monitor(void *);
int		create_monitor_pthread(t_diningtable *);
int		join_monitor_pthread(t_diningtable *);
#endif
