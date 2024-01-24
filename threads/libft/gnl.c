/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:22:58 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/12 16:23:01 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fill(int fd, char *data)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (!ft_strcontains(data, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			if (data != NULL)
				free(data);
			return (NULL);
		}
			buffer[bytes_read] = '\0';	
			data = ft_strjoin_special(data, buffer);
	}
	free(buffer);
	return (data);
}

char		*ft_extract_line(char *data)
{
	char		*line;
	size_t		len;
	int			i;

	if (data[0] == '\0')	
		return (NULL);
	i = 0;
	while (data[i] != '\0' && data[i] != '\n')
		i++;
	len = i;
	if(data[i] == '\n')
		len++;
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	ft_strcpy_nl(line, data, 1);
	return (line);
}

char	*ft_update_data(char *old_data)
{
	char		*new_data;
	int			start;

	start = 0;
	while (old_data[start] != '\0' && old_data[start] != '\n')
		start++;
	if (old_data[start] == '\0')
	{
		free(old_data);
		return (NULL);
	}
	new_data = malloc(sizeof(char) * (ft_strlen(old_data + start) + 1));
	if (new_data == NULL)
		return (NULL);
	ft_strcpy_nl(new_data, old_data + start + 1, 0);
	free(old_data);
	return (new_data);
}

char	*get_next_line(int fd)
{ 
		char		*line;
		static char	*data;

		if (fd < 0 || BUFFER_SIZE <= 0)
				return (NULL);
		data = ft_fill(fd, data);
		if (data == NULL)
			return (NULL);
		line = ft_extract_line(data);
		data = ft_update_data(data);
		return (line);
}
