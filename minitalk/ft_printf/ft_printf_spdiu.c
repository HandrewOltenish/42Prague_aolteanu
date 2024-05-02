/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spdiu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:02:11 by aolteanu          #+#    #+#             */
/*   Updated: 2024/04/30 15:32:45 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_mod(char	*str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write (1, "(null)", 6));
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_plen(void *p)
{
	size_t	p1;
	int		i;

	if (p == 0)
		return (ft_putstr("(nil)"));
	p1 = (size_t)p;
	i = ft_putstr("0x") + ft_pint(p1);
	return (i);
}

int	ft_pint(size_t p)
{
	int			i;
	char		*s;

	i = 0;
	s = "0123456789abcdef";
	if (p != 0)
	{
		if (p >= 16)
		{
			i += ft_pint(p / 16);
			p %= 16;
		}
		if (p < 16)
			i += write (1, &s[p], 1);
	}
	return (i);
}

int	ft_dorilen(int number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (ft_charlen(i + '0'));
	if (number < 0)
	{
		if (number == -2147483648)
			return (ft_strlen_mod("-2147483648"));
		number = number * (-1);
		i = i + ft_charlen('-');
	}
	if (number < 10)
	{
		i = i + ft_charlen(number + '0');
	}
	else
	{
		i = i + ft_dorilen(number / 10);
		i = i + ft_dorilen(number % 10);
	}
	return (i);
}

int	ft_ulen(unsigned int number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (ft_charlen('0'));
	if (number < 10)
	{
		i = i + ft_charlen(number + '0');
	}
	else
	{
		i = i + ft_ulen(number / 10);
		i = i + ft_ulen(number % 10);
	}
	return (i);
}
