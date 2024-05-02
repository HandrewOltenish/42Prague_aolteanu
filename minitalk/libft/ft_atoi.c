/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:38:13 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/04 19:31:55 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//		Excerpt from Piscine C04 Ex03
// Write a function that converts the initial portion of the string
// pointed by str to its int representation
// • The string can start with an arbitray amount of white space
// (as determined by isspace(3))
// • The string can be followed by an arbitrary amount of +
//	and - signs, - sign will change
// the sign of the int returned based on the number of - is odd or even.
// • Finally the string can be followed by any numbers of the base 10.
// • Your function should read the string until the string stop following
// the rules and return the number found until now.
// • You should not take care of overflow or underflow.
// result can be undefined in that case.

//		The atoi() function converts the initial portion of the string
//	pointed to by nptr to int.  The behavior is the same as

//           strtol(nptr, NULL, 10);

//       except that atoi() does not detect errors.
//  Returns the converted value or 0 on error.

// strtol behavior:

//		The  strtol()  function  converts  the initial part of the
//	string in nptr to a long integer value according to the given
//  base, which must be between 2 and 36 inclusive, or be the special value 0.

//      The string may begin with an arbitrary amount of white space
//	(as determined by isspace(3)) followed by a single optional
//  '+'  or '-' sign.  If base is zero or 16, the string may
//	then include a "0x" or "0X" prefix, and the number will be read
//  in base 16; otherwise, a zero base is taken as 10 (decimal)
//	unless the next character is '0', in which case it is  taken
//  as 8 (octal).

//		The remainder of the string is converted to a long value
//	in the obvious manner, stopping at the first character which is
//  not a valid digit in the given base.  (In bases above 10, the
//	letter 'A' in either uppercase or lowercase represents 10,
//  'B' represents 11, and so forth, with 'Z' representing 35.)

//  If  endptr  is not NULL, strtol() stores the address of
//	the first invalid character in *endptr.  If there were no digits
//  at all, strtol() stores the original value of nptr in *endptr
//	(and returns 0).  In particular, if *nptr is not '\0'  but
//  **endptr is '\0' on return, the entire string is valid.

// #include <stdlib.h>
// #include <stdio.h>

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int		number;
	short	sign;

	number = 0;
	sign = 1;
	if (nptr == NULL)
		return (0);
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if ((*nptr++) == '-')
			sign = -1;
	while ('0' <= *nptr && *nptr <= '9')
		number = (number * 10) + ((*nptr++) - '0');
	return (number * sign);
}

// int	main()
// {
// 	printf("Let's see what ATOI does:\n%i\n", atoi("  -+-123"));
// 	printf("Let's see what ATOI does:\n%i\n", ft_atoi("   -+-123"));
// 	return (0);
// }