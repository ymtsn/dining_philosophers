#ifndef PHILO_WAITER_BONUS_H
# define PHILO_WAITER_BONUS_H
void	do_waiter(void *arg);
int		create_waiter_pthread(t_diningtable *table);
int		join_waiter_pthread(t_diningtable *table);
#endif
