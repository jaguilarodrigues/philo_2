/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:41:39 by ebresser          #+#    #+#             */
/*   Updated: 2022/08/07 22:35:15 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

/*
** Standard macros redefined (norme).
*/

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define LONG_MAX 9223372036854775807

/*
** bool
*/
# define TRUE 1
# define FALSE 0

/*
** Colors
*/
# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"
# define BOLD_ORANGE "\e[0;38;5;202m"

/*
** Error return macros.
*/

# define FEW_ARGS "ERROR: One or more arguments missing."
# define MANY_ARGS "ERROR: There are too many arguments."
# define INPUT_TOO_HIGH "ERROR: Input is above the int limit"
# define INPUT_TOO_LOW "ERROR: Input is below 1."
# define NOT_DIGIT "ERROR: Input should be an integer."
# define MANY_PHILOS "We don't need that many Ṕhilosophers. Put some back."
# define ZERO_PHILOS "If no one is there to eat the spaghetti, does it exist?"

/*
** Routines messages
*/
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died ☠️"
# define SATIATED "satiated ☠️"

/*
** Structures
*/
typedef struct s_input //populada OK
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_eat;
}					t_input;

typedef struct s_philo
{
	int				id;
	int				num_of_times_ate;
	long long		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				has_right_fork;
	int				has_left_fork;
	int				*death_ctrl;
	int				time_to_die;
	long long		*t0;
	pthread_t		thread;
	pthread_mutex_t	*printer;
	pthread_mutex_t	*checker_mutex;
}					t_philo;

typedef struct s_status
{
	int				n_thread;
	int				philo_dead;
	long long		t0;
	t_input			input;
	t_philo			*philo;
	pthread_mutex_t	checker_mutex;
	pthread_mutex_t	printer;
	pthread_mutex_t	*forks;
//	pthread_mutex_t	n_thread_philo;
}				t_status;

int				philo_eat(t_status *status, int i);
int				philo_sleep(t_status *status, int i);
int				philo_think(t_status *status, int i);
int				philo_is_dead(t_philo *philo);
int				drop_forks(t_status *status, int i);

int				create_forks(t_status *status);

int				create_philos(t_status *status);
void			fill_philo_struct(t_status *status, int i, int j);

int				create_threads(t_status *status);
int				join_threads(t_status *status);
int				destroy_mutex(t_status *status);

int				input_errors(int argc, char **argv);

void			free_structs(t_status *status);
void			*routine(void *args);
int				routine_execute(t_status *status, int i);
void			*routine_checker(void *args);
int				philo_print(t_status *status, int id, char *color, \
							char *action);

void			set_input(int argc, char **argv, t_status *status);

__uint64_t		now_ms(void);
long long int	duration_ms(long long int simul_start);
void			wait_ms(long long int time);
long long		delta_time(long long time);
void			exec_action(long long time);

int				ft_atoi(const char *str);
long long int	ft_atoll(char *str);
int				ft_isdigit(int c);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);

#endif