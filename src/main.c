/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:38:09 by ebresser          #+#    #+#             */
/*   Updated: 2022/08/08 03:35:17 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_status	status;

	if (input_errors(argc, argv) == TRUE)
		return (1);
	set_input(argc, argv, &status);
	if (create_forks(&status) == FALSE)
		return (1);
	if (create_philos(&status) == FALSE)
		return (1);
	if (create_threads(&status) == FALSE)
		return (1);
	if (destroy_mutex(&status) == FALSE)
		return (1);
	return (0);
}
