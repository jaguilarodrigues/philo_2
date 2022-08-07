/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:35:42 by ebresser          #+#    #+#             */
/*   Updated: 2022/08/07 22:52:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_structs(t_status *status)
{
	free(status->philo);
	free(status->forks);
}

int	create_threads(t_status *status)
{
	int		i;

	i = 0;
	// TODO: testar tempos no inicializar ao ines de na criacao de threads
	status->philo_dead = FALSE;
	status->t0 = now_ms();
	//if (pthread_mutex_init(&status->n_thread_philo, NULL) != 0)
	//	return (FALSE);
	if (pthread_mutex_init(&status->printer, NULL) != 0 \
		|| pthread_mutex_init(&status->checker_mutex, NULL) != 0)
	{
		free_structs(status);
		return (FALSE);
	}
	while (i < status->input.num_philo)
	{
	//	pthread_mutex_lock(&status->n_thread_philo);
		status->n_thread = i;
	//	pthread_mutex_unlock(&status->n_thread_philo);
		if (pthread_create(&status->philo[i].thread,
				NULL, &routine, (void *) status) != 0)
			return (FALSE);
		i++;
		usleep(1000);
	}
	if (join_threads(status) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	join_threads(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->input.num_philo)
	{
		if (pthread_join(status->philo[i].thread, NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	destroy_mutex(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->input.num_philo)
	{
		pthread_mutex_destroy(&status->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&status->printer);
	return (TRUE);
}
