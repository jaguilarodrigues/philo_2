/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:37:28 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 20:40:31 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

__uint64_t	now_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * (__uint64_t)1000 + time.tv_usec / (__uint64_t)1000);
}

long long int	duration_ms(long long int simul_start)
{
	return (now_ms() - simul_start);
}

void	wait_ms(long long int time)
{
	usleep(time * 1000);
}

long long	delta_time(long long time)
{
	if (time > 0)
		return (now_ms() - time);
	return (0);
}

void	exec_action(long long time)
{
	usleep(time * 1000);
}
