#ifndef PHILO_CREATE_VARIABLES_BONUS_H
# define PHILO_CREATE_VARIABLES_BONUS_H
long			ft_atol(const char *str);
void			ft_bzero(void *arg, size_t size);
t_philo			**create_philo_variables(t_diningtable *table);
t_diningtable	*create_table_variables(int argc, char *argv[]);
void			free_array(int i, void *arg);
#endif
