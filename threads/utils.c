/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:38:48 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/26 19:02:50 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phylo.h"

bool	philo_dead(t_philo *philo)
{
	long long since_last;
	better_usleep(1);
	since_last = get_time(philo);
	if (since_last > philo->info->death_time)
	{
		set_bool(&philo->p_mtx, &philo->over, true);
		write_handle(DEAD, philo);
		return (true);
	}
	return (false);
}

void	better_usleep(long long time)
{
	long long	start;

	start = time_check();
	while (time_check() - start < time)
		usleep(250);
}

long long	get_time(t_philo *philo)
{
	long long	curr;
	long long	last_meal;
	curr = time_check();
	last_meal = get_long(&philo->p_mtx, &philo->last_meal);
	return (curr - last_meal);
}

long long	time_check()
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

bool	end_checks(t_philo *philo)
{
	if(get_bool(&philo->info->check_value, &philo->info->end))
		return (true);
	if(get_bool(&philo->p_mtx, &philo->over))
		return (true);
	
	return (false);
}