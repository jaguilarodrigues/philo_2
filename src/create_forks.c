/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:32:19 by ebresser          #+#    #+#             */
/*   Updated: 2022/08/08 03:36:32 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_forks(t_status *status)
{
	int	i;

	// ft_putstr("");
	// ft_putstr("");
	i = 0;
	while (i < status->input.num_philo)
	{
		if (pthread_mutex_init(&status->forks[i], NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
