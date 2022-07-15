#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"

static void	load_argv(int argc, char *argv[], t_diningtable *table)
{
	ft_bzero(table, sizeof(t_diningtable));
	table->philo_num = ft_atol(argv[PHILO_NUM_INDEX]);
	table->must_eat = 1;
	if (argc == 2)
		return ;
	table->die = ft_atol(argv[DIE_TIME_INDEX]);
	if (argc == 3)
		return ;
	table->eat = ft_atol(argv[EAT_TIME_INDEX]);
	if (argc == 4)
		return ;
	table->sleep = ft_atol(argv[SLEEP_TIME_INDEX]);
	if (argc == 5)
		return ;
	table->must_eat = ft_atol(argv[MUST_EAT_INDEX]);
}

t_diningtable	*create_table_variables(int argc, char *argv[])
{
	t_diningtable	*table;

	if (argc <= 1)
		return (NULL);
	table = malloc(sizeof(t_diningtable));
	if (table == NULL)
		return (NULL);
	load_argv(argc, argv, table);
	table->philo = create_philo_variables(table);
	if (table->philo == NULL)
	{
		free(table->sema);
		free(table);
		return (NULL);
	}
	return (table);
}
