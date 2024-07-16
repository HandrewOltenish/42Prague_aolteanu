/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:39:00 by aolteanu          #+#    #+#             */
/*   Updated: 2024/05/24 21:05:29 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
// char *read_buffer is used to store all the concatenated lines up until now
// ssize_t bytes_read is the number of bytes read using the read function
// bytes_read = 1 initial value to initiate loop
// while bytes_read != 0 read through read_buffer and assign the bytes
// at index bytes_read to '\0'
// if bytes_read == -1 it means either EOF or error, so we free the buffer and
// return (0);
// concatenate strings buffer and read_buffer

void	ft_gnl_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_gnl_calloc(size_t n, size_t size)
{
	void	*p;

	p = malloc(n * size);
	if (p == 0)
		return (NULL);
	ft_gnl_bzero(p, n * size);
	return (p);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == 0)
		s1 = ft_gnl_calloc(1, 1);
	if (s2 == 0)
		return (NULL);
	str = (char *)malloc((ft_gnl)strlen(s1) + ft_gnl_strlen(s2) + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[ft_gnl_strlen(s1) + ft_gnl_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	int	i;

	if (s == 0)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if ((char) c == s[i])
		return ((char *) &s[i]);
	return (NULL);
}
