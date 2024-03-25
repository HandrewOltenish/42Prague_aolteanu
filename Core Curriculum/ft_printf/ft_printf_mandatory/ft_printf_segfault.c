/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_segfault.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:12:40 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/25 19:54:18 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
int ft_putstr(char	*s)
{
	int i;
	int len;

	len = 0;
	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		len = len + ft_putchar(s[i]);
		i++;
	}
	return (len);
}

int ft_strsize(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_revstr(char *s, char *revstr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	while (i >= 0)
	{
		revstr[j] = s[i];
		i--;
		j++;
	}
	revstr[j] = '\0';
	return (revstr);
}

int ft_charlen(int number)
{
	char c;

	c = number;
	return(ft_putchar(c));
}


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

int ft_plen(void *p)
{
	size_t p1;
	int i;

	if (p == 0)
		return (ft_putstr("nil"));
	p1 = (size_t)p;
	i = ft_putstr("0x") + ft_pint(p1);
	return (i);
}

int ft_pint(size_t p)
{
	int i;
	char	*s;

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

int ft_dorilen(int number)
{
	int i;

	i = 0;
	if (number == 0)
		return (ft_charlen(i + '0'));
	if (number < 0)
	{
		if (number == -2147483648)
			return(ft_strlen("-2147483648"));
		number = number * (-1);
		i = i + ft_putchar('-');
	}
	if (number < 10)
	{
		i = i + ft_putchar(number + '0');
	}
	else
	{
		i = i + ft_dorilen(number / 10);
		i = i + ft_dorilen(number % 10);
	}
	return (i);
}

int ft_ulen(unsigned int number)
{
	int i;

	i = 0;
	if (number == 0)
		return (ft_putchar('0'));
	if (number < 10)
	{
		i = i + ft_putchar(number + '0');
	}
	else
	{
		i = i + ft_ulen(number / 10);
		i = i + ft_ulen(number % 10);
	}
	return (i);
}

int ft_xXlen(char format, int number)
{
	int 	i;
	char	*s;
	char	str[25];

	if (format == 'x')
		s = "0123456789abcdef";
	if (format == 'X')
		s = "0123456789ABCDEF";
	i = 0;
	if (number == 0)
		return (i++);
	while (number > 0)
	{
		str[i++] = s[(number % 16)];
		number /= 16;
	}
	str[i] = '\0';
	i--;
	while (i + 1)
		ft_putchar(str[i--]);
	return(ft_strsize(str));
}

int ft_checkformat(char format, va_list arg)
{
	
	if (format == 'c')
		return (ft_charlen(va_arg(arg, int)));
	if (format == 's')
		return (ft_strlen(va_arg(arg, char	*)));
	if (format == 'p')
		return (ft_plen(va_arg(arg, void *)));
	if (format == 'd' || format == 'i')
		return (ft_dorilen(va_arg(arg, int)));
	if (format == 'u')
		return (ft_ulen(va_arg(arg, int)));
	if (format == 'x' || format == 'X')
		return (ft_xXlen(format, va_arg(arg, int)));
	if (format == '%')
		return(ft_charlen('%'));
	return (format);
	
}

int ft_printf(const char	*format, ...)
{
	int i;
	int len;
	
	i = 0;
	len = 0;
	va_list arg;
	va_start(arg, format);
	if (!format)
		return (0);
	
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = len + ft_checkformat(format[++i], arg);
			i++;
		}
		len = len + ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}

int main()
{
	// char *p;
	int i;
	int j;
	// p = "Skibidi bop mm dada";
	// printf("Characters: %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n", 'a', 65, 'a', 65, 'a', 65, 'a', 65, 'a', 65, 'a', 65, 'a', 65);
	// ft_printf("Characters: %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n", 'a', 65, 'a', 65, 'a', 65, 'a', 65, 'a', 65, 'a', 65, 'a', 65);
	// printf ("%s\n%s\n", "A string", "");
	// ft_printf ("%s\n%s\n", "A string", "");
	// printf("Pointer address: %p\n", &p);
	// ft_printf("Pointer address: %p\n", &p);
	// printf("Decimal & Integer: %d %i\n", 12, -12);
	// ft_printf("Decimal & Integer: %d %i\n", 12, -12);
	// printf("Unsigned integer: %u %u\n", 0, 123456);
	// ft_printf("Unsigned integer: %u %u\n", 0, 123456);
	i = printf("x & X: %x %X\n", 12345, 12345);
	j = ft_printf("x & X: %x %X\n", 12345, 12345);
	printf("i = %i\nj = %d\n", i, j);
	ft_printf("i = %i\nj = %d\n", i, j);
	// printf("Percent sign: %%");
	// ft_printf("Percent sign: %%");
	// printf("Percent sign with error: %%", %);
	return (0);
}