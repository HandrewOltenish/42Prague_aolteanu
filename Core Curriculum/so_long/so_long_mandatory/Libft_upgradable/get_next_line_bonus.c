/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:35:53 by aolteanu          #+#    #+#             */
/*   Updated: 2024/05/24 21:05:59 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// static char *buffer allows to update its value
// for every time the get_next_line() function is called
// char *line_read is where we store the string and
// return it later
// ft_get() gets the line, reads it, stores it for later
// ft_next() searches for next line
// ft_line() returns the current line read
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
	next_line = (char *)malloc((ft_gnl_strlen(buffer) - i + 1) * sizeof(char));
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

char	*ft_get(int fd, char *buffer)
{
	char	*get_buffer;
	int		bytes_read;

	get_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (get_buffer == 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, get_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(get_buffer);
			return (NULL);
		}
		get_buffer[bytes_read] = '\0';
		buffer = ft_gnl_strjoin(buffer, get_buffer);
		if (ft_gnl_strchr(buffer, '\n'))
			break ;
	}
	free (get_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1000];
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

// int main(void)
// {
// 	char	*gnl;
// 	size_t	i;
// 	int	fd;
// 	char	buf[50];

// 	fd = open("test.txt", O_RDONLY);
// 	gnl = get_next_line(fd);
// 	i = 0;
// 	while (read(fd, buf, BUFFER_SIZE))
// 	{
// 		printf("%s", gnl);
// 		i++;
// 	}
// 	return (0);
// }

// int	main()
// {
// 	char *line;
// 	int	i;
// 	int fd;

// 	fd = open("test.txt", O_RDONLY);
// 	i = 0;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("line %d: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	return (0);
// }
