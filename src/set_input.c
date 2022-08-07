/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:38:10 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 20:24:03 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_input(int argc, char **argv, t_status *status)
{
	status->input.num_philo = ft_atoi(argv[1]);
	status->input.time_to_die = ft_atoi(argv[2]);
	status->input.time_to_eat = ft_atoi(argv[3]);
	status->input.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		status->input.num_of_times_eat = ft_atoi(argv[5]);
	else
		status->input.num_of_times_eat = -1;
}
