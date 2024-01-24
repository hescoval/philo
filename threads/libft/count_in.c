/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:43:34 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/12 14:43:40 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_in(char *str, char c)
{
	int	count;
	int	i;

	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}

	return (count);
}