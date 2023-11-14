/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:17:30 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/14 21:16:31 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//		The memcmp() function compares the first n bytes (each interpreted as
//	unsigned char) of the memory areas s1 and s2.
//	The  memcmp() function returns an integer less than, equal to, or greater
//	than zero if the first n bytes of s1 is found, respectively, to be less
//	than, to match, or be greater than the first n bytes of s2.
//		For a nonzero return value, the sign is determined by the sign of
//	the difference between the first pair of bytes (interpreted as
//	unsigned char) that differ in s1 and s2.
//		If n is zero, the return value is zero.

// #include <string.h>
// #include <stdio.h>

#include "libft.h"

int	ft_memcmp(const void	*s1, const void	*s2, size_t	n)
{
	const unsigned char	*string1;
	const unsigned char	*string2;

	string1 = s1;
	string2 = s2;
	while (*string1 && *string2 && n > 0)
	{
		string1++;
		string2++;
		n--;
	}
	if (n == 0 || string1 == string2)
		return (0);
	else if (string1 > string2)
		return (42);
	else
		return (-42);
}

// int main()
// {
// 	char	*s1 = "Clue";
// 	char	*s2 = "Crypticsfh";
// 	size_t	n = 8;
// 	char	*s11 = "Clue";
// 	char	*s22 = "Crypthazic";
// 	size_t	n2 = 8;
// 	printf("Compare up to %zu bytes\n", n);
// 	printf("Which is greater?\n%s\nor\n%s?\n%i\n", s1, s2, memcmp(s1, s2, n));
// 	printf("Which is greater?\n%s\nor\n%s?\n%i\n", s11, s22, 
// 	ft_memcmp(s11, s22, n2));
// }
