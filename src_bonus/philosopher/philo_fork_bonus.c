#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_define_bonus.h"
#include "philo_struct_bonus.h"
#include "philo_create_variables_bonus.h"
#include "philo_philosopher_bonus.h"

void	take_right_fork(t_philo *philo)
{
	int	rc;

	rc = sem_wait(philo->sema);
	if (rc != 0)
		philo->stop_flg = ERR;
}

void	take_left_fork(t_philo *philo)
{
	int	rc;

	rc = sem_wait(philo->sema);
	if (rc != 0)
		philo->stop_flg = ERR;
}

void	put_right_fork(t_philo *philo)
{
	int	rc;

	rc = sem_post(philo->sema);
	if (rc != 0)
		philo->stop_flg = ERR;
}

void	put_left_fork(t_philo *philo)
{
	int	rc;

	rc = sem_post(philo->sema);
	if (rc != 0)
		philo->stop_flg = ERR;
}
