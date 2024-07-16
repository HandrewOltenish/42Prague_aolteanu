/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:47:28 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/04 22:07:02 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_putstr_fd
// Prototype void ft_putstr_fd(char *s, int fd);
// Turn in files -
// Parameters s: The string to output.
// fd: The file descriptor on which to write.
// Return value None
// External functs. write
// Description Outputs the string ’s’ to the given file
// descriptor.

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		write (fd, &s[index], 1);
		index++;
	}
}

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = "/nfs/homes/aolteanu/Common Core/Libft/testfile.txt",
//  O_WRONLY | O_APPEND);
// 	s = "I'm inside your files";
// 	ft_putstr_fd(s, fd);
// }
