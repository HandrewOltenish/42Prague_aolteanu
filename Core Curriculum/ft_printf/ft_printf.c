/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:09:53 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/09 16:49:44 by aolteanu         ###   ########.fr       */
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
//               made zero (by prefixing a 0 ifimproving programming logicn.  By default, a sign is
//               used only for negative numbers.  A + overrides a space if
//               both are used.

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

ft_checkformat(char format va_list arg)
{
	if (format == 'c')
		//return another function like putchar_len
	if (format == 's')
		//return function
	if (format == 'p')
	if (format == 'd')
	if (format == 'i')
	if (format == 'u')
	if (format == 'x')
	if (format == 'X')
	if (format == '#')
	if (format == ' ')
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
		if (s[i] == '%')
			i += ft_checkformat(s[i++])
		i++;
	}
	return (0);
	int check = ft_printf();
	int check_1 = printf();
}

// Linked list exercises
// ---------------------------------------------- RECAP OF LONKED LISTS ---------------------------------------------------------
//lstnew Allocates (with malloc(3)) and returns a new node.
// The member variable ’content’ is initialized with
// the value of the parameter ’content’. The variable
// ’next’ is initialized to NULL.

// Main Program for testing variadic functions
int main(void)
{
	printf("Here comes the Sum: %d\n", sum(10, 1));
	return (0);
}

Main program for printf testing
int main()
{
   printf ("Characters: %c %c \n", 'a', 65);
   printf ("Character error: %", "String");
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");
   return 0;
}