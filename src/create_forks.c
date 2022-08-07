/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:32:19 by ebresser          #+#    #+#             */
/*   Updated: 2022/08/07 22:11:09 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_forks(t_status *status)
{
	int	i;

	status->forks = malloc(sizeof(pthread_mutex_t) * \
		status->input.num_philo + 1);
	if (status->forks == NULL)
		return (FALSE);
	i = 0;
	while (i < status->input.num_philo)
	{
		if (pthread_mutex_init(&status->forks[i], NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
