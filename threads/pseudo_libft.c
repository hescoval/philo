/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:09:38 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/21 16:13:01 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phylo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	ret = malloc(nmemb * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	if (ret == NULL)
		return (NULL);
	return (ret);
}
int	ft_atoi(const char *nptr)
{
	int	ret;
	int	sign;
	int	i;

	sign = 1;
	ret = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret = ret * 10 + nptr[i] - 48;
		i++;
	}
	return (ret * sign);
}
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
void	ft_bzero(void *s, size_t n)
{
	char	*helper;

	helper = (char *) s;
	while (n)
	{
		*helper = 0;
		helper++;
		n--;
	}
}
long long	ft_atol(const char *nptr)
{
	long long ret;
	int	sign;
	int	i;

	sign = 1;
	ret = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret = ret * 10 + nptr[i] - 48;
		i++;
	}
	return (ret * sign);
}