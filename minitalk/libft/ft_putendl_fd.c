/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:06:30 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/04 22:31:14 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_putendl_fd
// Prototype void ft_putendl_fd(char *s, int fd);
// Turn in files -
// Parameters s: The string to output.
// fd: The file descriptor on which to write.
// Return value None
// External functs. write
// Description Outputs the string ’s’ to the given file descriptor
// followed by a newline.

#include "libft.h"
#include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	char	c;

	c = '\n';
	while (*s)
	{
		write(fd, &*s, 1);
		s++;
	}
	write (fd, &c, 1);
}

// int main(void)
// {
// 	char *s;
// 	int fd;

// 	s = "I always feel like\nSomebody's watching me~";
// 	fd = open("/nfs/homes/aolteanu/Common Core/Libft/testfile.txt",
//  O_WRONLY | O_APPEND);
// 	ft_putendl_fd(s, fd);
// 	return (0);
// }