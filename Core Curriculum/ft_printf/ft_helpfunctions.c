/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:35:48 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/10 19:56:44 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_clen(int number)
{
	int i;
	return (i = 1);
}
// ft_strlen returns the length of a string
int ft_slen(char	*str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
// ft_plen returns the length of a pointer
int ft_plen(void *p)
{
	int i;

	i = 0;
	while ((char *)p++)
		i++;
	return (i);
}

int ft_dlen(int number)
{
	int i;

	i = 0;
	if (number == 0)
		return (i);
	while (number)
	{
		if (number < 0)
		{
			number = number * (-1);
			i++;
		}
		number = number / 10;
		i++;
	}
	return (i);
}

int ft_ulen(unsigned int number)
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
	return (i);
}

int ft_xlen(int number)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_Xlen(int number)
{
	int i;

	i = 0;
	while (number)
	{
		if (number < 0)
		{
			number = number * (-1);
			i++;
		}
		number = number / 10;
		i++;
	}
	return (i);
}