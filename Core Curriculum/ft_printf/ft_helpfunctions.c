/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:35:48 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/12 23:46:29 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// -----------------------------LENTGTH FUNCTIONS-----------------------------
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
		write (1, '0', 1);
		return (i);
	}
	if (number < 0)
	{
		if (number == -2147483648)
			return(ft_strlen("-2147483648"));
		number = number * (-1);
		write (1, '-', 1);
		i++;
	}
	if (number < 10)
	{
		write (1, number + '0', 1);
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
int ft_xlen(int number)
{
	int i;
	char	*s;

	s = "abcdef";
	i = 0;
	if (number == 0)
	{
		write(1, '0', 1);
		return (i++);
	}
	return (i);
}
// ft_Xlen returns length of number in base 16 uppercase
int ft_Xlen(int number)
{
	int i;
	char	*s;

	s = (char *)number;
	i = 0;
	while (s[i])
		i++;
	return (i);
}
// ft_pcentlen returns lengrh of number in base 16 uppercase ( can be the same as ft_clen)
int ft_pcentlen(int number)
{
	int i;
	return (i = 1);
}
// ft_zerolen returns length of number padded with n number of zeroes to the left
int ft_zerolen(int number)
{
	int i;
	char	*s;

	s = (char *)number;
	i = 0;
	while (s[i])
		i++;
	return (i);
}
// ft_dashlen left-side justifies decimal with n number of spaces
int ft_dashlen(int number)
{
	int i;
	char	*s;

	s = (char *)number;
	i = 0;
	while (s[i])
		i++;
	return (i);
}
// ft_hashlen returns length of x or X addresses, precedented by 0x or 0X for values diffrent than zero
// ft_xlen & ft_Xlen can be used instad. Needs checking.
int ft_hashlen(int number)
{
	return (0);
}
// ft_spacelen returns length of value preceded by blank space if no sign is written, hence i++;
int ft_spacelen(int number)
{
	int i;

	i = 0;
	if (number == 0)
		return (i);
	while (number)
	{
		number = number / 10;
		i++;
	}
	i++;
	return (i);
}