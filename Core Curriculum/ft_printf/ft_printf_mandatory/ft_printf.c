/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:12:40 by aolteanu          #+#    #+#             */
/*   Updated: 2024/05/16 17:59:27 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xxlen(char format, unsigned int number)
{
	int		i;
	char	*s;
	char	str[25];

	if (format == 'x')
		s = "0123456789abcdef";
	if (format == 'X')
		s = "0123456789ABCDEF";
	i = 0;
	if (number <= 0)
		return (write(1, "0", 1));
	while (number > 0)
	{
		str[i++] = s[(number % 16)];
		number /= 16;
	}
	str[i] = '\0';
	i--;
	while (i + 1)
		ft_printf_charlen(str[i--]);
	return (ft_printf_strsize(str));
}

int	ft_checkformat(char format, va_list arg)
{
	if (format == 'c')
		return (ft_printf_charlen(va_arg(arg, int)));
	if (format == 's')
		return (ft_printf_strlen(va_arg(arg, char *)));
	if (format == 'p')
		return (ft_plen(va_arg(arg, void *)));
	if (format == 'd' || format == 'i')
		return (ft_dorilen(va_arg(arg, int)));
	if (format == 'u')
		return (ft_ulen(va_arg(arg, int)));
	if (format == 'x' || format == 'X')
		return (ft_xxlen(format, va_arg(arg, int)));
	if (format == '%')
		return (ft_printf_charlen('%'));
	return (format);
}

int	ft_printf(const char	*format, ...)
{
	int		len;
	va_list	arg;

	len = 0;
	va_start(arg, format);
	if (!format)
		return (0);
	while (*format)
	{
		if (*format == '%')
			len += ft_checkformat(*(++format), arg);
		else
			len += write (1, format, 1);
		format++;
	}
	va_end(arg);
	return (len);
}
