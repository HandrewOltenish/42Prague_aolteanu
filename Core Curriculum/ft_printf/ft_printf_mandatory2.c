/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mandatory2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:42:22 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/23 16:32:34 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
