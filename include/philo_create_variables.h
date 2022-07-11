#ifndef PHILO_CREATE_VARIABLES_H
#define PHILO_CREATE_VARIABLES_H
long	ft_atol(const char *);
void	ft_bzero(void *, size_t);
t_fork			**create_fork_variables(int);
t_philo			**create_philo_variables(t_diningtable *);
t_diningtable	*create_table_variables(int, char *[]);
void			free_array(int, int, void *);
#endif
