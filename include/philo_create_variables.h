#ifndef PHILO_CREATE_VARIABLES_H
# define PHILO_CREATE_VARIABLES_H
long			ft_atol(const char *str);
void			ft_bzero(void *arg, size_t size);
t_fork			**create_fork_variables(int total_philo);
t_philo			**create_philo_variables(t_diningtable *arg);
t_diningtable	*create_table_variables(int argc, char *argv[]);
void			free_array(int i, int type, void *arg);
#endif
