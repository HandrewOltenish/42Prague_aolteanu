/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:29:04 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/23 16:32:40 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ft_zerolen returns length of number padded with n number of zeroes to the left
int ft_zerolen(int number, int atoi)
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
	while (atoi)
	{
		ft_putchar('0', 1);
		atoi--;
		i++;
	}
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
		i++;
	}
	return (i);
}
// ft_hashlen returns length of x or X addresses, precedented by 0x or 0X for values diffrent than zero
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

int ft_bonusformat(char	*format, va_list arg)
{
	if ((*format == '0' && *format++ == '-') ||
		(*format == '-' && *format++ == '0'))
	{
		write(1, "flag '0' is ignored when flag '-' is present", 45);
		return (1);        
	}
	if (*format == '0')
		return (ft_zerolen(arg, ft_atoi(arg)));
	if (*format == '-')
		return (ft_dashlen(arg, ft_atoi(arg)));
	if (*format == '#')
		return (ft_hashlen(va_arg(arg, int), format++));
	if (*format == ' ')
	{
		if (va_arg(arg, int) >= 0)
		{
			ft_putchar(' ', 1);
			return (ft_dorilen(va_arg(arg, int)));
		}
		else return (ft_dorilen(va_arg(arg, int)));
	}
}