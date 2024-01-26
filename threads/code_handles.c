/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_handles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:56:36 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/26 18:52:12 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phylo.h"

void	mutex_handle(t_mtx *mutex, t_codes code)
{
	if (code == LOCK)
		pthread_mutex_lock(mutex);
	else if(code == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if(code == INIT)
		pthread_mutex_init(mutex, NULL);
	else if(code == DESTROY)
		pthread_mutex_destroy(mutex);
}

void	thread_handle(pthread_t *thread, void *(*fct)(void *),
		void *data, t_codes code)
{
	if (code == CREATE)
		pthread_create(thread, NULL, fct, data);
	else if (code == JOIN)
		pthread_join(*thread, NULL);
	else if (code == DETACH)
		pthread_detach(*thread);
}

void	write_handle(moves move, t_philo *philo)
{
	long long	current_time;
	long long	start_time;
	
	if(get_bool(&philo->info->check_value, &philo->info->end) && move != DEAD)
		return;
	start_time = get_long(&philo->info->check_value, &philo->info->start_time);
	mutex_handle(&philo->info->print, LOCK);
	current_time = time_check() - start_time;
	if(move == FORK_ONE)
		printf(G"%lld "RST C"%ld has taken a fork\n"RST, current_time, philo->p_id);
	else if(move == FORK_TWO)
		printf(G"%lld "RST C"%ld has taken a fork\n"RST, current_time, philo->p_id);
	else if(move == EAT)
		printf(G"%lld "RST RED"%ld is eating\n"RST, current_time, philo->p_id);
	else if(move == SLEEP)
		printf(G"%lld " C"%ld is sleeping\n"RST, current_time, philo->p_id);
	else if(move == THINK)
		printf(G"%lld " C"%ld is thinking\n"RST, current_time, philo->p_id);
	else if(move == DEAD)
		printf(G"%lld " C"%ld died\n"RST, current_time, philo->p_id);
	mutex_handle(&philo->info->print, UNLOCK);
}
