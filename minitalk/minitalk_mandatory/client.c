/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:40:24 by aolteanu          #+#    #+#             */
/*   Updated: 2024/05/09 18:58:11 by aolteanu         ###   ########.fr       */
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

int	ft_send_byte(int pid, int byte)
{
	int	bit;

	bit = 7;
	while (bit != -1)
	{
		if ((byte >> bit) & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		bit--;
		usleep(100);
	}
	return (0);
}

void	ft_signal_handler(int pid, char *message)
{
	while (*message)
	{
		ft_send_byte(pid, *message);
		message++;
	}
	ft_send_byte (pid, '\0');
	ft_send_byte (pid, '\n');
	exit (0);
}

int	main(int parameters, char *strings[])
{
	if (parameters != 3)
	{
		write(1, "Program needs three parameters", 31);
		return (-1);
	}
	while (*strings[2])
	{
		ft_signal_handler(ft_atoi(strings[1]), strings[2]);
	}
	return (0);
}
