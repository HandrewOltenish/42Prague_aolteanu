/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:33:21 by aolteanu          #+#    #+#             */
/*   Updated: 2024/05/02 16:20:00 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int ft_transfer_bits(int pid, int signum)
{
	static int	bit;
	static int	c;

	bit = 7;
	c = 0;
	if (signum == SIGUSR1)
		c += 1 << bit;
	if (signum == SIGUSR2)
		c += 0 << bit;
	bit--;
	if (bit == -1)
	{
		write (1, &c, 1);
		bit = 7;
		c = 0;
	}

}

int main(void)
{
	int pid;

	pid = getpid();
	ft_printf("Process with PID [%i] started", pid);
	while (1)
	{
		if (!(signal(SIGUSR1, ft_transfer_bits)
			|| signal(SIGUSR2, ft_transfer_bits)))
					ft_exit_status("Error receiving signal.");
	}
	return (0);
}