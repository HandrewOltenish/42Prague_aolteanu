/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:33:21 by aolteanu          #+#    #+#             */
/*   Updated: 2024/05/12 18:47:09 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_exit_status(char	*str)
{
	write (2, str, ft_strlen(str));
	exit(2);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_transfer_bits(int signum)
{
	static int	bit = 7;
	static int	c = 0;

	if (signum == SIGUSR1)
		c += 1 << bit;
	if (signum == SIGUSR2)
		c += 0 << bit;
	if (signum == SIGQUIT)
	{
		bit = 7;
		c = 0;
		fflush(NULL);
		exit (0);
	}
	bit--;
	if (bit == -1)
	{
		write (1, &c, 1);
		bit = 7;
		c = 0;
	}
}

void	ft_exit(int signum)
{
	if (signum == SIGQUIT)
		fflush(NULL);
}

int	main(void)
{
	int	sender_pid;

	sender_pid = 0;
	if (sender_pid == 0)
	{
		sender_pid = getpid();
		write(1, "Process with pid ", 18);
		write(1, ft_itoa((int)sender_pid), ft_numlength((int)getpid()));
		write (1, " started.\n", 11);
		free(ft_itoa((int)sender_pid));
	}
	while (1)
	{
		signal(SIGUSR1, ft_transfer_bits);
		signal(SIGUSR2, ft_transfer_bits);
	}
	return (0);
}
