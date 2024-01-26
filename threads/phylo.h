/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phylo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:52:25 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/26 18:16:49 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHYLO_H
# define PHYLO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <ctype.h>
#include "libft/libft.h"
#include <errno.h>
#include <stdbool.h>

#define RST "\033[0m"	// Reset
#define RED "\033[0;31m"	// Red
#define G "\033[0;32m"	// Green
#define Y "\033[0;33m"	// Yellow
#define B "\033[0;34m"	// Blue
#define M "\033[0;35m"	// Magenta
#define C "\033[0;36m"	// Cyan
#define W "\033[0;37m"	// White

typedef pthread_mutex_t t_mtx;
typedef	struct s_general t_general;

typedef enum e_mutex_threads_ops
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_codes;

typedef enum e_write_perms
{
	NORMAL,
	MONITOR
}	t_perms;

typedef struct s_fork
{
	t_mtx mtx;
	int	f_id;
}	t_fork;

typedef struct s_philo
{
	long		p_id;
	long long	times_eaten;
	long long	last_meal;
	bool		over;
	t_fork		*f_one;
	t_fork		*f_two;
	t_mtx		p_mtx;
	pthread_t	thread;
	t_general	*info;
}	t_philo;

struct s_general
{
	long		total_p;
	long long	death_time;
	long long	eat_time;
	long long	sleep_time;
	long long	max_meals;
	long long	start_time;
	long long	full_philos;
	bool		ready;
	bool		end;
	t_fork		*forks;
	t_mtx		check_value;
	t_mtx		print;
	pthread_t	monitor;
	t_philo		*philos;
};

typedef enum e_actions
{
	FORK_ONE,
	FORK_TWO,
	EAT,
	SLEEP,
	THINK,
	DEAD,
	FULL
}	moves;

typedef enum e_errors
{
	ARG_COUNT,
	ARG_FORMAT,
	INIT_ERROR
}	error;

// Parser Utils
int			invalid_args(int ac, char **args);

// Error Handling
int			p_error(char *error);
void		*safe_malloc(size_t bytes);
void		handle_mutex_error(int status, t_codes code);
void		handle_thread_error(int	status,	t_codes code);
void		mutex_handle(t_mtx *mutex, t_codes code);
void		thread_handle(pthread_t *thread, void *(*fct)(void *),
			void *data, t_codes code);
void		threads_ready(t_general *info);

// Utils
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		ft_bzero(void *s, size_t n);
long long	ft_atol(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);

// Data Initialization
char		*init_data(t_general *info, char **args, int ac);
void		init_phylo(t_general *info);

// Prevent Racing
void		set_bool(t_mtx *mutex, bool *change, bool value);
bool		get_bool(t_mtx *mutex, bool *change);
void		set_long(t_mtx *mutex, long long *change, long long value);
long long	get_long(t_mtx *mutex, long long *change);
void		increment_long(t_mtx *mutex, long long *change);

// Rest
void		eat_setup(t_general *info);
long long	time_check();
long long	get_time(t_philo *philo);
void	write_handle(moves move, t_philo *philo);
bool		end_checks(t_philo *philo);
void		better_usleep(long long time);
bool	philo_dead(t_philo *philo);

#endif