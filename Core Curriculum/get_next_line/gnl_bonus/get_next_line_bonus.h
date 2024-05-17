/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:57:47 by aolteanu          #+#    #+#             */
/*   Updated: 2024/01/11 18:59:43 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_next(char *buffer);
char	*ft_line(char *buffer);
char	*ft_get(int fd, char *buffer);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_gnl_strchr(const char *s, int c);
void	ft_gnl_bzero(void *s, size_t n);
void	*ft_gnl_calloc(size_t n, size_t size);
size_t	ft_gnl_strlen(const char *s);
#endif
