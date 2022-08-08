/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:17:03 by ebresser          #+#    #+#             */
/*   Updated: 2022/08/08 01:48:04 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philos(t_status *status)
{
	int	i;
	int	j;

	status->philo = malloc(sizeof(t_philo) * (status->input.num_philo + 1));
	if (status->philo == NULL)
		return (FALSE);
	i = 0;
	j = 1;
	while (j < status->input.num_philo)
	{
		fill_philo_struct(status, i, j);
		i++;
		j++;
	}
	j = 0;
	fill_philo_struct(status, i, j);
	return (TRUE);
}

void	fill_philo_struct(t_status *status, int i, int j)
{
	status->philo[i].id = i + 1;
	status->philo[i].num_of_times_ate = 0;
	status->philo[i].last_meal = status->t0;
	status->philo[i].left_fork = &status->forks[i];
	status->philo[i].right_fork = &status->forks[j];
	status->philo[i].time_to_die = status->input.time_to_die;
	status->philo[i].t0 = &status->t0;
	status->philo[i].printer = &status->printer;
	status->philo[i].death_ctrl = &status->philo_dead;
	status->philo[i].checker_mutex = &status->checker_mutex;
	status->philo[i].has_right_fork = 0;
	status->philo[i].has_left_fork = 0;
	
	
}
