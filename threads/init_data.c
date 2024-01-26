/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:56:29 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/26 18:31:18 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phylo.h"

void	init_mutexes(t_general *info)
{
	int	i;

	i = -1;
	mutex_handle(&info->check_value, INIT);
	mutex_handle(&info->print, INIT);
	while(++i < info->total_p)
	{
		mutex_handle(&info->forks[i].mtx, INIT);
		info->forks[i].f_id = i;
	}
}

void	init_phylo(t_general *info)
{
	t_philo *philo;
	int	i;
	
	i = -1;
	while (++i < info->total_p)
	{
		philo = info->philos + i;
		mutex_handle(&philo->p_mtx, INIT);
		philo->p_id = i + 1;
		philo->info = info;
		if(philo->p_id % 2 == 0)
		{
			philo->f_one = &info->forks[i];
			philo->f_two = &info->forks[(i + 1) % info->total_p];
		}
		else
		{
			philo->f_one = &info->forks[(i + 1) % info->total_p];
			philo->f_two = &info->forks[i];
		}
	}
}

int	parse_args(t_general *info, char **args, int ac)
{
	info->total_p = ft_atoi(args[1]);
	info->death_time = ft_atoi(args[2]);
	info->eat_time = ft_atoi(args[3]);
	info->sleep_time = ft_atoi(args[4]);
	if(ac == 6)
		info->max_meals = ft_atoi(args[5]);
	else
		info->max_meals = -1;
	return 1;
}

char	*init_data(t_general *info, char **args, int ac)
{
	parse_args(info, args, ac);
	printf("Total Philosophers: %ld\n", info->total_p);
	if(info->max_meals == 0)
		return("Max Meals must be greater than 0");
	info->forks = ft_calloc(info->total_p, sizeof(t_fork));
	printf("Size of fork is%ld\n\n", sizeof(t_fork));
	if (info->forks == NULL)
		return("Malloc Error");
	info->philos = ft_calloc(info->total_p, sizeof(t_philo));
	printf("Size of philo is%ld\n\n", sizeof(t_philo));
	if (info->philos == NULL)
		return("Malloc Error");
	init_mutexes(info);
	init_phylo(info);
	return (NULL);
}
