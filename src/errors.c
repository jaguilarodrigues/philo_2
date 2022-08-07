/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:46:01 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 20:38:39 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	error_msg(char *msg)
{
	printf("%s%s%s\n", "\033[1;33m", msg, "\033[0m");
}

static int	invalid_philo_number(int number)
{
	if (number > 200)
	{
		error_msg(MANY_PHILOS);
		return (TRUE);
	}
	if (number == 0)
	{
		error_msg(ZERO_PHILOS);
		return (TRUE);
	}
	if (number == 1)
	{
		printf("\033[0;33m");
		printf("The lone Philosopher starves to death...\n");
		printf("\033[0m");
		return (TRUE);
	}	
	return (FALSE);
}

static int	check_digits(char *current)
{
	int	i;

	i = 0;
	if (current[0] == '-' || current[0] == '+')
		i = 1;
	while (current[i])
	{
		if (ft_isdigit((int)current[i]) == 0)
		{
			error_msg(NOT_DIGIT);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

static int	check_limits(char *current)
{
	long long int	current_number;

	current_number = ft_atoll(current);
	if (current_number > INT_MAX)
	{
		error_msg(INPUT_TOO_HIGH);
		return (TRUE);
	}
	else if (current_number < 1)
	{
		error_msg(INPUT_TOO_LOW);
		return (TRUE);
	}
	return (FALSE);
}

int	input_errors(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5)
	{
		error_msg(FEW_ARGS);
		return (TRUE);
	}
	if (argc > 6)
	{
		error_msg(MANY_ARGS);
		return (TRUE);
	}	
	while (argv[i])
	{
		if (check_digits(argv[i]) == TRUE
			|| check_limits(argv[i]) == TRUE)
			return (TRUE);
		i++;
	}
	if (invalid_philo_number(ft_atoi(argv[1])) == TRUE)
		return (TRUE);
	return (FALSE);
}
