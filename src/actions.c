/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:59:27 by ebresser          #+#    #+#             */
/*   Updated: 2022/08/08 03:10:58 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_status *status, int i)
{
	// ft_putstr("vai comer\n");
	if (status->philo_dead == TRUE || is_satiated(status, i) == TRUE)
	{
		// ft_putstr("não comeu\n");
		return (FALSE);
	}
	if (pthread_mutex_lock(status->philo[i].left_fork) != 0)
		return (FALSE);
	status->philo[i].has_left_fork = 1;
	if (philo_print(status, status->philo[i].id, B_BLUE, FORK) == FALSE)
		return (FALSE);
	if (pthread_mutex_lock(status->philo[i].right_fork) != 0)
		return (FALSE);
	status->philo[i].has_right_fork = 1;
	if (philo_print(status, status->philo[i].id, B_BLUE, FORK) == FALSE)
		return (FALSE);
	if (philo_print(status, status->philo[i].id, G_CYAN, EAT) == FALSE)
		return (FALSE);
	exec_action(status->input.time_to_eat);
	status->philo[i].last_meal = now_ms();
	drop_forks(status, i);
	return (TRUE);
}

int	philo_sleep(t_status *status, int i)
{
	if (status->philo_dead == TRUE || is_satiated(status, i) == TRUE)
		return (FALSE);
	if (philo_print(status, status->philo[i].id, BLUE, SLEEP) == FALSE)
		return (FALSE);
	exec_action(status->input.time_to_sleep);
	return (TRUE);
}

int	philo_think(t_status *status, int i)
{
	if (status->philo_dead == TRUE || is_satiated(status, i) == TRUE)
		return (FALSE);
	if (philo_print(status, status->philo[i].id, G_BLUE, THINK) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	drop_forks(t_status *status, int i)
{
	if (pthread_mutex_unlock(status->philo[i].left_fork))
		return (FALSE);
	status->philo[i].has_left_fork = 0;
	if (pthread_mutex_unlock(status->philo[i].right_fork))
		return (FALSE);
	status->philo[i].has_right_fork = 0;
	status->philo[i].num_of_times_ate++;
	return (TRUE);
}

int	philo_is_dead(t_philo *philo)
{
	int	time;
	long long now;

	time = delta_time(philo->last_meal);
	now = duration_ms(*(philo->t0));
	if (time > (philo->time_to_die) && (*(philo->death_ctrl) == FALSE))
	{
		*(philo->death_ctrl) = TRUE;
		pthread_mutex_lock(philo->printer);
		printf("%s%-10lld %-3d %-30s%s\n", PINK, now, philo->id, DIED, RESET);
		pthread_mutex_unlock(philo->printer);
		if (philo->has_left_fork == 1)
			pthread_mutex_unlock(philo->left_fork);
		if (philo->has_right_fork == 1)
			pthread_mutex_unlock(philo->right_fork);
		return (TRUE);
	}
	return (FALSE);
}
