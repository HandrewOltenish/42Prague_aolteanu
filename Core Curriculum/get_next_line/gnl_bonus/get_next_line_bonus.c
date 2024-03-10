/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:27:37 by aolteanu          #+#    #+#             */
/*   Updated: 2024/01/11 19:00:48 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next(char *buffer)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == 0)
	{
		free(buffer);
		return (NULL);
	}
	next_line = (char *)malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (next_line == 0)
		return (0);
	i++;
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	return (next_line);
}

char	*ft_line(char *buffer)
{
	char	*current_line;
	int		i;

	i = 0;
	if (buffer[i] == 0)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	current_line = (char *)malloc((i + 2) * sizeof(char));
	if (current_line == 0)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		current_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		current_line[i] = buffer[i];
		i++;
	}
	current_line[i] = '\0';
	return (current_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[];
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_get(fd, buffer[fd]);
	if (buffer[fd] == 0)
		return (NULL);
	current_line = ft_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (current_line);
}
