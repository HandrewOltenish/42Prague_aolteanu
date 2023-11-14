/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UNFINISHED_ft_putchar_fd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:28:25 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/14 20:46:45 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_putchar_fd
// Prototype void ft_putchar_fd(char c, int fd);
// Turn in files -
// Parameters c: The character to output.
// fd: The file descriptor on which to write.
// Return value None
// External functs. write
// Description Outputs the character ’c’ to the given file
// descriptor.

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	char	c;
// 	int		fd;
//
// 	c = 'c';
// 	fd = open("/nfs/homes/aolteanu/Common Core/Libft/testfile.txt", O_WRONLY | O_APPEND);
// 	ft_putchar_fd('c', fd);
// 	return (0);
// }
