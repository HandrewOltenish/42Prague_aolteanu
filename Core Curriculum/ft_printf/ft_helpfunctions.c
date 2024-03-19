/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:35:48 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/19 19:29:11 by aolteanu         ###   ########.fr       */
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

char *ft_revstr(char *s)
{
	char *revstr;
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		revstr[j] = s[i];
		i--;
		j++;
	}
	return (revstr);
}
// ft_charlen returns the length of a char
int ft_charlen(int number)
{
	int i;
	char c;

	c = number;
	write (1, &c, 1);
	return (i = 1);
}
// ft_strlen returns the length of a string
int ft_strlen(char	*str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}
// ft_plen returns the length of a pointer
int ft_plen(void *p)
{
	int i;

	i = 0;
	while ((char *)p++)
	{
		write (1, &p, 1);
		i++;
	}
	return (i);
}
// ft_dlen returns length of a base 10 integer
int ft_dorilen(int number)
{
	int i;

	i = 0;
	if (number == 0)
	{
		write (1, &i, 1);
		return (i++);
	}
	if (number < 0)
	{
		if (number == -2147483648)
			return(ft_strlen("-2147483648"));
		number = number * (-1);
		ft_putchar('-', 1);
		i++;
	}
	if (number < 10)
	{
		ft_putchar(number, 1);
		i++;
	}
	else
	{
		ft_dorilen(number / 10);
		ft_dorilen(number % 10);
	}
	return (i);
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
// ft_zerolen returns length of number padded with n number of zeroes to the left
int ft_zerolen(int number)
{
	int i;
	
	i = 0;
	
	return (i);
}
// ft_dashlen left-side justifies decimal with n number of spaces
int ft_dashlen(int number, int width)
{
	int 	i;
	char	*s;

	i = 0;
	s = ft_itoa(number);
	while (s[i])
	{
		ft_putchar(&s[i], 1);
		i++;
	}
	while (width)
	{
		ft_putchar(' ', 1);
		width--;
	}
	return (i);
}
// ft_hashlen returns length of x or X addresses, precedented by 0x or 0X for values diffrent than zero
// ft_xlen & ft_Xlen can be used instead. Needs checking.
int ft_hashlen(int number, int format)
{
	int i;

	i = 0;
	if (format == 'X')
	{
		ft_putstr("0X", 1);
		i = ft_Xlen(number) + 2;
	}
	if (format == 'x')
	{
		ft_putstr("0x", 1);
		i = ft_xlen(number) + 2;
	}
	return (i);
}
// ft_spacelen returns length of value preceded by blank space if no sign is written, hence i++;
int ft_spacelen(int number)
{
	int i;

	i = 0;
	if (number == 0)
		return (i++);
	while (number)
	{
		number = number / 10;
		i++;
	}
	i++;
	return (i);
}