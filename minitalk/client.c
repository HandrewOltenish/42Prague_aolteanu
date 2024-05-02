/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:40:24 by aolteanu          #+#    #+#             */
/*   Updated: 2024/05/02 16:23:46 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void ft_exit_status(char	*str)
{
	write (2, str, ft_strlen(str));
	exit(2);
}

int ft_send_byte(int pid, unsigned char	byte)
{
	int bit;
	int temp;

	bit = 7;
	temp = 0;
	while (bit != -1)
	{
		if ((byte & temp) && (kill(pid, SIGUSR1) == -1))
			ft_exit_status("Wrong PID");
		else if (!(byte & temp) && kill(pid, SIGUSR2) == -1)
				ft_exit_status("Wrong PID");
		if (temp += 1 << bit)
			kill(pid, SIGUSR1);
		else if (temp += 0 << bit)
			kill(pid, SIGUSR2);
		bit--;
		usleep(400);
	}
	return (0);
}

void ft_signal_handler(int pid, char *message)
{
	while (*message)
	{
		ft_send_byte(pid, *message);
		message++;
	}
	ft_send_byte (pid, *message);
}

int main(int parameters, char *strings[])
{
	if (parameters != 3)
	{
		ft_printf("Program needs three parameters");
		return (-1);
	}
	ft_signal_handler(ft_atoi(strings[1]), strings[2]);
	return (0);
}