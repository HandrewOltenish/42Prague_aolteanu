/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mandatory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:35:48 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/23 16:32:36 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// -----------------------------LENTGTH FUNCTIONS-----------------------------
// ft_putchar writes the character c in the specified file descriptor fd
static int	ft_numlength(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = n * (-1);
		count++;
	}
	if (n == 0)
		return (count = 1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
// ------------------------ATOI------------------------
int ft_atoi(char	*s)
{
	int i;
	int sign;
	int number;

	sign = 1;
	i = 0;
	if (*s == '-')
		sign = -1;
	while (*s >= '0' && *s <= '9')
	{
		number = (number * 10) + (*s - '0');
		i++;
		s++;	
	}
	return (number);
}
// ------------------------ITOA------------------------
char	*ft_itoa(int n)
{
	char	*string;
	long	number;
	int		index;

	string = 0;
	number = n;
	index = ft_numlength(n) - 1;
	string = (char *)malloc(sizeof(char) * (ft_numlength(n) + 1));
	if (string == 0)
		return (NULL);
	if (n == -2147483648)
		number = 2147483648;
	else if (number < 0)
		number = number * (-1);
	string[ft_numlength(n)] = '\0';
	while (index >= 0)
	{
		string[index] = (number % 10) + '0';
		number = number / 10;
		index--;
	}
	if (n < 0)
		string[0] = '-';
	return (string);
}
// ------------------------ITOA------------------------
void ft_putchar(char c, int fd)
{
	write (1, &c, 1);
}
void	ft_putstr(char *s, int fd)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		write (fd, &s[index], 1);
		index++;
	}
}
// ft_ulen returns length of unsigned decimal
int ft_ulen(unsigned int number)
{
	int i;

	i = 0;
	if (number == 0)
		return (i);
	if (number < 10)
	{
		write (1, number + '0', 1);
		i++;
	}
	else
	{
		ft_ulen(number / 10);
		ft_ulen(number % 10);
	}
	return (i);
}
// ft_xlen returns length of number in base 16 lowercase

// ft_Xlen returns length of number in base 16 uppercase
int ft_xXlen(char format, int number)
{
	int 	i;
	int 	j;
	char	*s;
	char	*str;

	if (format == 'x')
		s = "0123456789abcdef";
	if (format == 'X')
		s = "0123456789ABCDEF";
	i = 0;
	if (number == 0)
		return (i++);
	while (number > 0)
	{
		str[i] = s[(number % 16) * 16];
		number /= 16;
		i++;
	}
	ft_putstr(ft_revstr(str), 1);
}
// ft_pcentlen returns lengrh of percent character (can be the same as ft_charlen)
int ft_pcentlen(int number)
{
	int i;

	i = 0;
	ft_putchar('%', 1);
	return (i++);
}
