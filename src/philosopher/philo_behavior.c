#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_define.h"
#include "philo_struct.h"
#include "philo_create_variables.h"
#include "philo_philosopher.h"

size_t	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

static void	print_timestamp(t_philo *philo, char *MSG)
{
	if (philo->stop_flg == PHILO_DIED || philo->stop_flg == ERR)
		return ;
	printf("%lu %d %s\n", get_timestamp(), philo->philo_id + 1, MSG);
}

void	eat(t_philo *philo)
{
	philo->state = PHILO_EAT;
	philo->timestamp = get_timestamp();
	while (philo->parmission)
		usleep(100);
	take_right_fork(philo);
	print_timestamp(philo, FORK_MSG);
	take_left_fork(philo);
	print_timestamp(philo, FORK_MSG);
	print_timestamp(philo, EAT_MSG);
	philo->parmission = CANNOT_EAT;
	philo->right_fork->use = NO_USE;
	philo->left_fork->use = NO_USE;
	usleep(((t_diningtable *)philo->table)->eat * 1000);
	philo->timestamp = get_timestamp();
}

void	philo_sleep(t_philo *philo)
{
	philo->state = PHILO_SLEEP;
	put_right_fork(philo);
	put_left_fork(philo);
	print_timestamp(philo, SLEEP_MSG);
	usleep(((t_diningtable *)philo->table)->sleep * 1000);
}

void	think(t_philo *philo)
{
	philo->state = PHILO_THINK;
	print_timestamp(philo, THINK_MSG);
}
