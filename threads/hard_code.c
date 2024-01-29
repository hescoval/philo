/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:18:43 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/29 13:57:53 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phylo.h"

void	fake_sim(t_philo *philo)
{
	write_handle(THINK, philo);
	mutex_handle(&philo->f_two->mtx, LOCK);
	write_handle(FORK_TWO, philo);
	better_usleep(philo->info->death_time);
	write_handle(DEAD, philo);
	mutex_handle(&philo->f_two->mtx, UNLOCK);
}

void	*one_philo(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	philo->info->start_time = time_check();
	fake_sim(philo);
	return (NULL);
}