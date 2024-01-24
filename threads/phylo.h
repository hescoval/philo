/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phylo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:52:25 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/24 16:55:43 by hescoval         ###   ########.fr       */
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
	DETACH
}	t_codes;

typedef struct s_fork
{
	t_mtx mtx;
	int	f_id;
}	t_fork;

typedef struct s_philo
{
	int p_id;
	int	times_eaten;
	long long	last_meal;
	bool	full;
	t_fork	*f_one;
	t_fork	*f_two;
	pthread_t	thread;
	t_general	*info;
}	t_philo;

struct s_general
{
	long	total_p;
	long	death_time;
	long	eat_time;
	long	sleep_time;
	long	max_meals;
	bool	ready;
	bool	end;
	t_fork	*forks;
	t_mtx	*print;
	t_philo	*philos;
};

typedef enum ERRORS
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

// Utils
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		ft_bzero(void *s, size_t n);
long long	ft_atol(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);

// Data Initialization
char	*init_data(t_general *info, char **args, int ac);
void	init_phylo(t_general *info);

#endif