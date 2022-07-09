#include <pthread.h>
#include <stdlib.h>
#include <stddef.h>
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

t_waitor	*create_waitor_variable(void)
{
	t_waitor *waitor;

	waitor = malloc(sizeof(waitor));
	if (waitor == NULL)
		return (NULL);
	pthread_mutex_init(&waitor->mutex, NULL);
	return (waitor);
}

