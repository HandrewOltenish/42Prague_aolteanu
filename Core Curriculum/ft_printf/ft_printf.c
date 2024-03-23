/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:09:53 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/21 18:42:55 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Here are the requirements:
// • Don’t implement the buffer management of the original printf().
// • Your function has to handle the following conversions: cspdiuxX%
// • Your function will be compared against the original printf().
// • You must use the command ar to create your library.
// Using the libtool command is forbidden.
// • Your libftprintf.a has to be created at the root of your repository.
// 5
// ft_printf Because ft_putnbr() and ft_putstr() aren’t enough
// You have to implement the following conversions:
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.

// Bonus list:
// • Manage any combination of the following flags: ’-0.’ and the field minimum width
// under all conversions.
// -	Left-justify within the given field width; Right justification is the default (see width sub-specifier).
// -- My Notes: 0      The value should be zero padded.  For d, i, o, u, x, X, a,
//               A, e, E, f, F, g, and G conversions, the converted value
//               is padded on the left with zeros rather than blanks.  If
//               the 0 and - flags both appear, the 0 flag is ignored.  If
//               a precision is given with an integer conversion (d, i, o,
//               u, x, and X), the 0 flag is ignored.  For other
//               conversions, the behavior is undefined.
// • Manage all the following flags: ’# +’ (Yes, one of them is a space)
// -- My Notes: #      The value should be converted to an "alternate form".  For
//               o conversions, the first character of the output string is
//               made zero (by prefixing a 0 ifimproving programming logic.  By default, a sign is
//               used only for negative numbers.  A + overrides a space if
//               both are used.
// ' ' (space)	If no sign is going to be written, a blank space is inserted before the value.
#include "ft_printf.h"



int ft_checkformat(char format, va_list arg)
{
	int		i;

	i = 0;
	if (format == 'c')
		return (ft_charlen(va_arg(arg, int))); 
	if (format == 's')
		return (ft_strlen(va_arg(arg, char	*)));
	if (format == 'p')
		return (ft_plen(va_arg(arg, void *)));
   if (format == 'd' || format == 'i')
		return (ft_dorilen(va_arg(arg, int)));
	if (format == 'u')
		return (ft_ulen(va_arg(arg, unsigned int)));
	if (format == 'x' || format == 'X')
		return (ft_xXlen(va_arg(arg, int)));
	if (format == '%')
      return (ft_pcentlen(va_arg(arg, int)));
   // bonus
   if (format == '0' || format == '-' || format == ' ' || format == '.')
		return (ft_bonusformat(format, va_arg(arg, int)));
	return (0);
}

int ft_printf (const char *str, ...)
{
	const char *s;
	int i;

	va_list arg;
	va_start(arg, str);
	s = va_arg(arg, const char *);
	if (!s)
		return (0);
	while (s)
	{
		if (*s == '%')
			i++;
			if (ft_bonusformat(s++), arg)
				i = ft_bonusformat(i++);
			i = ft_checkformat(s[i], arg);
		i++;
	}
	return (0);
	int check = ft_printf("Integer %i", 1);
	int check_1 = printf("Integer %i", 1);
}