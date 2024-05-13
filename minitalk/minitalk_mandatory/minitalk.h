/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:30:36 by aolteanu          #+#    #+#             */
/*   Updated: 2024/05/13 12:49:25 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <aio.h>

void	ft_exit_status(char	*str);
void	ft_signal_handler(int pid, char *message);
void	ft_putnbr_fd(int n, int fd);
int		ft_numlength(int n);
int		ft_strlen(char	*str);
int		ft_send_byte(int pid, int byte);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
#endif
