/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:43:57 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/08 21:14:35 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_putnbr_fd
// Prototype void ft_putnbr_fd(int n, int fd);
// Turn in files -
// Parameters n: The integer to output.
// fd: The file descriptor on which to write.
// Return value None
// External functs. write
// Description Outputs the integer ’n’ to the given file
// descriptor.

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		return ;
	}
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	return ;
}

// int main (void)
// {
// 	int n;
// 	int fd;

// 	n = 12345678;
// 	fd = open("/nfs/homes/aolteanu/"
// 	"Common Core/Libft/testfile.txt", O_WRONLY | O_APPEND);
// 	ft_putnbr_fd(n, fd);
// 	return (0);
// }