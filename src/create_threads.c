/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:35:42 by ebresser          #+#    #+#             */
/*   Updated: 2022/08/08 03:54:26 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		return (FALSE);
	while (i < status->input.num_philo)
	{
	//	pthread_mutex_lock(&status->n_thread_philo);
		
		// ft_putstr("n_thread\n");
		status->n_thread = i;
	//	pthread_mutex_unlock(&status->n_thread_philo);
		if (pthread_create(&status->philo[i].thread,
				NULL, &routine, (void *) status) != 0)
			return (FALSE);
		i++;
		if (i % 2 == 0)
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
