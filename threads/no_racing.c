/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_racing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:28:07 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/26 16:15:29 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phylo.h"

void	increment_long(t_mtx *mutex, long long *change)
{
	mutex_handle(mutex, LOCK);
	*change += 1;
	mutex_handle(mutex, UNLOCK);
}

void	set_bool(t_mtx *mutex, bool *change, bool value)
{
	mutex_handle(mutex, LOCK);
	*change = value;
	mutex_handle(mutex, UNLOCK);
}

bool	get_bool(t_mtx *mutex, bool *check)
{
	bool ret;
	mutex_handle(mutex, LOCK);
	ret = *check;
	mutex_handle(mutex, UNLOCK);
	return(ret);
}

void	set_long(t_mtx *mutex, long long *change, long long change_to)
{
	mutex_handle(mutex, LOCK);
	*change = change_to;
	mutex_handle(mutex, UNLOCK);
}

long long get_long(t_mtx *mutex, long long *check)
{
	long ret;
	mutex_handle(mutex, LOCK);
	ret = *check;
	mutex_handle(mutex, UNLOCK);
	return(ret);
}