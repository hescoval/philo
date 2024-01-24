/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:22:56 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/12 16:25:56 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcontains(char *s, char c)
{
		unsigned int	i;

		if (s == NULL)
			return (0);
		i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return (1);
			i++;
		}
		return (0);
}

char	*ft_strcpy_nl(char *dest, char *src, int nl_stop)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		if (nl_stop && src[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
		dest[i] = '\0';
		return (dest);
}

char	*ft_strjoin_special(char *s1, char *s2)
{
	char	*join;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (len + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && s2[j] != '\0')
		join[i++] = s2[j++];
	join[len] = '\0';
	if (s1 != NULL)	
		free(s1);
	return (join);
}