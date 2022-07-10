#ifndef PHILO_WAITER_H
#define PHILO_WAITER_H
void	do_waiter(void *);
int		create_waiter_pthread(t_diningtable *);
int		join_waiter_pthread(t_diningtable *);
#endif
