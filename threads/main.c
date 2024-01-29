/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:56:32 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/29 13:59:39 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phylo.h"

int main(int ac, char **av)
{
	t_general *info = NULL;
	char	*error = NULL;

	if (ac < 5 || ac > 6)
		return (p_error("Wrong Argument Count"));
	if(invalid_args(ac, av))
		return (p_error("Arguments not properly formatted"));
	info = ft_calloc(1, sizeof(t_general));
	if (!info)
		return (p_error("Malloc Error"));
	error = init_data(info, av, ac);
	if(error)
		return (p_error(error));
/* 	printf("Death Time: %lld\n", info->death_time);
	printf("Eat Time: %lld\n", info->eat_time);
	printf("Sleep Time: %lld\n\n", info->sleep_time);
	for(int i = 0; i < info->total_p; i++)
	{
		printf("Philosopher %ld\n", info->philos[i].p_id);
		printf("Fork 1: %d\n", info->philos[i].f_one->f_id);
		printf("Fork 2: %d\n", info->philos[i].f_two->f_id);
		printf("Max Meals: %lld\n", info->max_meals);
		printf("\n");
	} */
	eat_setup(info);
	clean(info);
}