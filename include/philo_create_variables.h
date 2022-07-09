#ifndef PHILO_CREATE_VARIABLES_H
#define PHILO_CREATE_VARIABLES_H
#define FREE_PHILO 1
#define FREE_FORK 2
t_fork			**create_fork_variables(int);
t_philo			**create_philo_variables(char *[], int, t_waitor *, t_fork **);
t_waitor		*create_waitor_variable(void);
t_diningtable	*create_variables(int, char *[]);
void			free_array(int, int, void *);
#endif
